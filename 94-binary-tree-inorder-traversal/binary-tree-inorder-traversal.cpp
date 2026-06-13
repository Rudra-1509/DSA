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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* cur=root;
        while(cur){
            if(cur->left){
                TreeNode* rightMost=cur->left;
                while(rightMost->right && rightMost->right!=cur)
                    rightMost=rightMost->right;
                if(rightMost->right){
                    rightMost->right=nullptr;
                    res.push_back(cur->val);
                    cur=cur->right;
                }
                else{
                    rightMost->right=cur;
                    cur=cur->left;
                }     
            }
            else{
                res.push_back(cur->val);
                cur=cur->right;
            }
        }
        return res;
    }
};