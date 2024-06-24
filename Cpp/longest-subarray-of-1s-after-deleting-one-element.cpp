class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int count = 0;
        int maxValue = 0;
        int backup = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 1) {
                count++;
            } else {
                maxValue = max(maxValue, count);
                count -= backup;
                backup = count;
            }
        }
        maxValue = max(maxValue, count);
        return maxValue == nums.size() ? maxValue-1 : maxValue;
    }
};