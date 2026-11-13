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
        priority_queue<ListNode*,vector<ListNode*>,decltype(cmp)> pq(cmp);
        for(auto *head : lists) if(head) pq.push(head);
        ListNode dummy(-1);
        ListNode *node = &dummy;
        while(!pq.empty()) 
        {
            auto curr = pq.top(); pq.pop();
            node->next = curr;
            node = node->next;
            if(curr->next) pq.push(curr->next);
        }
        return dummy.next;
    }
};
