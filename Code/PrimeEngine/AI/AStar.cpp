#include "AStar.h"

namespace AI {

    void a_star() {
        pt goal;
        std::vector<node*> open_list;
        std::vector<node*> closed_list;

        while (open_list.size() > 0) {
            node* smallest_f_node;
            float smallest_f = INT_MAX;
            for each (node* n in open_list)
            {
                float nf = f(n->p, goal);
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

            for each (poly* neighbour in smallest_f_node->p.neighbours) {
                node* neighbour_node = (node*)malloc(sizeof(node));
                neighbour_node->p = *neighbour;

                pt smallest_f_node_pt;
                smallest_f_node_pt.x = smallest_f_node->p.x;
                smallest_f_node_pt.y = smallest_f_node->p.y;
                smallest_f_node_pt.z = smallest_f_node->p.z;

                neighbour_node->g = smallest_f_node->g + f(neighbour_node->p, smallest_f_node_pt);
                neighbour_node->h = f(neighbour_node->p, goal);
                neighbour_node->f = neighbour_node->g + neighbour_node->h;

                for each (node* n in open_list)  {
                    if (poly_equals(neighbour_node->p, n->p)) {
                        if (n->f < neighbour_node->f) {
                            free(neighbour_node);
                            continue;
                        }
                    }
                }
                for each (node* n in closed_list)  {
                    if (poly_equals(neighbour_node->p, n->p)) {
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