class Solution {
public:
    int numTilings(int n) {
        vector<vector<long>> t(n + 1, vector<long>(n + 1, -1));
        return dfs(0, 0, t);
    }
    long dfs(int x, int y, vector<vector<long>>& t){
        if (x == t.size() - 1 && y == t.size() - 1) return 1;
        if (x >= t.size() || y >= t.size()) return 0;
        if (t[x][y] != -1) return t[x][y];
        long sum = 0;
        if (x != y){
            if (x < y)
                sum += dfs(x + 2, y, t);
            else    
                sum += dfs(x, y + 2, t);
        }
        else sum += dfs(x + 2, y + 2, t);
        if (x == y) {
            sum += dfs(x + 1, y + 1, t);
            sum += dfs(x + 1, y + 2, t);
            sum += dfs(x + 2, y + 1, t);
        }
        if (y + 1 == x + 2) sum += dfs(x + 2, y + 1, t);
        if (x + 1 == y + 2) sum += dfs(x + 1, y + 2, t);
        return t[x][y] = sum % 1000000007;
    }
};