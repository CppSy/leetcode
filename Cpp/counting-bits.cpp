class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        ans[0] = 0;
        if(n == 0) {
            return ans;
        }
        ans[1] = 1;
        if(n== 1) {
            return ans;
        }
        ans[2] = 1;
        if(n == 2) {
            return ans;
        }
        int powerOfTwo = 2;
        for(int i=3;i<=n;i++) {
            if((i&(i-1)) == 0) {
                ans[i] = 1;
                powerOfTwo = i;
            } 
            else {
                // cout<<powerOfTwo<<"\n";
                ans[i] = ans[powerOfTwo] + ans[i%powerOfTwo];
            }
        }
        return ans;
    }
};