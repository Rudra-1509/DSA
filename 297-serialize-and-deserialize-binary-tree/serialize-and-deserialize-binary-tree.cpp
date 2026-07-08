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
private:
    const int null= 1001;
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)   return "#";
        string lhs=serialize(root->left);        
        string rhs=serialize(root->right);
        string key=to_string(root->val)+','+lhs+','+rhs;
        return key;
    }
    vector<int> seperate(string data){
        vector<int> res;
        stringstream ss(data);
        string cur;
        while(getline(ss,cur,',')){
            if(cur=="#")    res.push_back(null);
            else    res.push_back(stoi(cur));
        }
        return res;
    }
    TreeNode* helper(vector<int>& arr,int& ind){
        if(arr[ind]==null || ind>=arr.size())  return nullptr;
        TreeNode* cur=new TreeNode(arr[ind]);
        cur->left=helper(arr,++ind);
        cur->right=helper(arr,++ind);
        return cur;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> arr=seperate(data);
        int ind=0;
        return helper(arr,ind);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));