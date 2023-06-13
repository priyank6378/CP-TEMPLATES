#include <bits/stdc++.h>
using namespace std;

//**** It finds the cycle in the graph ******//
// it has _find_cycle helper function
vector<int> find_cycle(vector<vector<int>> &g){
    int n = g.size();
    vector<int> visited(n, 0);
    bool x = false;
    int s = -1;
    vector<int> cycle;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            _find_cycle(g, i, visited, x, -1, cycle);
            s = i;
            if (x and s == cycle[0])
            {
                cycle.push_back(s);
            }
        }
        if (x == true)
        {
            if (cycle[0] != cycle[cycle.size() - 1])
            {
                while (cycle[0] != cycle[cycle.size() - 1])
                    cycle.pop_back();
            }
            break;
        }
    }
    return cycle;
}
void _find_cycle(vector<vector<int>> &g, int s , vector<int> &visited, bool &found, int parent, vector<int> &cycle){
    visited[s] = 1;
    
    for (auto v: g[s]){
        if (visited[v] == 1 and v!=parent){
            found = true;
        }
        else if (visited[v] != 1) {
            _find_cycle(g, v, visited, found, s, cycle);
        }
        if (found){
            cycle.push_back(v);
            return ;
        }
    }
}



//*** It detects the cycle in the graph ***//
bool detect_cycle(vector<vector<pair<int,int>>>& g, int s, set<int>& recstack , vector<int>& visited){
    if (visited[s])return false;
    bool ans = false;
    recstack.insert(s);
    visited[s] = 1;
    for (auto node : g[s]){
        if (recstack.find(node.first)!=recstack.end()){
            ans = true;
            break;
        }
        ans |= detect_cycle(g, node.first, recstack, visited);
    }
    recstack.erase(s);
    return ans;
}