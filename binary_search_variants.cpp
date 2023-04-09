#include <bits/stdc++.h>
using namespace std;

int binary_search(int a[], int x,  int n){
    int l = 0, h = n-1 , m = (l+h)/2;
    while (l<=h){
        m = (l+h)/2;
        if (a[m] == x) return m;
        else if (a[m]>x) h = m-1;
        else l = m+1;
    }
    return -1;
}

int binary_search(vector<int> &a, int x){
    int l = 0, h = a.size()-1 , m = (l+h)/2;
    while (l<=h){
        m = (l+h)/2;
        if (a[m] == x) return m;
        else if (a[m]>x) h = m-1;
        else l = m+1;
    }
    return -1;
}

// just lower than x
int lower_lower_bound(vector<int> &a, int x){
    int l = 0, h = a.size()-1 , m = (l+h)/2;
    while (l<=h){
        m = (l+h)/2;
        if (a[m] == x) {
            if (m-1<0) return m;
            h = m-1;
        }
        else if (a[m]>x) h = m-1;
        else{
            if (m+1<a.size() and a[m+1]>=x) return m;
            l = m+1;
        }
    }
    return -1;
}