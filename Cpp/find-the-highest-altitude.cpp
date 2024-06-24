class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int hi = 0, alt = 0;
        for(int i=0; i < n; i++){
            alt += gain[i];
            hi = max(hi, alt);
        }
        return hi;
    }
};