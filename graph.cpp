#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph(int n, int m){
    int x,y;
    vector<vector<int>> g(n);
    for (int i = 0 ; i<m; i++){
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);  // comment out if the graph is directed
    }
    return g;
}

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


///////////////////////////////////////////////////////////////////////////
/**********************BELLMAN FORD ALGORITHM*****************************/
/* 
It is used to find shortest path between given node and all the other nodes.
It also helps in finding if there a negetive cycle in the graph.
*/
///////////////////////////////////////////////////////////////////////////
vector<double> bellman_ford(vector<tuple<int,int,int>> &edges, int s, int n){
    vector<double> distance(n+1 , INFINITY);
    int a,b,w;
    for (int i = 0 ;i< n-1 ;i++){
        for (auto edge : edges){
            tie(a,b,w) = edge;
            distance[b] = min(distance[b] , distance[a]+w);
        }
    }
    bool neg_cycle = false;
    for (auto e: edges){
        tie(a,b,w) = e;
        if (distance[b] > distance[a]+w){
            neg_cycle = true;
        }
    }
    return distance;
}

void dijkstra(vector<vector<pair<int,int>>> &g, int s, vector<long long> &dis, vector<int> &parent)
{
    priority_queue<pair<long long int, int>> q;
    vector<int> visited(g.size(), 0);
    q.push({0, s});
    for (int i = 0; i < g.size(); i++)
        dis[i] = LONG_MAX;
    dis[s] = 0;
    parent[s] = -1;
    visited[s] = 0;
    while (!q.empty())
    {
        pair<long long, int> x = q.top(); // x.first = distance and x.second = node
        q.pop();
        if (visited[x.second])
            continue;
        visited[x.second] = 1;
        for (auto v : g[x.second])
        {
            if (dis[v.first] > dis[x.second] + v.second)
            {
                dis[v.first] = dis[x.second] + v.second;
                parent[v.first] = x.second;
                q.push({-(dis[v.first]), v.first});
            }
        }
    }
}


void floyd_warshall(vector<vector<int>> &g){
    int n = g.size();
    for(int i = 0 ;i<n ;i++){
        for (int j = 0 ;j<n ;j++){
            if (g[i][j] == 0){
                g[i][j] = INT_MAX;
            }
        }
    }
    for (int mid = 0 ; mid<n; mid++){
        for (int i = 0 ;i<n ;i++){
            for (int j = 0 ; j<n ; j++){
                g[i][j] = min(g[i][j] , g[i][mid] + g[mid][j]);
            }
        }
    }
}

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

//////////////////////////////////////////////////////////////////////////////////////////////////
// slower topological sort and bigger code//
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
// FASTER TOPOLOGICAL SORT //
//////////////////////////////////////////////////////////////
// make reverse topological sort
void dfs(vector<vector<int>> &g, int s, vector<int> &order , vector<int>&visited){
    if (visited[s]) return ;
    visited[s] = 1;
    for (auto v: g[s]){
        dfs(g, v, order, visited);
    }
    order.push_back(s);
}


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