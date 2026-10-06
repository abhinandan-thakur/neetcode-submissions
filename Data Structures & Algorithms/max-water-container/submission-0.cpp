class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size()-1;
        int maxima = 0;
        while(left < right) {
            maxima = max(maxima, min(heights[left], heights[right])*(right-left));
            if(heights[right] < heights[left]) right--;
            else left++;
        }
        return maxima;
    }
};
/*
mono or 2p
if i start by choosing the next greater element ir next smaller it will not work 
take 2 pointer with a greedy approach from left and right 
move the smaller to the centre and store there area in a maxima;

*/
