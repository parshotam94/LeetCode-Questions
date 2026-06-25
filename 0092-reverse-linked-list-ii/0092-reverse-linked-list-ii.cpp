class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* nextt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextt;
        }
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right)
            return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prevLeft = &dummy;

        // Move prevLeft to node before 'left'
        for (int i = 1; i < left; i++) {
            prevLeft = prevLeft->next;
        }

        ListNode* leftNode = prevLeft->next;
        ListNode* rightNode = leftNode;

        // Move rightNode to position 'right'
        for (int i = left; i < right; i++) {
            rightNode = rightNode->next;
        }

        ListNode* afterRight = rightNode->next;

        // Detach sublist
        rightNode->next = nullptr;

        // Reverse sublist
        ListNode* newHead = reverse(leftNode);

        // Reconnect
        prevLeft->next = newHead;
        leftNode->next = afterRight;

        return dummy.next;
    }
};