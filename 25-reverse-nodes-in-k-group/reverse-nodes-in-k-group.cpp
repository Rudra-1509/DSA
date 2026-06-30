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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(-1);
        ListNode* prevGrpEnd=&dummy;
        dummy.next=head;
        ListNode* curGrpHead=head;
        ListNode* kth=head;
        while(1){
            for(int i=0;i<k-1 && kth;i++)    kth=kth->next;
            if(!kth)    break;
            ListNode* nextGrpHead=kth->next;
            ListNode* cur=curGrpHead;
            ListNode* prev=nextGrpHead;
            while(cur!=nextGrpHead){
                ListNode* next=cur->next;
                cur->next=prev;
                prev=cur;
                cur=next;
            }
            prevGrpEnd->next=kth;
            prevGrpEnd=curGrpHead;
            curGrpHead=nextGrpHead;
            kth=nextGrpHead;
        }
        return dummy.next;
    }
};