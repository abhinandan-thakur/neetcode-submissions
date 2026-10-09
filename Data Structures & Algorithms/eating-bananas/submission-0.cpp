class Solution {
private:
    vector<int> piles;
    int getTimeTaken(int speed) {
        int hoursTaken = 0;
        for(int pile: piles) hoursTaken += (pile+speed-1)/speed;
        return hoursTaken;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        this->piles = piles;
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int mid = -1;
        while(left < right) {
            mid = left + (right-left)/2;
            int time = getTimeTaken(mid);
            if(time <= h) {
                // so we should reduce speed therefore decrease right
                right = mid;
            }
            else {
                // timetaken is > h so we should increase speed therefore increase left
                left = mid+1;
            }
        }
        return left;
    }
};
