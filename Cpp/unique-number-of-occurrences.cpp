class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>maps, maps2;
        for(auto &k:arr)
            maps[k]++;
        for(auto &k:maps){
            maps2[k.second]++;
            if(maps2[k.second]>1)
                return false;
        }
        return true;
    }
};