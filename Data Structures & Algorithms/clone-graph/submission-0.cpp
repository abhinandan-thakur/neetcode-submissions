/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> visited;
    Node* recursion(Node *curr) {
        if(curr == nullptr) return nullptr;
        if(visited.count(curr)) return visited[curr];
        Node *curr2 = new Node(curr->val);
        visited[curr] = curr2;
        for(auto nei: curr->neighbors) {
            curr2->neighbors.push_back(recursion(nei));
        }
        return curr2;
    }
public:
    Node* cloneGraph(Node* node) {
        return recursion(node);
    }
};
