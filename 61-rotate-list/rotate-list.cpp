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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || !head)   return head;
        int count=0;
        for(ListNode* ptr=head;ptr;ptr=ptr->next)   count++;
        if(k>=count)    k=k%count;
        if(k==0)    return head;
        ListNode* ptr=head;
        for(int i=0;i<count-k-1;i++)    ptr=ptr->next;
        ListNode* newHead=ptr->next;

        ptr->next=nullptr;
        ListNode* oldTail=newHead;
        while(oldTail->next)    oldTail=oldTail->next;
        
        oldTail->next=head;
        return newHead;
    }
};