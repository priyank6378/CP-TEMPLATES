#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int>* g, int s, vector<bool> &visited){
    if (!visited[s]){
        // process node

        visited[s] = true;
        for (auto v: g[s]){
            dfs(g, v, visited);
        }
    }
}

int connected_components(vector<int> *g, vector<bool> &visited){
    int components = 0;
    for (int i=1; i<visited.size() ;i++){
        if (!visited[i]){
            dfs(g, i, visited);
            components++;
        }
    }
    return components;
} 

