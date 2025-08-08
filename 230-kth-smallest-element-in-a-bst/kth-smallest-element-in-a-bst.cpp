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
    void inorder(TreeNode* root,int k,int& cur,int& ans){
        if(!root)   return;
        inorder(root->left,k,cur,ans);
        if(k==cur){
            ans=root->val;
        }
        cur++;
        inorder(root->right,k,cur,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans=-1,cur=1;
        inorder(root,k,cur,ans);
        return ans;
    }
};