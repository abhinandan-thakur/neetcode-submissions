class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        int startIndex = 0;
        int fuel = 0;
        for(int i = 0; i < gas.size(); i++) {
            fuel = fuel + gas[i] - cost[i];
            total = total + gas[i] - cost[i];
            if(fuel < 0) {
                startIndex = i+1;
                fuel = 0;
            }
        }
        if(total < 0 ) return -1;
        return startIndex;
    }
};
