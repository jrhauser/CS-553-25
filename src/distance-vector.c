#include <adj.h>
#include <distance-node.h>
#include <stdio.h>


void pop_vector(distNode* node);

int main(void) {
    distNode nodes[5];
    for (int i = 0; i < MAX_TABLE_SIZE; i++) {
        nodes[i].router_id = i;
        pop_vector(&nodes[i]);
    }
}


void pop_vector(distNode* node){
    for (int i = 0; i < MAX_TABLE_SIZE; i++) {
        node->distance_vector[i] = adj[node->router_id][i];
    }
}
