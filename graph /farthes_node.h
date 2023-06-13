int i=0, ans=0, farthest_node_from_u=-1;
void dfs(int u, int visited[]){
    visited[u] = 1;
    for (auto v: g[u]){
        if (visited[v]==0){
            i++;
            dfs(v,visited);
            if (ans<i) ans = i, farthest_node_from_u=v;
            i--;
        }
    }
}
