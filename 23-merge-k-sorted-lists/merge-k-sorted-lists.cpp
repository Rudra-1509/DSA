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
    // ListNode* merge2Lists(ListNode* a,ListNode* b){
    //     ListNode dummy(-1);
    //     ListNode *cur1=a,*cur2=b,*cur=&dummy;
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

    // ListNode* helper(vector<ListNode*>& lists,int low,int high){
    //     if(low>high)    return nullptr;
    //     if(low==high)   return lists[low];
    //     int mid=low+(high-low)/2;
    //     ListNode* lhs=helper(lists,low,mid);
    //     ListNode* rhs=helper(lists,mid+1,high);
    //     return merge2Lists(lhs,rhs);
    // }

    // ListNode* mergeKLists(vector<ListNode*>& lists) {   
    //     return helper(lists,0,lists.size()-1);
    // }
    struct cmp{
        bool operator()(ListNode* a,ListNode*b){
            return a->val>b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) { 
        priority_queue<ListNode*,vector<ListNode*>,cmp> pq;
        for(auto ll:lists){
            if(ll)
                pq.push(ll);
        }
        ListNode dummy(-1);
        ListNode* cur=&dummy;
        while(!pq.empty()){
            ListNode* node=pq.top();pq.pop();
            cur->next=node;
            cur=cur->next;
            if(node->next)  pq.push(node->next);
        }

        return dummy.next;
    }
};