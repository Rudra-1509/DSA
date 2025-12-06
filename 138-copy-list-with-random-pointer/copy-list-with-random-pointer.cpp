/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* cur=head;
        while(cur){
            Node* newNode= new Node(cur->val);
            Node* next=cur->next;
            cur->next=newNode;
            newNode->next=next;
            cur=cur->next->next;
        }
        cur=head;
        while(cur){
            Node* randNode=cur->random;
            if(!randNode)   cur->next->random=nullptr;
            else            cur->next->random=randNode->next;
            cur=cur->next->next;
        }
        Node* dummy=new Node(-1);
        Node* newCur=dummy;
        cur=head;
        while(cur){
            Node* newNode=cur->next;
            cur->next=newNode->next;
            newCur->next=newNode;
            newCur=newCur->next;
            cur=cur->next;
        }
        return dummy->next;
    }
};