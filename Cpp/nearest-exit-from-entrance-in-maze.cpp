class Solution {
private:
    void bfs(vector<vector<char>>& maze, int& i, int& j, vector<vector<bool>>& visited, int& ans, queue<pair<int, int>>& q) {
        vector<int> row = {-1, 0, 1, 0};
        vector<int> col = {0, 1, 0, -1};
        int n = maze.size();
        int m = maze[0].size();
        int count = 0;

        while (!q.empty()) {
            int size = q.size();
            count++;
            for (int i = 0; i < size; i++) {
                pair<int, int> p = q.front(); 
                q.pop(); 
                int a = p.first;
                int b = p.second;

                for (int k = 0; k < 4; k++) {
                    int new_row = a + row[k];
                    int new_col = b + col[k];
                    
                    if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m && !visited[new_row][new_col] && maze[new_row][new_col] == '.') {
                        if (new_row == 0 || new_row == n - 1 || new_col == 0 || new_col == m - 1) {
                            ans = count;
                            return;
                        }
                        visited[new_row][new_col] = true;
                        q.push({new_row, new_col});
                    }
                }
            }
        }
    }

public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int i = entrance[0];
        int j = entrance[1];
        int n = maze.size();
        int m = maze[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        visited[i][j] = true;

        int ans = -1; // Use -1 to indicate no exit found
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        bfs(maze, i, j, visited, ans, q);

        return ans;
    }
};
