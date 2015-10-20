#ifndef _ASTAR_H_
#define _ASTAR_H_

#include <vector>

namespace AI {

    // replace with proper poly struct/class later
    struct poly {
        int x, y, z;
        std::vector<poly*> neighbours;
    };

    struct pt {
        int x, y, z;
    };

    inline bool poly_equals(poly p1, poly p2) {
        float ep = 0.0001;
        return abs(p1.x - p2.x) < ep && abs(p1.y - p2.y) < ep && abs(p1.z - p2.z) < ep;
    };

    struct node {
        node *parent;
        poly p;
        float f, g, h;
    };

    // we're using square of distance
    inline float f(poly p, pt goal) {
        return (goal.x - p.x)*(goal.x - p.x) + (goal.y - p.y)*(goal.x - p.y) + (goal.z - p.z)*(goal.z - p.z);
    }

    void a_star();

};

#endif