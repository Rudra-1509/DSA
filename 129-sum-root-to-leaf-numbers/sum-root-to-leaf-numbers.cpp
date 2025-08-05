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
    void helper(TreeNode* root,vector<int>& arr,int num){
        if(!root)   return;
        num=num*10+root->val;
        if(!root->left && !root->right){
            arr.push_back(num);
            return;
        }
        helper(root->left,arr,num);
        helper(root->right,arr,num);
        
    }
    int sumNumbers(TreeNode* root) {
        vector<int> arr;
        helper(root,arr,0);
        int res=0;
        for(int& num:arr)
            res+=num;
        return res;
    }
};