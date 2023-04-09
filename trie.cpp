// trie data structure class in c++ for competitive programming

#include <bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
        char data;
        unordered_map<char, TrieNode*> children;
        bool terminal;

        TrieNode(char d){
            data = d;
            terminal = false;
        }
};


class Trie{
    TrieNode* root;
    int cnt;

    public:
        Trie(){
            root = new TrieNode('\0');
            cnt = 0;
        }

        void insert(string word){
            TrieNode* temp = root;
            for (int i = 0 ;i<word.length();i++){
                char ch = word[i];
                if (temp->children.count(ch)){
                    temp = temp->children[ch];
                }
                else{
                    TrieNode* n = new TrieNode(ch);
                    temp->children[ch] = n;
                    temp = n;
                }
            }
            temp->terminal = true;
        }

        bool find(string word){
            TrieNode* temp = root;
            for (int i = 0 ;i<word.length();i++){
                char ch = word[i];
                if (temp->children.count(ch)==0){
                    return false;
                }
                else{
                    temp = temp->children[ch];
                }
            }
            return temp->terminal;
        }
};


int main(){
    Trie t;
    int n;
    cin >> n;
    for (int i = 0 ;i<n;i++){
        string word;
        cin >> word;
        t.insert(word);
    }
    int q;
    cin >> q;
    while(q--){
        string word;
        cin >> word;
        if (t.find(word)){
            cout << "Present" << endl;
        }
        else{
            cout << "Not Present" << endl;
        }
    }
    return 0;
}