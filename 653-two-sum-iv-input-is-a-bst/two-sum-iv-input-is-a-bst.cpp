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

class BSTiterator{
    public:
        stack<TreeNode*> st;
        bool ascend;
        BSTiterator(TreeNode* root,bool flag){
            ascend=flag;
            pushAll(root);
        }

        void pushAll(TreeNode* root){
            while(root){
                st.push(root);
                if(ascend)  root=root->left;
                else        root=root->right;
            }
        }

        int next(){
            TreeNode* temp=st.top();st.pop();
            if(ascend)  pushAll(temp->right);
            else        pushAll(temp->left);
            return temp->val;
        }
};

class Solution {
public:

    bool findTarget(TreeNode* root, int k) {
        if(!root)   return false;
        BSTiterator l(root,true);
        BSTiterator r(root,false);
        int i=l.next(),j=r.next();
        while(i<j){
            int sum=i+j;
            if(sum<k)   i=l.next();
            else if(sum>k)  j=r.next();
            else return true;
        }
        return false;
    }
};