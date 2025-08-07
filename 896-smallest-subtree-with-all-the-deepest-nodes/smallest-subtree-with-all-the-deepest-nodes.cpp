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
    TreeNode* LCA(TreeNode* root,TreeNode* p, TreeNode* q){
        if(!root||root==p||root==q) return root;
        TreeNode* left=LCA(root->left,p,q);
        TreeNode* right=LCA(root->right,p,q);
        if(!left && !right) return nullptr;
        if(!left)   return right;
        if(!right)  return left;
        return root;
    }
    int height(TreeNode* root){
        if(!root)   return 0;
        int lh=height(root->left);
        int rh=height(root->right);
        return 1+max(lh,rh);
    }


    void helper(TreeNode* root,int curLev,int maxHeight,vector<TreeNode*>& vec){
        if(!root)   return;
        helper(root->left,curLev+1,maxHeight,vec);
        helper(root->right,curLev+1,maxHeight,vec);
        if(curLev==maxHeight)
            vec.push_back(root);
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        vector<TreeNode*> vec;
        int maxHeight=height(root);
        helper(root,1,maxHeight,vec);
        TreeNode* p=vec[0];
        TreeNode* q=vec[vec.size()-1];
        return LCA(root,p,q);
    }
};