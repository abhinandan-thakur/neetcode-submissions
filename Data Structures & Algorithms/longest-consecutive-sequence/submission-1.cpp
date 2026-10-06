class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        int length = 0;
        int prev = 0;
        int curr = 0;
        for(auto num: s) {
            cout << num << ",";
            if(curr == 0 || (curr > 0 && prev+1 == num)) {
                curr++;
                prev = num;
                length = max(length, curr);
            }
            else {
                prev = num;
                curr = 1;
            }
        }
        return length;
    }
};
/*
sorting is one solution
but it will give tle
my memory is stil screamimg lower_bound or upperbound
but lets us see other ways how about dp maybe byt sorting will be better than that i guess
create a set of the vector and convert it into vector again
then reduce all the values by minima
*/