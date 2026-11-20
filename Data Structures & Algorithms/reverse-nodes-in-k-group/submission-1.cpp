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
private:
    int k;
    void reverse(ListNode *back, ListNode *curr) {
        ListNode *start = curr;
        ListNode *prev = nullptr;
        int count = 0;
        while(curr && count < k) {
            ListNode *nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            count++;
        }
        start->next = curr;
        back->next = prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        this->k = k;
        ListNode dummy(-1);
        dummy.next = head;
        int cnt = 0;
        ListNode *bck = &dummy;
        ListNode *curr = nullptr;
        while(head) {
            ListNode *nxt = head->next;
            if(cnt == 0) {
                curr = head;
            }
            else if(cnt == k-1) {
                reverse(bck, curr);
                bck = curr;
            }
            cnt = (cnt+1)%k;
            head = nxt;

        }
        return dummy.next;
    }
};
/*
so reverse function should return its bottom and top because it top need to be connected to next
and its bottom be connected to previoius

*/