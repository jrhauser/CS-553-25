#include <stdio.h>
#include <stdlib.h>
#include "distance-vector.h"
#include "link-state.h"

int main(void) {
    // Create nodes and test algorithms here
    distNode nodes[5];
    for (int i = 0; i < MAX_TABLE_SIZE; i++) {
        nodes[i].router_id = i;
        pop_vector(&nodes[i]);  // Distance-Vector algorithm
    }
    
    linkStateNode link_nodes[5];
    for (int i = 0; i < MAX_TABLE_SIZE; i++) {
        link_nodes[i].router_id = i;
        calculate_shortest_paths(&link_nodes[i]);  // Link-State algorithm
    }

    return 0;
}