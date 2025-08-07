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
    void bfs(TreeNode* root,int k){
        queue<TreeNode*> q;
        int dist=0;
        q.push(root);
        visited.insert(root);
        while(!q.empty()){
            int size=q.size();
            if(dist==k) break;
            for(int i=0;i<size;i++){
                TreeNode* cur=q.front();q.pop();
                for(TreeNode* neighbour:{cur->left,cur->right,parents[cur]}){
                    if(neighbour && !visited.count(neighbour)){
                        q.push(neighbour);
                        visited.insert(neighbour);
                    }
                }
            }
            dist++;
        }

        while(!q.empty()){
            res.push_back(q.front()->val);
            q.pop();
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        storeParent(root,nullptr);
        //dfs(target,0,k);
        bfs(target,k);
        return res;
    }
};