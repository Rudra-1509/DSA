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
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head,*fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *prev=nullptr, *cur=slow;
        while(cur){
            ListNode* next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        ListNode *ptr1=head, *ptr2=prev;
        while(ptr1 && ptr2){
            if(ptr1->val !=ptr2->val)   return false;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        return true;
    }
};