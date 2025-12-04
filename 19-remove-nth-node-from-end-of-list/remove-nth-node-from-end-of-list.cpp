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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* ptr=dummy;
        int count=0;
        for(ListNode* cur=head;cur;cur=cur->next)   count++;
        int jumpsReq=count-n;
        for(int i=0;i<jumpsReq;i++)     ptr=ptr->next;
        if(ptr->next)   ptr->next=ptr->next->next;
        else            ptr->next=nullptr;
        return dummy->next;
    }
};