#include "Navmesh.h"


namespace Pathfinding {

    Navmesh::Navmesh()
    {
    }


    Navmesh::~Navmesh()
    {
    }

    // tests angle for > 180
    bool HasReflexAngle(Vector3* p1, Vector3* p2, Vector3* p3) {
        Vector3 v1 = *p3 - *p1;
        Vector3 v2 = *p2 - *p1;

        // use determinant to get sign
        float det = 0;
        det = v1.getX() * v2.getY() - v1.getY() * v2.getX();
        return det > 0;
    }

    // ear-clipping method
    bool TriangulateEarClip(Polygon *poly, std::vector<Polygon*> *triangles) {

        // check for trivial cases
        if (poly->vertices.size() < 3) return false;
        if (poly->vertices.size() == 3) {
            triangles->push_back(poly);
            return true;
        }

        // copy so as to not modify anything in the poly
        std::vector<Vector3*> vertices;
        for each (Vector3* v in poly->vertices)
        {
            Vector3* nv = new Vector3(*v);
        }
        
        // -3 since the last 3 form a triangle which must be convex
        for (int i = 0; i < vertices.size() - 3; i++) {

            Vector3* ear;
            float ear_angle = 0;
            //find the most extruded ear
            int ear_index;
            for (ear_index = 0; ear_index < vertices.size(); ear_index++) {

                // calc angle
                Vector3* p1 = vertices.at(ear_index);
                Vector3* p2 = vertices.at((ear_index - 1) % vertices.size());
                Vector3* p3 = vertices.at((ear_index + 1) % vertices.size());

                Vector3 v1 = *p3 - *p1;
                Vector3 v2 = *p2 - *p1;
                float dot = v1.getX() * v2.getX() + v1.getY() * v2.getY();
                float det = v1.getX() * v2.getY() - v1.getY() * v2.getX();
                float angle = atan2(det, dot);

                if (abs(ear_angle) < 0.001) {
                    ear = vertices.at(ear_index);
                    ear_angle = angle;
                }
                else {
                    if (angle > ear_angle) {
                        ear = vertices.at(ear_index);
                        ear_angle = angle;
                    }
                }
            }

            //if none found there is a problem: fail
            if (abs(ear_angle) < 0.001) { 
                for each (Vector3* v in vertices){
                    delete v;
                }
                return false;
            }

            // create ear triangle
            Vector3* p1 = vertices.at(ear_index);
            Vector3* p2 = vertices.at((ear_index - 1) % vertices.size());
            Vector3* p3 = vertices.at((ear_index + 1) % vertices.size());
            Polygon* triangle = new Polygon();
            triangle->vertices.push_back(p2);
            triangle->vertices.push_back(p1);
            triangle->vertices.push_back(p3);

            // add ear to triangles
            triangles->push_back(triangle);
            // clip ear
            vertices.erase(vertices.begin() + ear_index);
        }

        // add the vertices which haven't been clipped off
        for (int i = 0; i < vertices.size(); i++) {
            Vector3* p1 = vertices.at(i);
            Vector3* p2 = vertices.at((i - 1) % vertices.size());
            Vector3* p3 = vertices.at((i + 1) % vertices.size());
            Polygon* triangle = new Polygon();
            triangle->vertices.push_back(p2);
            triangle->vertices.push_back(p1);
            triangle->vertices.push_back(p3);

            triangles->push_back(triangle);
        }

        // clear mem
        for each (Vector3* v in vertices)
        {
            delete v;
        }

        return true;
    }


    bool Navmesh::GenerateNavmesh(Polygon *polygon) {

        // TODO: make adjustments to get it to be less copy-paste
        std::vector<Polygon*> triangles;
        std::vector<Polygon*>::iterator iter_outer, iter_inner;
        
        // trivial case: all angles on outside
        // of polygon are reflex angles
        // therefore the polygon is convex
        for (int i = 0; i<polygon->vertices.size(); i++) {   
            bool hasRA = HasReflexAngle(
                polygon->vertices.at((i - 1) % polygon->vertices.size()),
                polygon->vertices.at(i),
                polygon->vertices.at((i + 1) % polygon->vertices.size()));
            if (hasRA) {
                // if convex, then just convert polygon to convex type
                ConvexPolygon* convexpoly = new ConvexPolygon();
                convexpoly->Clone(polygon);
                mesh.push_back(convexpoly);
                return true;
            }
        }

       

        // triangulate polygon
        if (!TriangulateEarClip(polygon, &triangles)) 
            return false;

        // combine triangles if still form convex polygon
        for (iter_outer = triangles.begin(); iter_outer != triangles.end(); iter_outer++) {
            Polygon *cur = *iter_outer;
            Polygon *cur2;
            int i11, i12, i21, i22, i13, i23; // indices for relationships between vertices
            for (i11 = 0; i11 < cur->vertices.size(); i11++) {
                Vector3* diag1 = cur->vertices.at(i11);
                i12 = (i11 + 1) % (cur->vertices.size());
                Vector3* diag2 = cur->vertices.at(i12);

                // find diagonal
                bool isdiagonal = false;
                for (iter_inner = iter_outer; iter_inner != triangles.end(); iter_inner++) {
                    if (iter_outer == iter_inner) continue; // later try just add +1 to loop init
                    cur2 = *iter_inner;

                    for (i21 = 0; i21<cur2->vertices.size(); i21++) {
                        if ((diag2->getX() != cur2->vertices.at(i21)->getX()) || (diag2->getY() != cur2->vertices.at(i21)->getY())) 
                            continue;

                        i22 = (i21 + 1) % (cur2->vertices.size());
                        if ((diag1->getX() != cur2->vertices.at(i22)->getX()) || (diag1->getY() != cur2->vertices.at(i22)->getY())) 
                            continue;

                        isdiagonal = true;
                        break;
                    }
                    if (isdiagonal) 
                        break;
                }

                if (!isdiagonal)
                    continue;

                // all this code needs to be cleaned up

                Vector3* p2 = cur->vertices.at(i11);

                if (i11 == 0) 
                    i13 = cur->vertices.size() - 1;
                else 
                    i13 = i11 - 1;

                Vector3* p1 = cur->vertices.at(i13);

                if (i22 == (cur2->vertices.size() - 1)) 
                    i23 = 0;
                else 
                    i23 = i22 + 1;

                Vector3* p3 = cur2->vertices.at(i23);

                if (HasReflexAngle(p1, p2, p3)) // no reflex angle = convex
                    continue;

                p2 = cur->vertices.at(i12);

                if (i12 == (cur->vertices.size() - 1)) 
                    i13 = 0;
                else 
                    i13 = i12 + 1;

                p3 = cur->vertices.at(i13);

                if (i21 == 0) 
                    i23 = cur2->vertices.size() - 1;
                else 
                    i23 = i21 - 1;

                p1 = cur2->vertices.at(i23);

                if (HasReflexAngle(p1, p2, p3)) // no reflex angle = convex
                    continue;

                Polygon *newpoly = new Polygon();
                for (int j = i12; j != i11; j = (j + 1) % (cur->vertices.size())) {
                    newpoly->vertices.push_back(cur->vertices.at(j));
                }
                for (int j = i22; j != i21; j = (j + 1) % (cur2->vertices.size())) {
                    newpoly->vertices.push_back(cur->vertices.at(j));
                }

                triangles.erase(iter_inner);
                *iter_outer = newpoly;
                cur = *iter_outer;
                i11--;
            }
        }

        // create convex poly mesh and delete list of triangles (default "Polygon")
        for (iter_outer = triangles.begin(); iter_outer != triangles.end(); iter_outer++) {
            ConvexPolygon* p = new ConvexPolygon();
            p->Clone(*iter_outer);
            delete *iter_outer;
            mesh.push_back(p);
        }

        return true;
    }
}