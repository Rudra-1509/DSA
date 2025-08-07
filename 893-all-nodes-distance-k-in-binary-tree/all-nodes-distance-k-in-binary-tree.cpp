/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*> parents;
    unordered_set<TreeNode*> visited;
    vector<int> res;

    void storeParent(TreeNode* root,TreeNode* parent){
        if(!root)   return;
        parents[root]=parent;
        storeParent(root->left,root);
        storeParent(root->right,root);
    }
    void dfs(TreeNode* root,int lev, int k){
        if(visited.count(root) || !root)   return;
        visited.insert(root);
        if(lev==k){
            res.push_back(root->val);
            return;
        }
        dfs(root->left,lev+1,k);
        dfs(root->right,lev+1,k);
        dfs(parents[root],lev+1,k);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        storeParent(root,nullptr);
        dfs(target,0,k);
        return res;
    }
};