#include <queue>
class MedianFinder {
   private:
    std::priority_queue<int, vector<int>, greater<>> right;
    std::priority_queue<int> left;

   public:
    MedianFinder() {}

    void addNum(int num) {
        right.push(num);

        if(!left.empty() && right.top() < left.top()) {
            left.push(right.top());
            right.pop();
        }

        int lSize = left.size();
        int rSize = right.size();
        if (lSize + 1 < rSize) {
            left.push(right.top());
            right.pop();
        }

        if(left.size() > right.size()) {
            right.push(left.top());
            left.pop();
        }
    }

    double findMedian() {
        if (right.size() > left.size()) return right.top();
        return ((double)left.top() + (double)right.top()) / 2;
    }
};
