#pragma once

#include "Polygon.h"
#include "ConvexPolygon.h"

namespace Pathfinding {

    class Navmesh
    {
    public:
        Navmesh();
        ~Navmesh();

        std::vector<ConvexPolygon*> mesh;

        // create mesh of convex polygons from non-convex polygon
        // Hertel and Mehlhorn partition
        bool Navmesh::GenerateNavmesh(Polygon *polygon);
    };

}