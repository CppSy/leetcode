class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>> q;
        int n=grid.size();int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                }
            }
        }
        int maxtime=0;
        while(!q.empty()){
            pair<int,pair<int,int>> p1=q.front();
            q.pop();
            int t=p1.first;
            int x=p1.second.first;
            int y=p1.second.second;
            if(x>0 && grid[x-1][y]==1){
                grid[x-1][y]=2;
                q.push({t+1,{x-1,y}});
            }
            if(y>0 && grid[x][y-1]==1){
                grid[x][y-1]=2;
                q.push({t+1,{x,y-1}});
            }
            if(x<n-1 && grid[x+1][y]==1){
                grid[x+1][y]=2;
                q.push({t+1,{x+1,y}});
            }
            if(y<m-1 && grid[x][y+1]==1){
                grid[x][y+1]=2;
                q.push({t+1,{x,y+1}});
            }
            maxtime=max(maxtime,t);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return maxtime;
    }
};