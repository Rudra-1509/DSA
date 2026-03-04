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
    TreeNode* helper(int& ind,vector<int>& preorder,int ub=INT_MAX){
        if(ind>=preorder.size() || preorder[ind]>ub)    return nullptr;    
        TreeNode* newNode=new TreeNode(preorder[ind]);
        ind++;
        newNode->left=helper(ind,preorder,newNode->val);
        newNode->right=helper(ind,preorder,ub);
        return newNode;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ind=0;
        TreeNode* root=helper(ind,preorder);
        return root;
    }
};