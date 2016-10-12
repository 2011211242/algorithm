#include <cstdio>
#include <queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root == NULL)return res;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            res.push_back(que.front() -> val);
            for(int i = que.size(); i > 0; i--){
                root = que.front();
                que.pop();
                if(root -> left) que.push(root -> left);
                if(root -> right) que.push(root -> right);
            }
        }
        return res;
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    Solution s;
    vector <int> res = s.rightSideView(root);
    for(int i = 0; i < res.size(); i++)printf("%d ", res[i]);
    printf("\n");
}
