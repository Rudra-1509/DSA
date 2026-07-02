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
    ListNode* findMiddle(ListNode* head){
        if(!head || !head->next)   return head;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=nullptr;
        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=nullptr;
        return slow;
    }

    ListNode* mergeList(ListNode* a,ListNode* b){
        ListNode dummy(-1);
        ListNode *cur1=a,*cur2=b,*cur=&dummy;
        while(cur1 && cur2){
            if(cur1->val<=cur2->val){
                cur->next=cur1;
                cur1=cur1->next;
            }
            else{
                cur->next=cur2;
                cur2=cur2->next;
            }
            cur=cur->next;
        }
        if(cur1)    cur->next=cur1;
        else        cur->next=cur2;

        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)    return head;
        ListNode* mid=findMiddle(head);
        ListNode* lhs=sortList(head);
        ListNode* rhs=sortList(mid);
        return mergeList(lhs,rhs);
    }
};