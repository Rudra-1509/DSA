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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(-1);
        ListNode* cur1=l1;
        ListNode* cur2=l2;
        ListNode* cur=dummy;
        int carry=0;
        while(cur1 || cur2 || carry){
            int val1=cur1? cur1->val: 0;
            int val2=cur2? cur2->val: 0;
            int sum=val1+val2+carry;
            carry=sum/10;
            sum=sum%10;
            cur->next=new ListNode(sum);
            cur=cur->next;
            if(cur1)  cur1=cur1->next;
            if(cur2)  cur2=cur2->next;
        }
        return dummy->next;   
    }
};