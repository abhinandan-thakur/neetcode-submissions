class MinStack {
private:
    stack <int> sta;
    priority_queue <int, vector<int>, greater<int>> minHeap;
    multiset<int> s;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        sta.push(val);
        s.insert(val);
    }
    
    void pop() {
        int val = sta.top();
        sta.pop();
        s.erase(s.find(val));
    }
    
    int top() {
        return sta.top();
    }
    
    int getMin() {
        return *s.begin();
    }
};
