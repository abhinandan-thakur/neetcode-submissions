class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while(left <= right) {
            int mid = left + (right-left)/2;
            if(nums[mid] > nums[right]) {
                // we are in the second slope
                if(target == nums[mid]) return mid;
                else if(nums[left] <= target && target < nums[mid] ) {
                    // interesting idk what to do here
                    right = mid-1;
                }
                else {
                    left = mid+1;
                }
            }
            else {
                // we are in the first slop
                if(target == nums[mid]) return mid;
                else if(target > nums[mid] && target <= nums[right]) left = mid+1;
                else right = mid-1;
            }
        }
        return -1;
    }
};
