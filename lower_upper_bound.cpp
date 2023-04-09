#include <bits/stdc++.h>

using namespace std;

int lower(vector<int> & a, int target){
    if (a.size() == 0) return -1;
    int l = 0 , h = a.size()-1, m=0 ;
    while (l<h){
        m = (l+h)/2;
        if (a[m]>=target){
            h = m;
        }
        else {
            l = m+1;
        }
    }
    if (a[l] == target) return l;
    return -1;
}
int upper(vector<int> & a, int target){
    if (a.size() == 0) return -1;
    int l = 0 , h = a.size()-1, m=0 ;
    while (l<h){
        m = (l+h)/2 + ((l+h)&1);
        if (a[m]>target){
            h = m-1;
        }
        else {
            l = m;
        }
    }
    if (a[l] == target) return l;
    return -1;
}