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
    stack<TreeNode*> lRr,rRl;
    void pushAllLeft(TreeNode* cur){
        while(cur){
            lRr.push(cur);
            cur=cur->left;
        }
    }
    int next(){
        TreeNode* root=lRr.top();lRr.pop();
        pushAllLeft(root->right);
        return root->val;
    }
    void pushAllRight(TreeNode* cur){
        while(cur){
            rRl.push(cur);
            cur=cur->right;
        }
    }
    int prev(){
        TreeNode* root=rRl.top();rRl.pop();
        pushAllRight(root->left);
        return root->val;        
    }
    bool findTarget(TreeNode* root, int k) {
        pushAllLeft(root);
        pushAllRight(root);
        int low=next();
        int high=prev();
        while(low<high){
            int sum=low+high;
            if(sum==k)      return true;
            else if(sum<k)  low=next();
            else high=prev();
        }
        return false;
    }
};