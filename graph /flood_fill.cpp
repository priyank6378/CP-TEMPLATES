#include <bits/stdc++.h>

using namespace std;

void flood_fill(vector<vector<int>> &v , int i , int j){
    if (i<0 or j<0 or i>=v.size() or j>=v[0].size() or v[i][j] == 0) return ;
    if (v[i][j] == 2) return ; // already visited;
    v[i][j] = 2;
    flood_fill(v, i+1, j);
    flood_fill(v, i-1, j);
    flood_fill(v, i, j+1);
    flood_fill(v, i, j-1);
    // other four directions:
    flood_fill(v, i+1, j+1);
    flood_fill(v, i+1, j-1);
    flood_fill(v, i-1, j+1);
    flood_fill(v, i-1, j-1);
}