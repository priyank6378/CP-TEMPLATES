#include <bits/stdc++.h>

using namespace std;

class Trie{
public:
    int count ; // how many times does we pass this node
    Trie *t[26]; // 26 alphabets

    Trie(){
        count = 0;
        for (int i = 0 ;i<26 ;i++){
            t[i] = nullptr;
        }
    }

    void insert(string s){
        Trie *x = nullptr;
        Trie **y = t;
        for (char i: s){
            x = *(y+ i-'a');
            if (x == nullptr){
                x = new Trie();
                x->count ++ ;
                *(y+ i-'a') = x;
            }
            else {
                x->count++;
            }
            y = x->t;
        }
    }

    int find(string s){
        Trie *x = nullptr;
        Trie **y = t;
        for (char i: s){
            x = *(y+ i-'a');
            if (x == nullptr){
                return 0;
            }
            y = x->t;
        }
        return 1;
    }

};

/////////////////////////////////////////////////////////////////
//////////////////// 2nd IMPLEMENTATION ////////////////////////
////////////////////////////////////////////////////////////////
struct TrieNode {
    TrieNode *next[26] ; 
    bool end ;
    TrieNode(){
        for (int i = 0 ; i<26 ; i++){
            next[i] = NULL;
        }
        end = false;
    }
};
class Trie{
    public:
        TrieNode t;

        void insert(string word){
            TrieNode *tmp = &t;
            for (auto i: word){
                if (tmp->next[i-'a'] == NULL) tmp->next[i-'a'] = new TrieNode;
                tmp = tmp->next[i-'a'];
            }
            tmp->end = true;
        }

        bool find(string s){
            TrieNode *x = &t;
            for (auto i: s){
                if (x->next[i-'a'] == NULL) return false;
                x = x->next[i-'a'];
            }
            return x->end;
        }
        
};
//////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////


int main(){
    Trie a;
    a.insert("abc");
    a.insert("abd");
    cout << a.find("abc") << a.find("ab") << a.find("abx")<< endl;
    return 0;
}