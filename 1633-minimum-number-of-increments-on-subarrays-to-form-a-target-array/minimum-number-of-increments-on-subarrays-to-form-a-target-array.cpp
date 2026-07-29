// struct node{
//     int start;
//     int end;
//     int val;
//     int index;
//     node* left;
//     node* right;
//     node(int s,int e){
//         start=s;end=e;left=right=nullptr;
//     }
// };
// class SegmentTree {
// private:
//     node* root;
//     node* buildTree(int l,int r,const vector<int>& arr){
//         if(l>r) return nullptr;
//         node* newNode=new node(l,r);
//         if(l==r){
//             newNode->val=arr[l];
//             newNode->index=l;
//             return newNode;
//         }
//         int mid=l+(r-l)/2;
//         newNode->left=buildTree(l,mid,arr);
//         newNode->right=buildTree(mid+1,r,arr);
//         if(newNode->left->val<=newNode->right->val){
//             newNode->val=newNode->left->val;
//             newNode->index=newNode->left->index;
//         }
//         else{
//             newNode->val=newNode->right->val;
//             newNode->index=newNode->right->index;
//         }
        
//         return newNode;
//     }
//     pair<int,int> query(node* root,int l,int r){
//         if(!root || l>r)    return {INT_MAX,-1};
//         if(l>root->end || r<root->start)    return {INT_MAX,-1};
//         if(root->start>=l && root->end<=r)  return {root->val,root->index};
//         pair<int,int> lhs=query(root->left,l,r);
//         pair<int,int> rhs=query(root->right,l,r);
//         if(lhs.first<=rhs.first)    return lhs;
//         else    return rhs;
//     }

// public:
//     SegmentTree(const vector<int>& arr){
//         int n=arr.size();
//         if(n==0)   root=nullptr;
//         else       root=buildTree(0,n-1,arr);
//     }
//     pair<int,int> query(int l,int r){
//         return query(root,l,r);
//     }
// };

// class Solution {
// public:
//     int helper(int l,int r,SegmentTree st,int base){
//         if(l>r) return 0;
//         auto [mini,idx]=st.query(l,r);
//         return (mini-base)+helper(l,idx-1,st,mini)+helper(idx+1,r,st,mini);    
//     }
//     int minNumberOperations(vector<int>& target) {
//         int ans=0,n=target.size();
//         SegmentTree st(target);
//         ans=helper(0,n-1,st,0);
//         return ans;
//     }
// };


class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans=target[0];
        for(int i=1;i<target.size();i++){
            ans+=max(0,target[i]-target[i-1]);
        }
        return ans;
    }
};