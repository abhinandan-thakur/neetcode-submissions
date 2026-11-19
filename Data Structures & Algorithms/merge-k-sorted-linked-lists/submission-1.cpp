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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode *a, ListNode *b){
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> min_heap;
        for(auto list: lists) {
            while(list) {
                min_heap.push(list);
                list = list->next;
            }
        }
        ListNode dummy(-1);
        ListNode *curr = &dummy;
        while(!min_heap.empty()) {
            curr->next = min_heap.top(); min_heap.pop();
            curr = curr->next;
        }
        return dummy.next;
    }
};
