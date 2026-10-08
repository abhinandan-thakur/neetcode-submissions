class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int RL = matrix.size();
        int CL = matrix[0].size();
        vector<int> rows(matrix.size(), 0);
        for(int row = 0; row < RL; row++) rows[row] = matrix[row][CL-1];

        auto it = lower_bound(rows.begin(), rows.end(), target);
        // the number is greater than the last element
        if(it == rows.end()) return false;
        int index = it-rows.begin();
        auto it2 = lower_bound(matrix[index].begin(), matrix[index].end(), target);
        if(it2 == matrix[index].end()) return false;
        if(*it2 == target) return true;
        return false;
        // well so there is a o(n) sollution i guess though mine implementation seems meh...
    }
};
/*
there are two ways first convert the 2d into one but that needs a n^2 iteration
second store all the first elements of each in a 1d matrix do lowerbound to find the index where it can
then do lower bound on that row if we can find anything or not
i think the second approach is om nothing more though i can be wrong but i think it is much optimized though i can do this question 
on^2 too...
*/
