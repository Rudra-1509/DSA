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
    // void helper(TreeNode* root,vector<int>& res){
    //     if(!root)   return;
    //     res.push_back(root->val);
    //     helper(root->left,res);
    //     helper(root->right,res);
    // }
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     helper(root,res);
    //     return res;
    // }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* cur=root;
        while(cur){
            if(!cur->left){
                res.push_back(cur->val);
                cur=cur->right;
            }
            else{
                TreeNode* rightMost=cur->left;
                while(rightMost->right && rightMost->right!=cur)
                    rightMost=rightMost->right;
                if(!rightMost->right){
                    //attach and before going to left subtree push the root
                    rightMost->right=cur;
                    res.push_back(cur->val);
                    cur=cur->left;
                }
                else{
                    //sever and go right
                    rightMost->right=nullptr;
                    cur=cur->right;
                }
            }
        }
        return res;
    }
};