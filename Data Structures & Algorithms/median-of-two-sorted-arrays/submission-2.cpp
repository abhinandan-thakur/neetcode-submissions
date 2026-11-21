class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if(a.size() > b.size()) return findMedianSortedArrays(b, a);
        int m = a.size();
        int n = b.size();
        int low = 0, high = m;
        int size = (m+n+1)/2;
        while(low <= high) {
            int index1 = low + (high-low)/2;
            int index2 = size-index1;
            int al = (index1 == 0) ? INT_MIN: a[index1-1];
            int ar = (index1 == m) ? INT_MAX: a[index1];
            int bl = (index2 == 0) ? INT_MIN: b[index2-1];
            int br = (index2 == n) ? INT_MAX: b[index2];
            if(al <= br && bl <= ar) {
                if((m+n)%2) return max(al,bl);
                else return (max(al,bl)+min(ar,br))/2.0;
            }
            if(al > br) high = index1-1; 
            else low = index1+1;
        }
        return 0.0;
    }
};
