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
    ListNode* deleteMiddle(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return NULL;

        // Count the number of nodes
        int count = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        // Find middle position
        int mid = count / 2;

        temp = head;

        // Move to the node before the middle
        for (int i = 1; i < mid; i++) {
            temp = temp->next;
        }

        // Delete the middle node
        temp->next = temp->next->next;

        return head;
    }
};