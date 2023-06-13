#include <bits/stdc++.h>
using namespace std;

class DisjointSetUnion
{
public:
    vector<int> s;

    DisjointSetUnion(int n)
    {
        for (int i = 0; i < n; i++)
            s.push_back(i);
    }

    void set_union(int a, int b)
    {
        int pa = parent(a);
        int pb = parent(b);
        s[pa] = pb;
    }

    int parent(int a)
    {
        if (s[a] == a)
            return a;
        return s[a]=parent(s[a]);
    }

    int isSameSet(int a, int b)
    {
        return parent(s[a]) == parent(s[b]);
    }
};


///////////////////////////////////////////////////////////////////////////
/**********************KRUSKAL ALGORITHM*****************************/
/* 
It is used to find minimum spanning tree.
*/
///////////////////////////////////////////////////////////////////////////
long int  kruskal(vector<pair<int,pair<int,int>>> edges, int v){
    // vector<pair<int,pair<int,int>>> mst;
    long int cost = 0;
    DisjointSetUnion ds(v);
    sort(edges.begin() , edges.end());
    for (auto e: edges){
        if (!ds.isSameSet(e.second.first, e.second.second)){
            //mst.push_back(e);
            cost += e.first;
            ds.set_union(e.second.first, e.second.second);
        }
    }
    return cost;
}