#include <bits/stdc++.h>
using namespace std;

template<class T>
T gcd(T a, T b){
    // a>=b : make sure
    if (b == 0) return a;
    return gcd(b, a%b)
}