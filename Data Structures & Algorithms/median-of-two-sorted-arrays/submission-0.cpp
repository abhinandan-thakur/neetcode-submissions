class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // lets try a min heap  maxheap solution insetad of a binary solution  though one thing
        // will a bs be faster
        // do binary search find middle of both l1,l2, r1,r2 something like that we need to pivout the segments and then make sure
        priority_queue<int, vector<int>, greater<>> right;
        priority_queue<int> left;
        for(int i = 0; i < nums1.size(); i++) {
            if(left.empty() && right.empty()) right.push(nums1[i]);
            else if(nums1[i] < right.top()) left.push(nums1[i]);
            else right.push(nums1[i]);

            if(left.size() >= right.size()+1) {
                right.push(left.top());
                left.pop();
            }
            if(right.size() >= left.size()+2) {
                left.push(right.top());
                right.pop();
            }
        }
        for(int i = 0; i < nums2.size(); i++) {
            if(left.empty() && right.empty()) right.push(nums2[i]);
            else if(nums2[i] < right.top()) left.push(nums2[i]);
            else right.push(nums2[i]);

            if(left.size() >= right.size()+1) {
                right.push(left.top());
                left.pop();
            }
            if(right.size() >= left.size()+2) {
                left.push(right.top());
                right.pop();
            }
        }
        if(right.size() == left.size()) return ((double)left.top()+right.top())/2.0;
        return right.top();
        

    }
};
