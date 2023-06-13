#include <bits/stdc++.h>
using namespace std;

//******** Returns true if graph is bipartite ********//
bool is_bipartite(vector<vector<int>> &g, int s, vector<int> &visited)
{
    // unvisited nodes have -1 visited value; and only s have visited[s] == 1;
    if (visited[s] == -1)
    {
        return true;
    }
    bool x = true;
    for (auto v : g[s])
    {
        if (visited[v] == -1 and visited[s] != visited[v])
        {
            visited[v] = 1 - visited[s];
            x = x & is_bipartite(g, v, visited);
        }
        else if (visited[v] != -1 and visited[s] == visited[v])
        {
            x = false;
            return x;
        }
    }
    return x;
}