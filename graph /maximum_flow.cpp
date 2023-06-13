#include <bits/stdc++.h>

using namespace std;

long long flow = 0;
map<pair<int,int>, vector<int>> edges_to_remove;
vector<vector<int>> path_src_to_sink;
int path_number = 1;

void _max_flow_bfs(vector<vector<long long>> &g , int s, int d , bool &found){
    // cout << "entered" << endl;
    int n = g.size();
    vector<int> visited(n , 0) , parent(n, 0);
    queue<pair<int,int>> q;
    q.push({s,INT_MAX});
    long long min_path_len = INT_MAX;
    while (!q.empty()){
        int v = q.front().first;
        int x = q.front().second;
        q.pop();
        if (visited[v]) continue;
        // cout << v << ' ';
        visited[v] = 1;
        if (v == d){
            found = true;
            break;
        }
        for (int i = 0; i < g[v].size() ; i++){
            if (g[v][i] and parent[i]==0){
                parent[i] = v;
                q.push({i, g[v][i]});
            }
        }
    }
    // cout << "done!";
    if (found){
        int tmp = d;
        vector<int> path;
        while (d!=s){
            min_path_len = min(min_path_len , g[parent[d]][d]);
            path.push_back(d);
            d = parent[d];
        }
        path.push_back(s);
        reverse(path.begin() , path.end());
        path_src_to_sink.push_back(path);
        // cout << min_path_len << ' ' ;
        d = tmp;
        while (d!=s){
            g[parent[d]][d] -= min_path_len;
            g[d][parent[d]] += min_path_len;
            // edges_to_remove[{min(d, parent[d]), max(d, parent[d])}].push_back(path_number) ;
            d = parent[d];
        }
        path_number++;
        flow += min_path_len;
        // cout << min_path_len ;
    }
}

void max_flow(vector<vector<long long>> &g , int s, int d){
    int path_min = INT_MAX;
    bool found = true;
    while (found){
        path_min = INT_MAX;
        found =false;
        vector<int> visited(g.size() , 0);  
        _max_flow_bfs(g, s, d, found);
    }
}

