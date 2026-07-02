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
    // string serialize(TreeNode* root,vector<TreeNode*>& res,unordered_map<string,int>& mpp){
    //     if(!root)   return "#";
    //     string lhs=serialize(root->left,res,mpp);
    //     string rhs=serialize(root->right,res,mpp);
    //     string cur=to_string(root->val)+',' + lhs + ',' + rhs;
    //     if(++mpp[cur]==2)  res.push_back(root);
    //     return cur;
    // }

    // vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    //     vector<TreeNode*> res;
    //     unordered_map<string,int> mpp;
    //     serialize(root,res,mpp);
    //     return res;
    // }
    unordered_map<int,int> frq;
    unordered_map<string,int> subTree;
    vector<TreeNode*> res;
    int Id=1;
    int dfs(TreeNode* root){
        if(!root)   return 0;
        int lhs=dfs(root->left);
        int rhs=dfs(root->right);
        string key=to_string(root->val)+","+to_string(lhs)+","+to_string(rhs);
        if(!subTree.count(key))
            subTree[key] = Id++;
        int curId=subTree[key];
        if(++frq[curId]==2)    res.push_back(root);
        return curId; 
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return res;
    }
};