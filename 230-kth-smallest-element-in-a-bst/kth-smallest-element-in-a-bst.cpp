/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* cur=root;
        int ans=-1;
        while(cur){
            if(!cur->left){
                    if(!--k)    ans= cur->val;
                    cur=cur->right;
            }
            else{
                TreeNode* rightMost=cur->left;
                while(rightMost->right && rightMost->right!=cur)
                    rightMost=rightMost->right;
                if(rightMost->right){
                    rightMost->right=nullptr;
                    if(!--k)    ans= cur->val;
                    cur=cur->right;
                }
                else{
                    rightMost->right=cur;
                    cur=cur->left;
                }
            }
        }
        return ans;
    }
};