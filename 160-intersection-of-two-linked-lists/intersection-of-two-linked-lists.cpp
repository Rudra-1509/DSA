/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
     int c1=0,c2=0;
     ListNode* ptr1=headA;
     ListNode* ptr2=headB;
     while(ptr1 || ptr2){
        if(ptr1){
            c1++;ptr1=ptr1->next;
        }
        if(ptr2){
            c2++;ptr2=ptr2->next;
        }
     }
     int diff=abs(c1-c2);
     ptr1=headA;
     ptr2=headB;
     if(c1>c2){
        for(int i=0;i<diff;i++) ptr1=ptr1->next;
     }
     else{
        for(int i=0;i<diff;i++) ptr2=ptr2->next;
     }
     while(ptr1!=ptr2){
        if(!ptr1 && !ptr2)  return nullptr;
        ptr1=ptr1->next;
        ptr2=ptr2->next;
     }
     return ptr1;
    }
};