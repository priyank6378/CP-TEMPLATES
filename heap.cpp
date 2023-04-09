#include <bits/stdc++.h>

using namespace std;

#define MIN_HEAP 0
#define MAX_HEAP 1

class Heap{
private:
    int n ;
    int type;
    vector<int> heap;
public:
    Heap(int n , int type){
        this->type = MIN_HEAP;
        this->n = n;
        heap.resize(n);
    }

    Heap(){
        type = MIN_HEAP;
        n = 0;
    }

    int parent(int i){
        i++;
        if (i/2 >= 0)
            return i/2 - 1;
        return 0;
    }

    int left_child(int i){
        i++;
        if (i*2 <= n)
            return i*2-1;
        return n-1;
    }

    int right_child(int i){
        i++;
        if (i*2 + 1 <= n)
            return i*2 ;
        return n-1;
    }

    void min_heapify_top(int i){
        int l=left_child(i), r=right_child(i);
        int m = i;
        if (l<n and heap[i]>heap[l]){
            int t = heap[i];
            heap[i] = heap[l];
            heap[l] = t;
            m = l;
        }
        if (r<n and heap[m]>heap[r]){
            int t = heap[m];
            heap[m] = heap[r];
            heap[r] = t;
            m = r;
        }
        if (m!=i){
            min_heapify_top(m);
        }
    }

    void min_heapify(int i){
        if (i == 0) return ;
        int p = parent(i);
        if (heap[i] < heap[p]){
            int tmp = heap[i];
            heap[i] = heap[p];
            heap[p] = tmp;
            min_heapify(p);
        }
    }

    void add(int x){
        heap.push_back(x);
        n = heap.size();
        min_heapify(n-1);
    }

    int get(){
        int x = heap[0];
        heap[0] = heap[n-1];
        n--;
        min_heapify_top(0);
        return x;
    }

    int operator [](int i){
        return heap[i];
    }

    int size(){
        return n;
    }
};

// int main(){
//     Heap h;
//     h.add(10);
//     for (int i = 0 ;i<h.size() ; i++){
//         cout << h[i] << ' ';
//     }cout << endl;
//     h.add(9);
//     for (int i = 0 ;i<h.size() ; i++){
//         cout << h[i] << ' ';
//     }cout << endl;
//     h.add(20);
//     for (int i = 0 ;i<h.size() ; i++){
//         cout << h[i] << ' ';
//     }cout << endl;
//     h.add(1);
//     for (int i = 0 ;i<h.size() ; i++){
//         cout << h[i] << ' ';
//     }cout << endl;
//     int x = h.get();
//     cout << x << endl;
//     for (int i = 0 ;i<h.size() ; i++){
//         cout << h[i] << ' ';
//     }cout << endl;
//     x = h.get();
//     cout << x << endl;
//     for (int i = 0 ;i<h.size() ; i++){
//         cout << h[i] << ' ';
//     }cout << endl;
//      x = h.get();
//     cout << x << endl;
//     for (int i = 0 ;i<h.size() ; i++){
//         cout << h[i] << ' ';
//     }cout << endl;
//      x = h.get();
//     cout << x << endl;
//     for (int i = 0 ;i<h.size() ; i++){
//         cout << h[i] << ' ';
//     }cout << endl;
// }