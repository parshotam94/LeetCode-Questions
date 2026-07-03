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
    ListNode* reverse(ListNode* head){
        ListNode* curr=head, *prev=nullptr;
        while(curr){
            ListNode* nextt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextt;
        }
        return prev;
    }
    ListNode* getKthNode(ListNode* temp, int k){
        k-=1;
        while(k>0 && temp!=nullptr){
            k--;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp=head, *prevLast=nullptr;
        while(temp){
            ListNode* kth=getKthNode(temp, k);
            if(!kth){
                if(prevLast) prevLast->next=temp;
                break;
            }
            ListNode* nextNode=kth->next;
            kth->next=nullptr;
            reverse(temp);
            if(temp==head){
                head=kth;
            }
            else{
                prevLast->next=kth;
            }
            prevLast=temp;
            temp=nextNode;
        }
        return head;
    }
};