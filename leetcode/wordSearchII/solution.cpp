#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <stdbool.h>
#include <stack>
#include <algorithm>
using namespace std;

class TrieNode{
private:
    #define CHARACTER_NUM 26
    TrieNode * next[CHARACTER_NUM];
    int cnt[CHARACTER_NUM];
    bool trail;
public:
    TrieNode(){
        fill(next, next + CHARACTER_NUM, (TrieNode *)NULL);
        fill(cnt, cnt + CHARACTER_NUM, 0);
        trail = false;
    }

    TrieNode * insert(char c){
        unsigned int idx = c -'a';
        if(this->next[idx] == NULL){
            this->next[idx] = new TrieNode();
        }
        this -> cnt[idx]++;
        return this->next[idx];
    }

    TrieNode * remove(char c){
        unsigned int idx = c - 'a';
        this -> cnt[idx]--;
        return this->next[idx];
    }

    bool isTrail(){
        return this->trail;
    }

    bool del(char c){
        unsigned int idx = c - 'a';
        if(this->next[idx] && this -> cnt[idx] == 0){
            delete this->next[idx];
            this->next[idx] = NULL;
            return true;
        }
        return false;
    }

    void setTrail(bool set){
        this->trail = set;
    }

    TrieNode * search(char c){
        unsigned int idx = c - 'a';
        return this->next[idx];
    }
};

class Trie{
public:
    enum type {invalid = 0, prefix, item};

    Trie(){
        root = new TrieNode();
    }

    void insert(string &word){
        TrieNode * ptr = root;
        for(auto c : word){
            ptr = ptr->insert(c);
        }
        ptr -> setTrail(true);
    }

    type search(string &word){
        TrieNode * ptr = root;
        for(auto c : word){
            ptr = ptr->search(c);
            if(ptr == NULL) return invalid;
        }

        if(ptr->isTrail()) return item;
        return prefix;
    }


    void remove(string &word){
        TrieNode * ptr = root;
        stack<TrieNode*> st;
        st.push(ptr);
        for(auto c : word){
            ptr = ptr->remove(c);
            if(ptr == NULL) return;
            st.push(ptr);
        }

        //ptr = st.top();
        ptr -> setTrail(false);
        st.pop();

        for(int i = word.length() - 1; i >= 0; i--){
            ptr = st.top();
            st.pop();
            if(ptr -> del(word[i]) == false) return;
        }
    }

    ~Trie(){
        delete root;
    }

private:
    TrieNode * root;
};

class Solution {
public:
    Trie trie;
    vector<string> ret;

    void search(vector<vector<bool>> &visit, vector<vector<char>> &board, int x, int y, string str){
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || visit[x][y]) return;

        str.push_back(board[x][y]);
        if(trie.search(str) == Trie::invalid) return;

        if(trie.search(str) == Trie::item){
            ret.push_back(str);
            trie.remove(str);
        }

        visit[x][y] = true;
        search(visit, board, x - 1, y, str);
        search(visit, board, x + 1, y, str);
        search(visit, board, x, y - 1, str);
        search(visit, board, x, y + 1, str);
        visit[x][y] = false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0; i < words.size(); i++){
            if(trie.search(words[i]) != Trie::item)
                trie.insert(words[i]);
        }

        for(int i = 0; i <= board.size(); i++){
            for(int j = 0; j <= board.size(); j++){
                search(visit, board, i, j, string(""));
            }
        }
        return ret;
    }
};

int main(){
    vector<vector<char>> board = {
        {'b', 'b', 'a', 'a', 'b', 'a'},
        {'b', 'b', 'a', 'b', 'a', 'a'},

        {'b', 'b', 'b', 'b', 'b', 'b'},

        {'a', 'a', 'a', 'b', 'a', 'a'},
        {'a', 'b', 'a', 'a', 'b', 'b'},
    };
    vector<string> words = {
        string("abbbababaa")
    };

    //vector<vector<char>> board = {{'a', 'a'}};
    //vector<string> words = {"a"};
    Solution s;
    vector<string> ret;
    ret = s.findWords(board, words);
    for(string str:ret){
        printf("ret = %s\n", str.c_str());
    }

}
