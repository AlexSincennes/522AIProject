#pragma once

#include "ConvexPolygon.h"

#define EPSILON 0.0001f

namespace Pathfinding {

    class AStarNode
    {
    public:
        AStarNode(ConvexPolygon* poly);
        ~AStarNode();

        AStarNode* parent;
        ConvexPolygon* polygon;
        float f, g, h;

        bool AStarNode::operator==(const AStarNode &other) const {
            return  abs(f - other.f) < EPSILON  && 
                    abs(g - other.g) < EPSILON  &&
                    abs(h - other.h) < EPSILON  &&
                    (parent == other.parent)    &&
                    polygon == other.polygon;
        }
    };

}