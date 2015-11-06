#include "ConvexPolygon.h"

namespace Pathfinding {

    ConvexPolygon::ConvexPolygon()
    {
        centre = NULL;
    }


    ConvexPolygon::~ConvexPolygon()
    {
    }

    bool ConvexPolygon::IsInside(const Vector3* pt) {

        bool isInside = true;
        for (int i = 0; i < vertices.size(); i++) {
            Vector3* v1 = vertices.at(i);
            Vector3* v2 = vertices.at((i+1)%vertices.size());

            Vector3 edge = *v2 - *v1;
            Vector3 to_pt = *pt - *v1;

            isInside = to_pt.crossProduct(edge).getZ() > 0;
            if (!isInside)
                break;
        }

        return isInside;
    }

    // TODO: CALCULATE REAL CENTRE FUNCTION
    // also, getCentre should calculate centre when asked (lazy eval)
}
