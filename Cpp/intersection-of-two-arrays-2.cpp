class Solution {
public:
    static vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size()>nums2.size()) return intersect(nums2, nums1);
        unordered_map<int, int> freq;
        int sz=nums1.size();
        freq.reserve(sz);
        for(int x: nums1) freq[x]++;
        vector<int> ans;
        ans.reserve(sz);
        for(int x: nums2){
            if (freq[x]-->0) ans.push_back(x);
        }
        return ans;   
    }
};



auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();