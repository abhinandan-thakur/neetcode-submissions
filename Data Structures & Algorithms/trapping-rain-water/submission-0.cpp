class Solution {
   public:
    int trap(vector<int>& height) {
        stack<int> mono;
        int water = 0;
        for(int i = 0; i < height.size(); i++) {
            while(!mono.empty() && height[i] > height[mono.top()]) {
                int bottom = height[mono.top()];
                mono.pop();
                if(mono.empty()) break;
                int hei = min(height[mono.top()], height[i]) - bottom;
                int width = i-mono.top()-1;
                water += hei*width;
            }
            mono.push(i);
        }
        return water;
    }
};

/*
so we can use a mono stack to find the next greater or equal and when we find one we get the
but i have an interesting idea what about lower bound
lower bound on 0 we get 2
lowerbound 2 we get 3 find area
lower bound 3 we get 3 find area
lower bound on 3 we get end so nothing
but the thing is way easier if we have the values of the bumps which are taking up space
how about a prefix vector
012345678 9  10
00225667 10 12
now the question is when i do lowerbound on 3 at 3 index and get a response of 3 at 7 index
vector at 7 is 7 and vec aat 4 is 5
so it can work is it faster

okay back to mono
iterate though the vector looking for the next greater or equal element or should i look for the next smaller element pr qual element
*/
