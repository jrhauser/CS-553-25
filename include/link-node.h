#ifndef LINK_STATE_H
#define LINK_STATE_H

// Definitions related to Link-State routing
typedef struct {
    int router_id;
    int shortest_paths[MAX_TABLE_SIZE];
} linkStateNode;

extern int adj[MAX_TABLE_SIZE][MAX_TABLE_SIZE];

void calculate_shortest_paths(linkStateNode* node);

#endif