#ifndef _ASTAR_H_
#define _ASTAR_H_

#include "ConvexPolygon.h"

namespace AI {

    struct node {
        node* parent;
        ConvexPolygon* poly;
        float f, g, h;
    };

    // return squared distance between 2 points
    inline float distance_squared(Vector3 p, Vector3 goal) {
        return  (goal.getX() - p.getX())*(goal.getX() - p.getX()) + 
                (goal.getY() - p.getY())*(goal.getY() - p.getY()) + 
                (goal.getZ() - p.getZ())*(goal.getZ() - p.getZ()) ;
    }

    void a_star();

};

#endif