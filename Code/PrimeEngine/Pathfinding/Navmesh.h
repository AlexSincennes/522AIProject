#pragma once

#include "Polygon.h"
#include "ConvexPolygon.h"
#include "AStar.h"

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

        // I just do a star every time
        // also remember that we use X and Y and NOT Z (game Z is navmesh Y)
        // ALSO uses NAVMESH.MESH so make sure to put polygon mesh in there!
        void Navmesh::FindNextPosition(Vector3 &pos, Vector3 &goal, ConvexPolygon *next_poly);

    };

}