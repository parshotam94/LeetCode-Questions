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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *d1=list1;
        ListNode *d2=list2;
        ListNode *dummy=new ListNode(-1);
        ListNode *temp=dummy;
        while(d1 && d2){
            if(d1->val<=d2->val){
                temp->next=d1;
                d1=d1->next;
            }
            else{
                temp->next=d2;
                d2=d2->next;
            }
            temp=temp->next;
        }
        if(d1){
            temp->next=d1;
        }
        if(d2){
            temp->next=d2;
        }
        return dummy->next;
    }
};