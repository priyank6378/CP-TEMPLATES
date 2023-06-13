#include <bits/stdc++.h>
using namespace std;

bitset<INT_MAX+(long)1> seive(~0);

void make_seive(long n){
    for (long i = 2 ;i <= n ;i++){
        if (seive[i]){
            for (long j = i*i ; j<=n ;j+=i)
                seive[j] = 0;
        }
    }
}


// with every number also stores its smallest prime factor
vector<pair<int,int>> make_extended_seive(int n){
    vector<pair<int,int>> seive(n+1, {1,1});
    for (int i = 2 ;i <= n ;i++){
        if (seive[i].first){
            for (int j = i ; j<=n ;j+=i){
                seive[j].first = 0;
                if (seive[j].second == 1)
                seive[j].second = i;
            }
        }
    }
    return seive;
}

int count_divisors(int n , vector<pair<int,int>> &seive){
    int ans = 0;
    if (seive[n].second == n) ans = 0;
    else ans = 1;
    while (n>1){
        n = n/seive[n].second;
        ans ++ ;
    }
    ans ++ ;
    return ans;
}


int main(){
    int n  = 10;
    vector<pair<int,int>> s = make_extended_seive(n);
    for (int i = 0 ;i<=n ;i++){
        cout << i << ' ' << s[i].second << endl;
    }
    cout << count_divisors(6, s) << endl;;
}