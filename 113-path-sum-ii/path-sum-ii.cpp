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
    void helper(TreeNode* root, int targetSum,vector<vector<int>>& result,vector<int>& path){
        if(!root)   return;
        path.push_back(root->val);
        if(root->val==targetSum && !root->left && !root->right){
            result.push_back(path);
        }
        else{
        helper(root->left,targetSum-root->val,result,path);
        helper(root->right,targetSum-root->val,result,path);
        }
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path;
        helper(root,targetSum,result,path);
        return result;
    }
};