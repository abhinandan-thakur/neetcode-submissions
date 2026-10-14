class KthLargest {
private:
    // std::queue<int> q;
    int limit;
    std::priority_queue<int, vector<int>, greater<int>> pq;
public:
    KthLargest(int k, vector<int>& nums) {
        limit = k;
        std::cout << k << std::endl << limit << std::endl;
        for(auto num : nums) {
            pq.push(num);
            if(pq.size() > limit) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        std::cout << pq.size() << std::endl << limit << std::endl;
        if(pq.size() > limit) pq.pop();
        return pq.top();
    }
};
