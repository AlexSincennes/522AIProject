#pragma once

#include "PrimeEngine/Math/Vector3.h"

#include <vector>

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
    Vector3 getCenter() {
        return { 0, 0, 0 };
    }
};

