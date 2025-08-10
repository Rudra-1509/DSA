/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* helper(ListNode*& head,int left,int right){
        if(left>right)  return nullptr;
        int mid=left+(right-left)/2;
        TreeNode* leftSide=helper(head,left,mid-1);
        TreeNode* root=new TreeNode(head->val);
        root->left=leftSide;
        head=head->next;
        root->right=helper(head,mid+1,right);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int size=0;
        for(ListNode* cur=head;cur;cur=cur->next)
            size++;
        return helper(head,0,size-1);
    }
};