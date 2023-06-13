#include <bits/stdc++.h>
using namespace std;

vector<int> pattern_proc(string p){
    int i = 1;
    int j = 0;
    int m = p.size();
    vector<int> reset(m, 0);
    reset[0] = 0;
    while (i<m){
        if (p[i] == p[j]){
            reset[i] = j;
            j++;
        }
        else {
            reset[i] = j;
            j = 0;
            
        }
        if (i == m-1) reset.push_back(j);
        i++;
    }
    return reset;
}

void find_pattern(string s, string p){
    vector<int> b = pattern_proc(p);
    int j = 0;
    int i = 0;
    while (i<s.size()){
        if (s[i]!=p[j]){
            j = b[j];
            i++;
        }
        while (i<s.size() and j<p.size() and s[i] == p[j]) i++, j++;
        if (j == p.size()) {
            // do something with this
            cout << "found : " << i - p.size() << endl;
        }
        j = b[j];
    }
}

int main(){
    string s = "i do not like seventy sev but seventy sevqnty seven";
    string p = "seventy sevqn";
    find_pattern(s, p);
}