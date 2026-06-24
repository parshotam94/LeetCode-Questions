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
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, int>mpp;
        ListNode* curr=head;
        while(curr!=nullptr){
            if(mpp.find(curr)!=mpp.end()){
                return true;
            }
            mpp[curr]=1;
            curr=curr->next;
        }
        return false;
    }
};