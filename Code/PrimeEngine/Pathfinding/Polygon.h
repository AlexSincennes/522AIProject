#pragma once

#include "PrimeEngine/Math/Vector3.h"

#include <vector>

namespace Pathfinding {

    // consider keeping a next/prev relationship
    class Polygon
    {
    public:
        Polygon();
        ~Polygon();

        // vertices must be in CLOCKWISE order
        std::vector<Vector3*> vertices;

        bool Polygon::operator==(const Polygon &other) const {
            bool result = true;
            for each (Vector3* v in vertices)
            {
                std::vector<Vector3*>::const_iterator it = std::find(other.vertices.begin(), other.vertices.end(), v);
                if (it == other.vertices.end()) {
                    result = false;
                    break;
                }
            }
            return result;
        }
		void Polygon::CreatePolygonMesh();
    };

	
	

	
}