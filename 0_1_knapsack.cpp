#include <bits/stdc++.h>
using namespace std;


/*
value = value of perticular item
costs = weight of the item
w     = total capacity
*/
int knapsack01(vector<int> & value, vector<int>& costs , int w){
    int a[value.size()+1][w+1];
    for (int i = 0 ;i<w+1 ;i++){
        a[0][i] = 0;
    }
    for (int i =0  ;i<value.size()+1; i++){
        a[i][0] = 0;
    }
    for (int i = 1 ;i<value.size()+1 ;i++){
        for (int j = 1 ;j<w+1 and j < costs[i-1] ; j++){
            a[i][j] = a[i-1][j];
        }
        for (int j = costs[i-1] ;j<=w ;j++){
            a[i][j] = max( a[i-1][j], value[i-1]+ a[i-1][j-costs[i-1]]);
        }
    }
    return a[value.size()][w];
}