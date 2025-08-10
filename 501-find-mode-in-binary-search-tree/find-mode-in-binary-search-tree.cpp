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
    int curfreq=0;
    int maxfreq=0;
    int prev=-1;
    void inorder(TreeNode* root,vector<int>& res){
        if(!root)   return;
        inorder(root->left,res);
        if(prev==root->val)     curfreq++;
        else                    curfreq=1;
        if(curfreq>maxfreq){
            maxfreq=curfreq;
            res.clear();
            res.push_back(root->val);
        }
        else if(curfreq==maxfreq){
            res.push_back(root->val);
        }
        prev=root->val;
        inorder(root->right,res);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        inorder(root,res);
        return res;
    }
};