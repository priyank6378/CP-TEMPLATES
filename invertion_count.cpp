#include <bits/stdc++.h>

using namespace std;

int inv = 0;
void __merge(vector<int> &a , int start, int end, int start1 , int end1){
    int  i = start , j = start1;
    // int n = end-start+end1-start1+2;
    vector<int> b;
    // int k = 0;
    while (i<=end and j<=end1){
        if (a[i]<=a[j]){
            b.push_back(a[i]);
            i++;
        }
        else {
            inv += end-i+1;
            b.push_back(a[j]);
            j++;
        }
    }
    while (i<=end) b.push_back(a[i++]);
    while (j<=end1) b.push_back(a[j++]);
    i = start;
    for (int x = 0 ; x<b.size() ; x++){
        a[i] = b[x];
        i++;   
    }
}

void merge_sort(vector<int> &a, int l , int r){
    if (l == r) return ;
    int m = (l+r)/2;
    merge_sort(a, l, m);
    merge_sort(a, m+1, r);
    __merge(a, l , m , m+1, r);
}


int main(){
    vector<int> a = {2, 4, 1, 3, 5};
    merge_sort(a, 0 , 4);
    for (auto i : a) cout << i << ' ' ; cout << endl;
    cout << inv << endl;
}