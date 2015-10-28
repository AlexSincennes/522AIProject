#pragma once

#include "PrimeEngine/Math/Vector3.h"

#include <vector>

namespace Pathfinding {

    class ConvexPolygon
    {
    public:
        ConvexPolygon();
        ~ConvexPolygon();

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

    private:
        Vector3* centre;
    };

}