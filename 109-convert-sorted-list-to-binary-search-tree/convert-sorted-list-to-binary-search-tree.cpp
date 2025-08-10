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
    ListNode* findMiddle(ListNode* head){
        if(!head)   return nullptr;
        ListNode *slow=head,*fast=head,*prev=nullptr;
        while(fast && fast->next){
            fast=fast->next->next;
            prev=slow;
            slow=slow->next;
        }
        if(prev) prev->next=nullptr;
        return slow;
    }
    TreeNode* helper(ListNode* head){
        if(!head)   return nullptr;
        ListNode* mid=findMiddle(head);
        TreeNode* root=new TreeNode(mid->val);
        root->left=(head==mid)?nullptr:helper(head);
        root->right=helper(mid->next);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        return helper(head);
    }
};