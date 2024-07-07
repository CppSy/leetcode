class Solution {
public:

    int dp[40];

    int recg(int n) {
        if (n <= 1) // base case
            return n;
        if (n == 2) // base case
            return 1;

        if (dp[n] != -1) // dp
            return dp[n];

        return dp[n] = 
                recg(n - 1) + recg(n - 2) + recg(n - 3);
    }
    int tribonacci(int n) {

        memset(dp, -1, sizeof(dp));

        return recg(n);

    }
};