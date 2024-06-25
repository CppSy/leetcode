class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>ans(2, vector<int>());
        vector<int>left;
        vector<int>right;
        for( auto i: nums1){
            auto n= find(nums2.begin(),nums2.end(),i);
            if(n ==nums2.end()){
             left.push_back(i);
            }

        }
        for( auto j: nums2){
            auto z= find(nums1.begin(),nums1.end(),j);
            if(z ==nums1.end()){
             right.push_back(j);
            }

        }
        unordered_map<int,int> freq;
        for( auto a: left){
            freq[a]++;
        }
        vector<int> f;
        for( auto b: freq){
                f.push_back(b.first);
        }
        unordered_map<int,int>fr;
        for(auto c: right){
            fr[c]++;
        }
        vector<int>r;
        for(auto d: fr){
            r.push_back(d.first);
        }
        
   ans[0]=f;
   ans[1]=(r);
   return ans;}
};