class Solution {
public:
    int minReorder(int n, vector<vector<int>>& con) {
        vector<vector<int>> road(n),graph(n);
        for(auto i:con){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
            road[i[0]].push_back(i[1]);
        }
        queue<int>q;
        q.push(0);
        int ct=0;
        vector<int>vis(n,0);
        while(!q.empty())
        {
            int node = q.front();
            vis[node]=1;
            q.pop();
            for(auto i:graph[node]){
                if(!vis[i])
                {
                    q.push(i);
                    for(auto j:road[i])
                    if(j==node) ct--;
                    ct++;
                }
            }
        }
        return ct;
    }
};