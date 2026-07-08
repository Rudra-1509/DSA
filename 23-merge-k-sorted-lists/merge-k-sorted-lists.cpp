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
    // ListNode* merge2lists(ListNode* a,ListNode*  b){
    //     ListNode dummy(-1);
    //     ListNode *cur1=a, *cur2=b, *cur=&dummy;
    //     while(cur1 && cur2){
    //         if(cur1->val<=cur2->val){
    //             cur->next=cur1;
    //             cur1=cur1->next;
    //         }
    //         else{
    //             cur->next=cur2;
    //             cur2=cur2->next;
    //         }
    //         cur=cur->next;
    //     }
    //     if(cur1)    cur->next=cur1;
    //     else        cur->next=cur2;
    
    //     return dummy.next;
    // }

    // ListNode* helper(vector<ListNode*>& lists,int l,int r){
    //     if(l>r) return nullptr;
    //     if(l==r)    return lists[l];
    //     int m=l+(r-l)/2;
    //     ListNode* lhs=helper(lists,l,m);
    //     ListNode* rhs=helper(lists,m+1,r);
    //     return merge2lists(lhs,rhs);
    // }

    // ListNode* mergeKLists(vector<ListNode*>& lists) { 
    //     int n=lists.size();
    //     return helper(lists,0,n-1);
    // }

    struct cmp{
        bool operator()(ListNode* a,ListNode* b){
            return a->val>b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) { 
        priority_queue<ListNode*,vector<ListNode*>,cmp> pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i])    pq.push(lists[i]);
        }
        ListNode dummy(-1);
        ListNode* ptr=&dummy;
        while(!pq.empty()){
            ListNode* cur=pq.top();pq.pop();
            ptr->next=cur;
            ptr=ptr->next;
            if(cur->next)   pq.push(cur->next);   
        }
        return dummy.next;
    }
};