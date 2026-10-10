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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode *root = head;
        while(root) {
            count++;
            root = root->next;
        }

        int targetIndex = count-n+1;
        if(targetIndex == 1) return head->next;
        ListNode *iter = head;
        count = 0;
        while(iter) {
            count++;
            if(count+1 == targetIndex) {
                ListNode *toDel = iter->next;
                iter->next = toDel->next;
                toDel->next = nullptr;
                delete(toDel);
                break;
            }
            iter = iter->next;
        }
        return head;
    }
};
