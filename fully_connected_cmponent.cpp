#include <bits/stdc++.h>

using namespace std;


void dfs(vector<vector<int>> &g, int s, vector<int> &visited, vector<int> &process_order){
    if (visited[s]) return ;
    visited[s] = 1;
    for (auto v : g[s]){
        dfs(g, v, visited, process_order);
    }
    process_order.push_back(s);
}

vector<int> kosaraju_scc(vector<vector<int>> &g){
    int n = g.size();
    vector<int> process_order;
    vector<int> visited(n, 0);
    int scc = 0;
    for (int i = 0 ; i<n ; i++){
        if (visited[i] == 0){
            dfs(g, i , visited, process_order);
        }
    }
    vector<vector<int>> rev_g(n);
    for (int i = 0 ; i<n ; i++){
        for (auto v : g[i]){
            rev_g[v].push_back(i);
        }
    }
    reverse(process_order.begin(), process_order.end());
    for (int i = 0 ;i<n ;i++ ) visited[i] = 0;
    vector<int> tmp, start;
    for (auto i: process_order){
        if (visited[i] == 0){
            start.push_back(i);
            dfs(rev_g, i , visited, tmp);
            scc++;
        }
    }
    return start; // or fcc depend on the context of prob;
}


int main(){
    int n; cin >> n;
    int m ; cin >> m;
    vector<vector<int>> g(n);
    for(int i = 0 ; i<m ; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
    }

    vector<int> c = kosaraju_fcc(g);
    if (c.size() == 1){
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
        cout << c[1]+1 << ' ' << c[0]+1 << endl;
    }

    return 0;
}