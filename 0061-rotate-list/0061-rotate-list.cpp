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
        if(!head || !head->next) return head;
        int len=0;
        ListNode *curr=head;
        while(curr){
            curr=curr->next;
            len+=1;
        }
        k=k%len;
        if(k==0) return head;
        int rotate=len-k;
        curr=head;
        for(int i=1;i<rotate;i++){
            curr=curr->next;
        }
        ListNode *temp=curr->next;
        ListNode *dummy=temp;
        curr->next=nullptr;
        while(temp && temp->next){
            temp=temp->next;
        }
        temp->next=head;
        return dummy;
    }
};