#pragma once

#include "ConvexPolygon.h"

class Navmesh
{
public:
    Navmesh();
    ~Navmesh();

    std::vector<ConvexPolygon> mesh;
};

