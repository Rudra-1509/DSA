class NumArray {
private:
    struct node{
        int sum;
        int start;
        int end;
        node* left;
        node* right;
        node(int s,int e){
            start=s;end=e;
            sum = 0;
            left = nullptr;
            right = nullptr;
        }
    };

    node* root;
    node* builder(vector<int>& nums,int l,int r){
        node* newnode=new node(l,r);
        if(l==r){
            newnode->sum=nums[l];
            return newnode;
        }
        int mid=l+(r-l)/2;
        node* lhs=builder(nums,l,mid);
        node* rhs=builder(nums,mid+1,r);
        newnode->left=lhs;
        newnode->right=rhs;
        newnode->sum=lhs->sum+rhs->sum;
        return newnode;
    }

    int sumRange(node* root,int l,int r){
        if(!root)   return 0;
        if(r<root->start || l>root->end)   return 0;
        if(root->start>=l && root->end<=r)  return root->sum;
        int lhs=sumRange(root->left,l,r);
        int rhs=sumRange(root->right,l,r);
        return lhs+rhs;
    }

    int update(node* root,int index,int val){
        if(!root)   return 0;
        if(index<root->start || index>root->end)    return root->sum;
        if(root->start==root->end){
            root->sum=val;
            return val;
        }
        int lhs=update(root->left,index,val);
        int rhs=update(root->right,index,val);
        root->sum=lhs+rhs;
        return lhs+rhs;
    }

public:
    NumArray(vector<int>& nums) { 
        if(nums.empty())    root=nullptr;
        else    root=builder(nums,0,nums.size()-1);
    }
    
    void update(int index, int val) {
        update(root,index,val);
    }
    
    int sumRange(int left, int right) {
        return sumRange(root,left,right);   
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */