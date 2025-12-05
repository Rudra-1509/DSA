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
    ListNode* rev(ListNode* head){ 
        ListNode *prev=nullptr, *cur=head; 
        while(cur){ 
            ListNode* next=cur->next; 
            cur->next=prev; 
            prev=cur; 
            cur=next; 
            } 
            return prev; 
        }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)   return nullptr;
        ListNode* cur=head;
        for(int i=0;i<k;i++){
            if(!cur)    return head;
            cur=cur->next;
        }
        ListNode* curGrpHead=head; 
        ListNode* prevGrpTail=nullptr;
        cur=head; 
        ListNode* newHead=nullptr; 
        int grpMemCount=1; 
        while(cur){ 
            if(grpMemCount==k){ 
                ListNode *nextGrpHead=cur->next; 
                cur->next=nullptr; 
                rev(curGrpHead); 
                if(prevGrpTail) prevGrpTail->next=cur; 
                else newHead=cur; 
                curGrpHead->next=nextGrpHead; 
                prevGrpTail=curGrpHead; 
                cur=curGrpHead; 
                curGrpHead=nextGrpHead; 
                grpMemCount=0; 
            } 
                cur=cur->next; 
                grpMemCount++; 
        } 
        return newHead;
    }
};