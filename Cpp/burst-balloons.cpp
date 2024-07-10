class Solution {
public:
    static bool compare(pair<int,int>& a,pair<int,int>& b)
    {
        return a.second>b.second;
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();

        priority_queue<pair<int,int>,vector<pair<int,int>>, decltype(&compare)> pq(&compare);
        for(int i=0;i<n;i++)
        {
            pq.push({points[i][0],points[i][1]});
        }

        int point = -1;
        int ans = 0;

        while(!pq.empty())
        {
            
            auto itr = pq.top();
            pq.pop();

            if(point==-1)
            {
                point = itr.second;
                ans++;
            }
            else
            {
                if(itr.first<=point) continue;
                else 
                {
                    point = itr.second;
                    ans++;
                }
            }
        }
        return ans;
    }
};