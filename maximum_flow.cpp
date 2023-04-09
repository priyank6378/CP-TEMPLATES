#include <bits/stdc++.h>

using namespace std;

long long flow = 0;
map<pair<int,int>, vector<int>> edges_to_remove;
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
        while (d!=s){
            min_path_len = min(min_path_len , g[parent[d]][d]);
            d = parent[d];
        }
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



int main(){
    int n , m ; cin >> n >> m;
    vector<vector<long long >> g(n+1 , vector<long long>(n+1, 0)) ;
    // int k ; cin >> k;
    for(int i = 0 ;i<m ;i++){
        int a, b , c;
        cin >> a >> b ;
        c = 1;
        // b += n;
        g[a][b] += c;
        g[b][a] += c; 
    }
    vector<vector<long long>> g2(g);
    // for (int i = 1; i<=n; i++) g[0][i] = g[i][0] = 1;
    // for (int i = n+1; i<=n+m; i++) g[i][n+m+1] = g[n+m+1][i] = 1;
    
    // for (auto i: g) {for (auto j : i) {cout << j << ' ' ;}cout << endl;}

    max_flow(g, 1, n);
    cout << flow << endl;

    for (int i = 1 ; i<=n ;i++){
        for (int j = 1; j<n+1; j++){
            if ((g2[i][j] != 0 and g[i][j] == 0)) cout << i << ' ' << j << endl;
        }
    }

    // vector<int> paths(path_number+1,0);
    // for (auto i: edges_to_remove){
    //     auto e = i.first;
    //     if (e.first != 0 and e.first!= n+m+1 and e.second!=0 and e.second!=n+m+1){
    //         cout << e.first << ' ' << e.second-n << endl;
    //     }
    // }
}