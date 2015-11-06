#pragma once

#include "PrimeEngine/Math/Vector3.h"

#include "Polygon.h"

#include <vector>

namespace Pathfinding {

    class ConvexPolygon
    {
    public:
        ConvexPolygon();
        ~ConvexPolygon();

        // vertices must be in CLOCKWISE order
        std::vector<Vector3*> vertices;
        std::vector<ConvexPolygon*> neighbours;

        bool ConvexPolygon::operator==(const ConvexPolygon &other) const {
            bool result = true;
            for each (Vector3* v in vertices)
            {
                std::vector<Vector3*>::const_iterator it = std::find(other.vertices.begin(), other.vertices.end(), v);
                if (it == other.vertices.end()) {
                    result = false;
                    break;
                }
            }
            return result;
        }

        bool ConvexPolygon::IsInside(const Vector3* pt);

        // returns center of polygon. Useful for A* heuristic algorithm
        const Vector3* getCentre() {
            return centre;
        }

        // TODO: this should only be temporary while polygons are hard-coded
        void setCentre(Vector3* v) {
            if (centre != NULL)
                delete centre;
            centre = new Vector3(*v);
        }

        void Clone(Polygon* p) {
            for each (Vector3* v in p->vertices)
            {
                Vector3* vn = new Vector3(*v);
                vertices.push_back(vn);
            }
            // call set centre
        }

    private:
        Vector3* centre;
    };

}