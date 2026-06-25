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
    ListNode *reverse(ListNode *temp){
        ListNode *curr=temp,*prev=nullptr;
        while(curr){
            ListNode *nextt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextt;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode *slow=head;
        ListNode *fast=head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *temp=slow->next;
        slow->next=nullptr;
        ListNode *rev=reverse(temp);
        slow=head;
        int maxSum=0;
        while(slow!=nullptr){
            if(slow->val+rev->val > maxSum){
                maxSum=slow->val+rev->val;
            }
            slow=slow->next;
            rev=rev->next;
        }
        return maxSum;
    }
};