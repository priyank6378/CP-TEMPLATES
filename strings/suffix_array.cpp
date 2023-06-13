#include <bits/stdc++.h>

using namespace std;

class SuffixArray{
public:
    vector<int> sa;
    vector<int> ra;
    string s;
    int n;

    SuffixArray(string str){
        s = str;
        s += "$";
        n = s.size();
        
        for (int i = 0 ; i<n; i++){
            sa.push_back(i);
            ra.push_back(s[i]);
        }
        for (int k = 1; k<n; k<<=1){
            if (ra[n-1] == n-1) {
                return;
            }
            __update_sa(k);
            __update_sa(0);

            vector<int> tmpra(n);
            tmpra[0] = 0;
            int r = 0 ;
            for (int i = 1 ; i<n ; i++){
                tmpra[sa[i]] = (ra[sa[i]]==ra[sa[i-1]] && ra[sa[i]+k]==ra[sa[i-1]+k] ? r : ++r);
            }
            for (int i = 0 ; i<n ;i++){
                ra[i] = tmpra[i];
            }
        }
    }

    void __update_sa(int k){
        vector<int> tmpsa(n);
        vector<int> cnt(max(n, 300), 0);
        for (int i = 0 ; i<n ;i++) cnt[i+k<n ? ra[i+k] : 0]++;
        int sum = 0, tmp;
        for (int i = 0 ; i<cnt.size() ;i++) {
            tmp = cnt[i];
            cnt[i] = sum;
            sum += tmp;
        }
        for (int i = 0 ; i<n ;i++){
            int ind = (sa[i]+k<n?ra[sa[i]+k]:0);
            tmpsa[cnt[ind]++] = sa[i] ;
        }
        for (int i = 0 ;i<n ;i++){
            sa[i] = tmpsa[i];
        }
    }

    int _strcmp(string& p, int x){
        int i = 0 , j = 0 ; 
        int m = p.size();
        while (i<n and j<m){
            if (*(s.begin()+x+i)!=p[j]) return *(s.begin()+x+i)-p[j];
        }
        return 0;
    }

    pair<int,int> search(string& p){
        int l = 0 , h = n-1;
        while (l<h){
            int m = (l+h)/2;
            if (_strcmp(p, sa[m])>=0) h = m;
            else l = m+1;
        }
        int lo = 0;
        if (_strcmp(p, sa[h]) == 0)
            lo = h;
        else return {-1,-1};
        // finding upper bound
        l = 0 , h = n-1;
        while (l<h){
            int m = (l+h)/2 + (l+h)%2;
            if (_strcmp(p, sa[m])>0) h = m-1;
            else l = m;
        }
        int hi = 0;
        if (_strcmp(p,sa[h]) == 0)
            hi = h;
        else hi = lo;
        return {lo, hi};
    }

    // permuted longest common prefix (plcp)
    /* It finds the longest common prefix in O(n) time. */
    vector<int> plcp(){
        int i , l ;
        vector<int> phi(n) , plcp(n);
        phi[sa[0]] = -1;
        for (i = 1; i<n ; i++){
            phi[sa[i]] = sa[i-1];
        }
        for (i = l = 0  ; i<n ;i++){
            if (phi[i] == -1){
                plcp[i] = 0; 
                continue;
            }
            while (s[i+l] == s[phi[i]+l]) l++;
            plcp[i] = l;
            l = max(l-1, 0);   // decreasing l for next iteration
        }

        vector<int> lcp(n);
        for (i = 0 ; i<n; i++){
            lcp[i] = plcp[sa[i]];
        }
        return lcp;
    }

    void display(){
        for (auto i: sa) cout << i << ' ' ; cout << endl;
    }
};


int main(){
    string s = "ABRACADABRA";
    cin >> s;
    int n = s.size();
    s += s;
    SuffixArray sa(s);
    for (auto i: sa.sa){
        if (i<=n){
            for (int x = i ;x < i+n ;x++)cout << s[x];
            cout << endl;
            return 0;
        }
    }
    return 0;
}