#include "AStarNode.h"

namespace Pathfinding {

    AStarNode::AStarNode(ConvexPolygon* poly)
    {
        parent = NULL;
        polygon = poly;
        f = 0;
        g = 0;
        h = 0;
    }


    AStarNode::~AStarNode()
    {
    }
}