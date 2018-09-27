#include <iostream>
#include <vector>
#include <stack>
using namespace std;

namespace rbtree {
using namespace std;

enum COLOR {
    BLACK = 0,
    RED = 1,
};


template <typename T>
class node {
public:
    node() { l = nullptr, r = nullptr, p = nullptr, cl = BLACK, cnt = 0, freq = 0; }
    node(const T& a): val(a) { l = nullptr, r = nullptr, p = nullptr, cl = BLACK, cnt = 0, freq = 0; }
    node(const T&& a): val(a) { l = nullptr, r = nullptr, p = nullptr, cl = BLACK, cnt = 0, freq = 0; }

    node<T>* left() { return l; }
    node<T>* right() { return r; }
    node<T>* parent() { return p; }
    COLOR color() { return cl; }

    T value(){ return val; }
    unsigned int count() { return cnt; }
    unsigned int frequence() { return freq;}

    void set_left(node<T>* ptr) { l = ptr; }
    void set_right(node<T>* ptr) { r = ptr; }
    void set_parent(node<T>* ptr) { p = ptr; }
    void set_color(const COLOR c) { cl = c; }
    void set_value(const T& val) { this -> val = val; }
    void set_count(const unsigned int ct) { cnt = ct; }
    void set_frequence(const unsigned int f) {freq = f;}

private:
    node<T>* l; 
    node<T>* r;
    node<T>* p;
    COLOR cl;
    T val;
    unsigned int cnt;
    unsigned int freq;
};


template <typename T>
class rbtree {
public:
    rbtree() { 
        nil = new node<T>; 
        nil -> set_left(nil);
        nil -> set_right(nil);
        nil -> set_parent(nil);
        root = nil;
    }

    ~rbtree();
    void add(const T &val);
    //node<T>* root() { return root; }

    void test();
    bool test_bh();
    unsigned int count_less_then(const T& val);

private:
    void insert_fixup(node<T>* x);
    void left_rotate(node<T>* const x);
    void right_rotate(node<T>* const x);

    node<T> * root;
    node<T> * nil;
};


template <typename T>
rbtree<T>::~rbtree() {
    stack<node<T> *> stk;
    stk.push(root);

    while(!stk.empty()) {
        node <T> * ptr = stk.top();
        stk.pop();
        while ( ptr != nil ) {
            node <T> * left = ptr -> left();
            node <T> * right = ptr -> right();

            stk.push(right);
            ptr -> set_left(nullptr);
            ptr -> set_right(nullptr);

            delete ptr;
            ptr = left;
        }
    }

    delete nil;
    nil = nullptr;
    root = nullptr;
}


template <typename T>
void rbtree<T>::add(const T &val) {
    node<T>* parent = nil;
    node<T>* ptr = root;

    while( ptr != nil ) {
        ptr -> set_count(ptr -> count() + 1);
        parent = ptr;

        if (val == ptr->value()) {
            ptr -> set_frequence(ptr -> frequence() + 1);
            return;
        }

        if ( val < ptr -> value()) ptr = ptr -> left();
        else ptr = ptr -> right();
    }

    node<T>* z = new node<T>( val );
    z -> set_count(1);
    z -> set_frequence(1);

    if (root == nil) 
        root = z;
    else {
        if ( val < parent -> value() ) parent -> set_left(z);
        else parent -> set_right(z);
    }

    z -> set_parent( parent );
    z -> set_left(nil);
    z -> set_right(nil);
    z -> set_color(RED);

    insert_fixup(z);
}

template <typename T>
unsigned int rbtree<T>::count_less_then(const T& val) {
    unsigned int ret = 0;
    node<T>* ptr = root;

    while( ptr != nil ) {
        if ( val < ptr -> value() ) ptr = ptr -> left();
        else {
            ret += (ptr -> left() -> count());
            if (val > ptr -> value() ) ret += ptr->frequence();

            ptr = ptr -> right();
        }
    }
    return ret;
}


template <typename T>
void rbtree<T>::insert_fixup(node<T>* x) {
    while (x -> parent() -> color() == RED) {
        if ( x -> parent() == x -> parent() -> parent() -> left()) {
            node <T> * y = x -> parent() -> parent() -> right();
            if (y -> color() == RED) {
                x -> parent() -> set_color(BLACK);
                y -> set_color(BLACK);
                x -> parent() -> parent() -> set_color(RED);
                x = x -> parent() -> parent();
            }
            else {
                if (x == x -> parent() -> right()) {
                    x = x -> parent();
                    left_rotate(x);
                }
                x -> parent() -> set_color(BLACK);
                x -> parent() -> parent() -> set_color(RED);
                right_rotate(x -> parent() -> parent());
            }
        }
        else {
            node <T> * y = x -> parent() -> parent() -> left();
            if (y -> color() == RED) {
                x -> parent() -> set_color(BLACK);
                y -> set_color(BLACK);
                x -> parent() -> parent() -> set_color(RED);
                x = x -> parent() -> parent();
            }
            else {
                if (x == x -> parent() -> left()) {
                    x = x -> parent();
                    right_rotate(x);
                }
                x -> parent() -> set_color(BLACK);
                x -> parent() -> parent() -> set_color(RED);
                left_rotate(x -> parent() -> parent());
            }
        }
    }
    root -> set_color(BLACK);
}


template <typename T>
void rbtree<T>::left_rotate(node<T>* const x) {
    node<T> * const right = x -> right();
    if( x == root ) {
        root = right;
    }
    else {
        if (x == x -> parent() -> left()) {
            x -> parent() -> set_left(right);
        }
        else {
            x -> parent() -> set_right(right);
        }
    }
    right -> set_parent(x -> parent());

    x -> set_parent(right);
    x -> set_right(right -> left());

    if (right -> left() != nil) {
        right -> left() -> set_parent(x);
    }
    right -> set_left(x);

    x -> set_count(x -> left() -> count() + x -> right() -> count() + x -> frequence());
    right -> set_count(right -> left() -> count() + right -> right() -> count() + right -> frequence());
}


template <typename T>
void rbtree<T>::right_rotate(node<T>* const x) {
    node<T> * const left = x -> left();
    if (x == root) {
        root = left;
    }
    else {
        if (x == x -> parent() -> left()) {
            x -> parent() -> set_left(left);
        }
        else {
            x -> parent() -> set_right(left);
        }
    }
    left -> set_parent(x -> parent());

    x -> set_parent(left);
    x -> set_left(left -> right());

    if (left -> right() != nil) {
        left -> right() -> set_parent(x);
    }
    left -> set_right(x);

    x -> set_count(x -> left() -> count() + x -> right() -> count() + x -> frequence());
    left -> set_count(left -> left() -> count() + left -> right() -> count() + left -> frequence());
}
}

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        long long int sum = 0;
        int ret = 0;
        rbtree::rbtree<long long int> tree;
        tree.add(0);
        for (auto item : nums) {
            sum += item;
            unsigned int c1 = tree.count_less_then(sum - upper);
            unsigned int c2 = tree.count_less_then(sum - lower + 1);

            ret += ( c2 - c1 );
            tree.add(sum);
        }
        return ret;
    }
};


int main() {
    Solution s;
    vector<int> vec = {0,-1,1,2,-3,-3};
    int lower = -3, upper = 1;
    int ret = s.countRangeSum(vec, lower, upper);
    cout << ret << endl;

    return 0;
}
