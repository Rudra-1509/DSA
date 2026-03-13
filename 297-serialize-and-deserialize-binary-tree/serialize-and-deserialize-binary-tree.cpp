/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string ans="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur=q.front();
            q.pop();
            if(cur)     ans.append(to_string(cur->val)+",");
            else        ans.append("#,");
            if(cur){
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return ans; 
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)  return nullptr;
        stringstream ss(data);
        string str;
        getline(ss,str,',');
        queue<TreeNode*> q;
        TreeNode* root=new TreeNode(stoi(str));
        q.push(root);
        while(!q.empty()){
            TreeNode* cur=q.front();q.pop();

            getline(ss,str,',');
            if(str=="#")    cur->left=nullptr;
            else            cur->left=new TreeNode(stoi(str));

            getline(ss,str,',');
            if(str=="#")    cur->right=nullptr;
            else            cur->right=new TreeNode(stoi(str));

            if(cur->left)   q.push(cur->left);
            if(cur->right)   q.push(cur->right);
        }
        return root;
    }   
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));