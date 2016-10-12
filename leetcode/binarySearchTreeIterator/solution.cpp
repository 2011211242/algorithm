#include <cstdio>
#include <stack>

using namespace std;
/**
 * Definition for binary tree
 */

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
private:
    TreeNode * next, *cur;

public:
    BSTIterator(TreeNode *root) {
        if(root == NULL) return NULL;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {

    }

    /** @return the next smallest number */
    int next() {

    }
};

int main(){
    BSTIterator i = BSTIterator(root);
    while (i.hasNext()) cout << i.next();
}
