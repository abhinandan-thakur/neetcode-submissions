class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool x,y,z;
        x = y = z = false;
        for(int i = 0; i < triplets.size(); i++) {
            if(triplets[i][0] > target[0]) continue;
            if(triplets[i][1] > target[1]) continue;
            if(triplets[i][2] > target[2]) continue;
            if(triplets[i][0] == target[0]) x = true;
            if(triplets[i][1] == target[1]) y = true;
            if(triplets[i][2] == target[2]) z = true;
        }
        return x && y && z;
    }
};
