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
    bool ans=false;
    bool helper(TreeNode* root1, TreeNode* root2){
        if(!root1 && !root2)    return true;
        if(!root1 || !root2)    return false;
        if(root1->val!=root2->val)  return false;
        return helper(root1->left,root2->left) && helper(root1->right,root2->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot)   return true;
        if(!root)   return false;
        if(helper(root,subRoot))    return true;
        return isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
    }
};