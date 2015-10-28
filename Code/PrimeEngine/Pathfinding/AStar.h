#pragma once

#include "ConvexPolygon.h"
#include "AStarNode.h"

namespace Pathfinding {

    // return squared distance between 2 points
    inline float distance_squared(const Vector3* p, const Vector3* goal) {
        return  (goal->getX() - p->getX())*(goal->getX() - p->getX()) +
                (goal->getY() - p->getY())*(goal->getY() - p->getY()) +
                (goal->getZ() - p->getZ())*(goal->getZ() - p->getZ());
    }

    void a_star(const Vector3* goal, std::vector<AStarNode*> open_list, std::vector<AStarNode*> closed_list);

};