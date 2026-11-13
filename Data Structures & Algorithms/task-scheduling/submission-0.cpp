class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> hash(26,0);
        for(auto &task: tasks) hash[task-'A']++;
        int maxFreq = *max_element(hash.begin(), hash.end());
        int maxi = 0;
        for(int h: hash) if(h == maxFreq) maxi++;
        int ans = (maxFreq-1)*(n+1)+maxi;
        return max((int)tasks.size(), ans);
    }
};
