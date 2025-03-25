#include "link-state.h"
#include <limits.h>

// Function for Dijkstra's algorithm
void calculate_shortest_paths(linkStateNode* node){
    for (int i = 0; i < MAX_TABLE_SIZE; i++) {
        node->shortest_paths[i] = INT_MAX;
    }
    node->shortest_paths[node->router_id] = 0;

    int visited[MAX_TABLE_SIZE] = {0};
    visited[node->router_id] = 1;

    for (int count = 0; count < MAX_TABLE_SIZE - 1; count++) {
        int min_distance = INT_MAX;
        int next_node = -1;

        for (int i = 0; i < MAX_TABLE_SIZE; i++) {
            if (!visited[i] && node->shortest_paths[i] < min_distance) {
                min_distance = node->shortest_paths[i];
                next_node = i;
            }
        }

        if (next_node == -1) break;

        visited[next_node] = 1;

        for (int i = 0; i < MAX_TABLE_SIZE; i++) {
            if (!visited[i] && adj[next_node][i] != 0 && node->shortest_paths[next_node] + adj[next_node][i] < node->shortest_paths[i]) {
                node->shortest_paths[i] = node->shortest_paths[next_node] + adj[next_node][i];
            }
        }
    }
}