#include <bits/stdc++.h>

int max(int a, int b){
    if (a>b) return a;
    return b;
}

int lcs(string a, string b){
    int n = a.size(), m = b.size();
    int a[n+1][m+1];
    for (int i = 0 ;i<n+1; i++){
        a[i][0] = 0;
    }
    for (int i = 0 ; i<m+1 ; i++){
        a[0][i] = 0;
    }
    for (int i = 1 ; i<n+1; i++){
        for (int j = 1 ; j<m+1; j++){
            if (a[i-1] == b[j-1]){
                a[i][j] = a[i-1][j-1] + 1 ;
            }
            else {
                a[i][j] = max(a[i-1][j] , a[i][j-1])
            }
        }
    }
    return a[n][m];
}