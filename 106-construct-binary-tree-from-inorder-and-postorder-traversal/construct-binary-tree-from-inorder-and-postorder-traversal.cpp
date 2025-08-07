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
    TreeNode* helper(vector<int>& inorder,int inStart,int inEnd,
    vector<int>& postorder,int postStart,int postEnd,unordered_map<int,int>& mpp){
        if(inStart>inEnd || postStart>postEnd)  return nullptr;
        TreeNode* root=new TreeNode(postorder[postEnd]);
        int rootIdxIn=mpp[root->val];
        int numsRight=inEnd-rootIdxIn;
        root->left=helper(inorder,inStart,rootIdxIn-1,postorder,postStart,postEnd-numsRight-1,mpp);
        root->right=helper(inorder,rootIdxIn+1,inEnd,postorder,postEnd-numsRight,postEnd-1,mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mpp;
        for(int i=0;i<inorder.size();i++)
            mpp[inorder[i]]=i;
        return helper(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mpp);
    }
};