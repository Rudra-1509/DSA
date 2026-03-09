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
    TreeNode* helper(vector<int>& preorder,int preStart,int preEnd, 
    vector<int>& inorder,int inStart, int inEnd,unordered_map<int,int>& mpp){
        if(preStart>preEnd || inStart>inEnd)    return nullptr;
        TreeNode* newNode=new TreeNode(preorder[preStart]);
        int idxIn=mpp[newNode->val];
        int leftCount=idxIn-inStart;
        int rightCount=inEnd-idxIn;
        newNode->left=
        helper(preorder,preStart+1,preStart+leftCount,inorder,inStart,idxIn-1,mpp);
        newNode->right=
        helper(preorder,preStart+leftCount+1,preEnd,inorder,idxIn+1,inEnd,mpp);
        return newNode;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mpp;
        for(int i=0;i<inorder.size();i++)
            mpp[inorder[i]]=i;
        return helper(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mpp);
    }
};