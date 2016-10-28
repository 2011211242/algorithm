#include <cstdio>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL;
        invertTree(root->left);
        invertTree(root->right);

        TreeNode * tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        return root;
    }
};

int main(){
    Solution s;
    TreeNode * root = NULL;
    s.invertTree(root);
}
