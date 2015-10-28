#include "AStar.h"

namespace AI {

    void a_star() {
        Vector3 goal;
        std::vector<node*> open_list;
        std::vector<node*> closed_list;

        while (open_list.size() > 0) {
            node* smallest_f_node;  
            float smallest_f = INT_MAX;
            for each (node* n in open_list)
            {
                float nf = distance_squared(n->poly->getCenter(), goal);
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
                node* neighbour_node = (node*)malloc(sizeof(node));
                neighbour_node->poly = neighbour;

                Vector3 smallest_f_node_pt;
                smallest_f_node_pt.m_x = smallest_f_node->poly->getCenter().m_x;
                smallest_f_node_pt.m_y = smallest_f_node->poly->getCenter().m_y;
                smallest_f_node_pt.m_z = smallest_f_node->poly->getCenter().m_z;

                neighbour_node->g = smallest_f_node->g + distance_squared(neighbour_node->poly->getCenter(), smallest_f_node_pt);
                neighbour_node->h = distance_squared(neighbour_node->poly->getCenter(), goal);
                neighbour_node->f = neighbour_node->g + neighbour_node->h;

                for each (node* n in open_list)  {
                    if (neighbour_node->poly == n->poly) {
                        if (n->f < neighbour_node->f) {
                            free(neighbour_node);
                            continue;
                        }
                    }
                }
                for each (node* n in closed_list)  {
                    if (neighbour_node->poly == n->poly) {
                        if (n->f < neighbour_node->f) {
                            free(neighbour_node);
                            continue;
                        }
                    }
                }

                open_list.push_back(neighbour_node);
            }
            closed_list.push_back(smallest_f_node);
        }
    }
};