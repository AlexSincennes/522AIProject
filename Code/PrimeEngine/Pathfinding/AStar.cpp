#include "AStar.h"

namespace AI {

    void a_star() {
        Vector3* goal = new Vector3(10, 10, 0);
        std::vector<Node*> open_list;
        std::vector<Node*> closed_list;

        while (open_list.size() > 0) {
            Node* smallest_f_node;
            float smallest_f = INT_MAX;
            for each (Node* n in open_list)
            {
                float nf = distance_squared(n->poly->getCentre(), goal);
                if (nf < smallest_f) {
                    smallest_f_node = n;
                    smallest_f = nf;
                }
            }

            for (int i = 0; i < open_list.size(); i++) {
                if (open_list[i] == smallest_f_node) {
                    open_list.erase(open_list.begin() + i);
                    break;
                }
            }

            for each (ConvexPolygon* neighbour in smallest_f_node->poly->neighbours) {
                Node* neighbour_node = new Node();
                neighbour_node->poly = neighbour;

                Vector3* smallest_f_node_pt = new Vector3(*(smallest_f_node->poly->getCentre()));

                neighbour_node->g = smallest_f_node->g + distance_squared(neighbour_node->poly->getCentre(), (const Vector3*) smallest_f_node_pt);
                neighbour_node->h = distance_squared(neighbour_node->poly->getCentre(), goal);
                neighbour_node->f = neighbour_node->g + neighbour_node->h;

                for each (Node* n in open_list)  {
                    if (neighbour_node->poly == n->poly) {
                        if (n->f < neighbour_node->f) {
                            delete neighbour_node;
                            delete smallest_f_node_pt;
                            continue;
                        }
                    }
                }
                for each (Node* n in closed_list)  {
                    if (neighbour_node->poly == n->poly) {
                        if (n->f < neighbour_node->f) {
                            delete neighbour_node;
                            delete smallest_f_node_pt;
                            continue;
                        }
                    }
                }
                open_list.push_back(neighbour_node);
            }
            closed_list.push_back(smallest_f_node);
        }

        // temp memory management

        for each (Node* n in open_list)  {
            delete n;
        }
        for each (Node* n in closed_list)  {
            delete n;
        }

        delete goal;
    }
};