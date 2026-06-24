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
    bool isPalindrome(ListNode* head) {
        stack<int>st;
        string ans="";
        ListNode *temp=head;
        while(temp){
            st.push(temp->val);
            ans+=(temp->val)+'0';
            temp=temp->next;
        }
        string res="";
        while(!st.empty()){
            res+=st.top()+'0';
            st.pop();
        }
        return res==ans;
    }
};