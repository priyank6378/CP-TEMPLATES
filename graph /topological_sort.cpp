#include <bits/stdc++.h>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////
//****** slower topological sort and bigger code *******//
//////////////////////////////////////////////////////////////////////////////////////////////////
void _topological_sort(vector<vector<int>> &g, int s , vector<int> & order, vector<int>& visited){
    if (visited[s]) return ;
    visited[s] = 1;
    if (g[s].size() == 0) {
        order.push_back(s);
        return ;
    }
    for (auto v: g[s]){
        if (visited[v] == 0) _topological_sort(g, v, order, visited);
    }
    order.push_back(s);
}
vector<int> topological_sort(vector<vector<int>> &g , vector<int>& order){
    int n = g.size();
    vector<int> visited(n,0);
    vector<vector<int>> reverse_g(n);
    for (int i = 0 ;i< n ;i++){
        if (g[i].size()){
            for (auto v : g[i]){
                reverse_g[v].push_back(i);
            }
        }
    }
    // cout << "done making reverse graph..." << endl;
    for (int i = 0 ;i<n;i ++ ){
        if (visited[i] == 0){
            _topological_sort(reverse_g , i , order, visited);
        }
    }
    return order;
}
///////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////
//****** FASTER TOPOLOGICAL SORT *******//
//****make reverse topological sort****//
//////////////////////////////////////////////////////////////

void dfs(vector<vector<int>> &g, int s, vector<int> &order , vector<int>&visited){
    if (visited[s]) return ;
    visited[s] = 1;
    for (auto v: g[s]){
        dfs(g, v, order, visited);
    }
    order.push_back(s);
}
