#include <bits/stdc++.h>

using namespace std;

// T is numeric
template <typename T>
class SegmentTree{
    public:
        vector<T> st;
        int n;
        
        SegmentTree(vector<int> &a){
            int x = a.size();
            n = 1;
            while (n<x)
                n *= 2;
            st.resize(2*n);
            for (int i = n; i<2*n ;i++){
                st[i] = (i-n<x) ? a[i-n] : ~0;  // for sum queries end elements are 0
            }
            for (int i=n-1 ;i>0 ;i--){
                st[i] = st[i*2] ^ st[i*2 + 1]; // for sum queries (modifiy according to use)
            }
            st[0] = -1;
        }
        
        // input : 0 indexed i and j range
        T range_sum(int a , int b){
            a+=n ; b+=n;
            T s = 0;
            while (a<b){
                if (a%2){ // a is right child
                    // a/=2;
                    s -= st[(a/2)*2];
                }
                if (b%2 == 0){ // b is left child
                    s -= st[(b/2)*2 + 1];
                }
                a/=2 ;
                b/=2 ;
            }
            s += st[a];
            return s;
        }

        T range_xor(int a , int b){
            a+=n ; b+=n;
            T s = 0;
            while (a<b){
                if (a%2){
                    // a/=2;
                    s ^= st[(a/2)*2];
                }
                if (b%2 == 0){
                    s ^= st[(b/2)*2 + 1];
                }
                a/=2 ;
                b/=2 ;
            }
            s ^= st[a];
            return s;
        }

        void increment(int pos , int x){
            pos += n;
            while (pos > 0){
                st[pos] += x;
                pos /= 2;
            }
        }

        void update(int pos , int x){
            pos += n;
            int d = x-st[pos];
            while (pos > 0){
                st[pos] += d;
                pos /= 2;
            }
        }

        void show_tree(){
            for (auto i: st){
                cout << i << ' ';
            } cout << endl;
        }
        
};


template <typename T>
class LazySegmentTree{
    public:
        vector<pair<T,T>> st;
        ll n;
        
        LazySegmentTree(vector<int> &a){
            ll x = a.size();
            n = 1;
            while (n<x)
                n *= 2;
            st.resize(2*n);
            for (int i = n; i<2*n ;i++){
                st[i] = (i-n<x) ? make_pair(a[i-n], 0) : make_pair(0,0); 
            }
            for (int i=n-1 ;i>0 ;i--){
                st[i] = {0,0}; 
            }
            st[0] = {-1,-1};
        }

        void range_update(int a, int b, int pos , int x, int y , int u){
            if (b<x || a>y) return ;
            else if (x>=a && y<=b) {
                st[pos].second += u;
                return ;
            }
            int l = 2*pos;
            int r = 2*pos+1;
            st[l].second += st[pos].second;
            st[r].second += st[pos].second;
            st[pos].second = 0;
            int m = (x+y)/2;
            range_update(a,b, l , x, m , u) ;
            range_update(a,b, r, m+1, y, u);
        }

        T kth_element(int k, int x, int y, int pos){
            if (x == y){
                st[pos].first += st[pos].second;
                st[pos].second = 0;
                return st[pos].first;
            }
            int l = 2*pos;
            int r = 2*pos+1;
            st[l].second += st[pos].second;
            st[r].second += st[pos].second;
            st[pos].second = 0;
            int m = (x+y)/2;
            if (k>=x and k<=m)
                return kth_element(k , x, m , l);
            else 
                return kth_element(k , m+1, y , r);
        }

};

int main(){
    vector<int> a = {1,2,3,4};
    SegmentTree<int> s(a);
    cout << s.range_xor(0,3);
    return 0;
}