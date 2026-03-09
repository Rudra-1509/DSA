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
        TreeNode* cur=new TreeNode(postorder[postEnd]);
        int idxIn=mpp[cur->val];
        int leftCount=idxIn-inStart;
        cur->left=
            helper(inorder,inStart,idxIn-1,postorder,postStart,postStart+leftCount-1,mpp);
        cur->right=
            helper(inorder,idxIn+1,inEnd,postorder,postStart+leftCount,postEnd-1,mpp);
        return cur;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mpp;
        for(int i=0;i<inorder.size();i++)
            mpp[inorder[i]]=i;
        return helper(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mpp);
    }
};