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
    bool isValidBST(TreeNode* root,long long maxi=LLONG_MAX,long long mini=LLONG_MIN) {
        if(!root)   return true;
        if(!(root->val<maxi && root->val>mini)) return false;
        bool leftside=isValidBST(root->left,root->val,mini);
        bool rightside=isValidBST(root->right,maxi,root->val);
        return leftside && rightside;
    }
};