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
    string serialize(TreeNode* root,vector<TreeNode*>& res,unordered_map<string,int>& mpp){
        if(!root)   return "#";
        string lhs=serialize(root->left,res,mpp);
        string rhs=serialize(root->right,res,mpp);
        string cur=to_string(root->val)+',' + lhs + ',' + rhs;
        if(++mpp[cur]==2)  res.push_back(root);
        return cur;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        unordered_map<string,int> mpp;
        serialize(root,res,mpp);
        return res;
    }
};