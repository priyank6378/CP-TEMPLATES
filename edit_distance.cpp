#include <bits/stdc++.h>
using namespace std;


int edit_distance(string a, string b){
	int n = a.size() , m = b.size();
	int d[n+1][m+1];
	for (int i = 0 ;i<n+1 ;i++) d[i][0] = i;
	for (int j = 0 ; j<m+1 ;j++) d[0][j] = j;
	for (int i = 1 ;i<n+1 ;i++){
		for (int j = 1 ; j<m+1 ;j++){
			int x,y,z;
			x = d[i-1][j-1] + (a[i-1] == b[j-1] ? 0 : 1);
			y = d[i-1][j] + 1;
			z = d[i][j-1] + 1;
			d[i][j] = min(x,y);
			d[i][j] = min(d[i][j], z);
		}
	}
	return d[n][m];
}