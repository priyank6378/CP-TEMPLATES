#include <bits/stdc++.h>

using namespace std;

// also called binary indexed tree:
class FenwickTree{
public:
    vector<int> tree;
    vector<int> a;
    int n;

    FenwickTree(vector<int> &x){
        a = x;
        n = a.size();
        tree.resize(n+1);
        for (int i = 0 ;i<n+1 ;i++) tree[i] = 0;
        tree[0] = 0; 
        // tree[1] = a[0];
        for (int i = 1 ;i<=n ;i++){
            // tree construction loop:
            update(i, a[i-1]);
            // tree[i] = 0;
            // for (int j=i-1; j>i-1-(i&-i) ;j--){
            //     tree[i] += a[j];
            // }
        }
    }

    int sum_x(int x){
        int ans = 0 ;
        while (x){
            ans += tree[x];
            x -= (x&-x);
        }
        return ans;
    }

    int range_sum(int i ,int j){
        if (i == 0) return sum_x(j);
        return sum_x(j) - sum_x(i-1);
    }

    void update(int index, int x){
        // index is started from 1
        // x is the increase in the value at index
        while (index < n+1){
            tree[index] += x;
            index += index&-index;
        }
        a[index-1] += x;
    }
};

int main(){
    vector<int> x = {1,2,3,4,5,6,7};
    FenwickTree f(x);
    for (auto i: f.tree ) cout << i << ' ' ;
}