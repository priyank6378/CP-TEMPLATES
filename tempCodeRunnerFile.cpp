void dfs(vector<vector<int>> &g, int s, vector<int> &order , vector<int>&visited){
    if (visited[s]) return ;
    visited[s] = 1;
    for (auto v: g[s]){
        dfs(g, v, order, visited);
    }
    order.push_back(s);
}