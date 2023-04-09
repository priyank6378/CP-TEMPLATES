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
        return parent(s[a]);
    }

    int isSameSet(int a, int b)
    {
        return parent(s[a]) == parent(s[b]);
    }
};
