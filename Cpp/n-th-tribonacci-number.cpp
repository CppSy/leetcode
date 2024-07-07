class Solution {
public:

    int recg(int n) {
        if (n <= 1) // base case
            return n;
        if (n == 2) // base case
            return 1;


        return recg(n - 1) + recg(n - 2) + recg(n - 3);
    }
    int tribonacci(int n) {

        return recg(n);

    }
};
