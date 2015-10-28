#ifndef _ASTAR_H_
#define _ASTAR_H_

#include "ConvexPolygon.h"

namespace AI {

    struct Node {
        Node* parent;
        ConvexPolygon* poly;
        float f, g, h;
    };

    // return squared distance between 2 points
    inline float distance_squared(const Vector3* p, const Vector3* goal) {
        return  (goal->getX() - p->getX())*(goal->getX() - p->getX()) +
                (goal->getY() - p->getY())*(goal->getY() - p->getY()) +
                (goal->getZ() - p->getZ())*(goal->getZ() - p->getZ());
    }

    void a_star();

};

#endif