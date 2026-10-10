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
    void reorderList(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = head;
        while(slow && fast->next && fast->next->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *head2 = slow->next;
        slow->next = nullptr;
        ListNode *head1 = head;

        prev = nullptr;
        while(head2) {
            ListNode *front = head2->next;
            head2->next = prev;
            prev = head2;
            head2 = front;
        }

        head2 = prev;
        while(head2) {
            ListNode *front = head1->next;
            head1->next = head2;
            head1 = head2;
            head2 = head2->next;
            head1->next = front;
            head1 = front;
            if(!head1) break;
        }
    }
};
