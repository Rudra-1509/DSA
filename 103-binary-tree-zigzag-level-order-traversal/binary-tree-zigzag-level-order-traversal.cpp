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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) { 
        if(!root)   return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        bool left2right=true;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            deque<int> lev;
            while(sz--){
                TreeNode* cur=q.front();q.pop();
                if(left2right)  lev.push_back(cur->val);
                else            lev.push_front(cur->val);
                if(cur->left)   q.push(cur->left);
                if(cur->right)   q.push(cur->right);
            }
            left2right=!left2right;
            res.push_back(vector<int> (lev.begin(),lev.end()));
        }
        return res;
    }
};