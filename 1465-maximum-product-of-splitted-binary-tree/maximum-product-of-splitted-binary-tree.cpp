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
    const int MOD=1e9+7;
    long long getSum(TreeNode* root,long long& totalSum,long long& ans){
        if(!root)   return 0;
        long long lsum=getSum(root->left,totalSum,ans);
        long long rsum=getSum(root->right,totalSum,ans);
        long long curSum=root->val+lsum+rsum;
        ans=max(ans,(totalSum-curSum)*curSum);
        return curSum;
    }
    int maxProduct(TreeNode* root){
        if(!root)   return 0;
        long long totalSum=0;
        long long ans=INT_MIN;
        totalSum=getSum(root,totalSum,ans);
        getSum(root,totalSum,ans);
        return ans%MOD;
    }
};