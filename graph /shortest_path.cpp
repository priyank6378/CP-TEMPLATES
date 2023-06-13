#include <bits/stdc++.h>
using namespace std;

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


///////////////////////////////////////////////////////////////////////////
/**********************DIJKSTRA ALGORITHM*****************************/
/* 
It is used to find shortest path between given node and all the other nodes.
It is unable to detect -ve cycle.
-ve edge should not be present
*/
///////////////////////////////////////////////////////////////////////////
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


///////////////////////////////////////////////////////////////////////////
/**********************FLOYD WARSHALL ALGORITHM*****************************/
/* 
It is used to find shortest path between all the pair of nodes.
*/
///////////////////////////////////////////////////////////////////////////
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
