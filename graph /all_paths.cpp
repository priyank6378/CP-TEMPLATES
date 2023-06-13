#include <bits/stdc++.h>
using namespace std;

void find_all_path(vector<vector<int>> &g, int x, int y, vector<int> &visited, vector<int>& cur_path, vector<vector<int>>& paths){
    if (visited[x]) return ;
    visited[x] = 1;
    for (auto v: g[x]){
        if ( v == y){
            cur_path.push_back(v);
            paths.push_back(cur_path);
            find_all_path(g, v, y , visited, cur_path, paths);
            cur_path.pop_back();
            continue;
        }
        if (visited[v] == 0){
            cur_path.push_back(v);
            find_all_path(g, v, y , visited, cur_path, paths);
            cur_path.pop_back();
        }
    }
    visited[x] = 0;
}

