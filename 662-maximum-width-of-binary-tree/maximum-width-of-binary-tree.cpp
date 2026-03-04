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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>> q;
        int ans=0;
        q.push({root,0});
        while(!q.empty()){
            int sz=q.size();
            long long start=q.front().second;
            long long end=q.back().second;
            long long diff=end-start+1;
            ans=max(ans,(int)diff);
            for(int i=0;i<sz;i++){
                TreeNode* cur=q.front().first;
                long long ind=q.front().second;
                ind-=start;
                q.pop();
                if(cur->left)   q.push({cur->left,2*ind+1});
                if(cur->right)   q.push({cur->right,2*ind+2});
            }
        }
        return ans;
    }
};