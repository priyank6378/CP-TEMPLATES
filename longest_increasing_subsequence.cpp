#include <bits/stdc++.h>

using namespace std;

int LIS(vector<int>& a){
    vector<int> v;
    for (auto i: a){
        auto x = lower_bound(v.begin(), v.end(), i);
        if (x == v.end()){
            v.push_back(i);
        }
        else {
            *x = i;
        }
        // for (auto i: v) cout << i << ' ' ; cout << endl;
    }
    return v.size();
}


int main(){
    vector<int> a = {-7,10,9,2,3,8,8,1};
    cout << LIS(a) << endl;
    
    return 0;
}