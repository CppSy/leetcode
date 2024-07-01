class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int odds_so_far = 0;

        for (int num : arr) {
            if (num % 2 != 0) {
                odds_so_far++;
                if (odds_so_far == 3) {
                    return true;
                }
            } else {
                odds_so_far = 0;
            }
        }
        return false;
    }
};