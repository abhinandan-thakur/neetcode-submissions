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
    ListNode *target = nullptr;
    pair<ListNode*, ListNode*> reverse(ListNode *head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        for(int i = 0; i < k; i++) {
            ListNode *front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        head->next = target;
        return {prev, head};
        
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int i = 0;
        this->k = k;
        int count = 0;
        ListNode *prevTail = nullptr;
        int revCnt = 0;
        ListNode *ans = head;
        while(head) {
            bool checker = false;
            ListNode *d = head;
            int count = 0;
            while(d) {
                count++;
                if(count >= k) {
                    checker = true;
                    target = d->next;
                    break;
                }
                d = d->next;
            }
            if(!checker) break;
            auto [a, b] = reverse(head);
            // revCnt++;
            // if(revCnt == 1) {
            //     ans = a;
            // }
            // head = b->next;
            if(!prevTail) ans = a;                     // first group decides the head
            else prevTail->next = a;                   // fix 1: connect groups
            prevTail = b;
            head = b->next;
        }
        return ans;
    }
};
