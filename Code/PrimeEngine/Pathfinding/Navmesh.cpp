#include "Navmesh.h"


namespace Pathfinding {

    Navmesh::Navmesh()
    {
    }


    Navmesh::~Navmesh()
    {
        for each (ConvexPolygon* p in mesh)
        {
            for each (Vector3* v in p->vertices)
            {
                if (v != NULL)
                    delete v;
            }
            if (p->getCentre() != NULL)
                delete p->getCentre();
            delete p;
        }
    }

    float Dist(Vector3* p1, Vector3* p2) {
        return sqrt((p1->getX() - p2->getX())*(p1->getX() - p2->getX()) + (p1->getY() - p2->getY())*(p1->getY() - p2->getY()));
    }

    float CalculateAngleDegrees(Vector3* center, Vector3* v1, Vector3* v2) {
        float pc1, pc2, p12;
        pc1 = Dist(center, v1);
        pc2 = Dist(center, v2);
        p12 = Dist(v1, v2);
        
        return acos((pc1*pc1 + pc2*pc2 - p12*p12) / (2 * pc1 * pc2)) * 180 / M_PI;
    }

    // tests angle for > 180 where first arg is the center of the angle
    bool HasReflexAngle(Vector3* center, Vector3* p1, Vector3* p2) {
        Vector3 v1 = *p2 - *center;
        Vector3 v2 = *p1 - *center;
        CalculateAngleDegrees(center, p1, p2);
        // use determinant to get sign
        float det = v1.getX() * v2.getY() - v1.getY() * v2.getX();
        return det > 0;
    }

    // ear-clipping method (with residual poly that is convex)
    bool TriangulateEarClip(Polygon *poly, std::vector<ConvexPolygon*> *triangles) {

        // check for trivial cases
        if (poly->vertices.size() < 3) return false;
        if (poly->vertices.size() == 3) {
            ConvexPolygon* p = new ConvexPolygon();
            p->Clone(poly);
            triangles->push_back(p);
            return true;
        }

        // copy so as to not modify anything in the poly
        std::vector<Vector3*> vertices;
        for each (Vector3* v in poly->vertices)
        {
            Vector3* nv = new Vector3(*v);
            vertices.push_back(nv);
        }
        
        // -3 since the last 3 form a triangle which must be convex
        for (int i = 0; i < vertices.size() - 3; i++) {

            int ear_index = 0;
            Vector3* ear;
            float ear_angle = 0;
            //find the most extruded ear
            for (int j = 0; j < vertices.size(); j++) {

                // calc angle
                Vector3* p1 = vertices.at(j);
                Vector3* p2 = vertices.at((j - 1 + vertices.size()) % vertices.size());
                Vector3* p3 = vertices.at((j + 1) % vertices.size());

                float angle = CalculateAngleDegrees(p1, p2, p3);

                if (angle > ear_angle) {
                    ear = vertices.at(j);
                    ear_angle = angle;
                    ear_index = j;
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
            Vector3* p2 = vertices.at((ear_index - 1 + vertices.size()) % vertices.size());
            Vector3* p3 = vertices.at((ear_index - 2 + vertices.size()) % vertices.size());
            ConvexPolygon* triangle = new ConvexPolygon();
            triangle->vertices.push_back(p2);
            triangle->vertices.push_back(p1);
            triangle->vertices.push_back(p3);

            // add ear to triangles
            triangles->push_back(triangle);
            // clip ear
            vertices.erase(vertices.begin() + ear_index - 1);
        }

        // add the vertices which haven't been clipped off

        ConvexPolygon* remainder = new ConvexPolygon();
        for (int i = 0; i < vertices.size(); i++) {
            Vector3* p1 = vertices.at(i);
            remainder->vertices.push_back(p1);
        }
        triangles->push_back(remainder);

        // TODO: create the neighbour relationship

        return true;
    }


    bool Navmesh::GenerateNavmesh(Polygon *polygon) {

        // TODO: make adjustments to get it to be less copy-paste
        std::vector<ConvexPolygon*> triangles;
        std::vector<ConvexPolygon*>::iterator iter_outer, iter_inner;
        
        // check every angle to see if it is a reflex angle (i.e. > 180)
        bool hasRA = false;
        for (int i = 0; i < polygon->vertices.size(); i++) {   
             hasRA = HasReflexAngle(
                polygon->vertices.at(i),
                polygon->vertices.at((i - 1 + polygon->vertices.size()) % polygon->vertices.size()),
                polygon->vertices.at((i + 1) % polygon->vertices.size()));
            if (hasRA) {
                break;
            }
        }

        // no reflex angles -> must be convex
        if (!hasRA) {
            ConvexPolygon* convexpoly = new ConvexPolygon();
            convexpoly->Clone(polygon);
            mesh.push_back(convexpoly);
            return true;
        }
       

        // triangulate polygon --> probably good enough for our purposes, we'll see
        if (!TriangulateEarClip(polygon, &triangles)) 
            return false;
        else {
            for each (ConvexPolygon* p in triangles)
            {
                mesh.push_back(p);

            }
            return true;
        }
            

        // IGNORE ALL OF THIS FOR NOW

        // combine triangles if still form convex polygon
        for (iter_outer = triangles.begin(); iter_outer != triangles.end(); iter_outer++) {
            ConvexPolygon *cur = *iter_outer;
            ConvexPolygon *cur2;
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

                ConvexPolygon *newpoly = new ConvexPolygon();
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
            ConvexPolygon* p = new ConvexPolygon(**iter_outer);
            delete *iter_outer;
            mesh.push_back(p);
        }

        return true;
    }
}