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
    long long totalSum=0;
    long long ans=INT_MIN;
    const int MOD=1e9+7;
    long long getSum(TreeNode* root){
        if(!root)   return 0;
        long long lsum=getSum(root->left);
        long long rsum=getSum(root->right);
        long long curSum=root->val+lsum+rsum;
        ans=max(ans,(totalSum-curSum)*curSum);
        return curSum;
    }
    int maxProduct(TreeNode* root){
        if(!root)   return 0;
        totalSum=getSum(root);
        getSum(root);
        return ans%MOD;
    }
};