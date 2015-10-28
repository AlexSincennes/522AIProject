#pragma once

#include "ConvexPolygon.h"

namespace Pathfinding {

    class Navmesh
    {
    public:
        Navmesh();
        ~Navmesh();

        std::vector<ConvexPolygon*> mesh;
    };

}