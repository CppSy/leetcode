class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        priority_queue<int,vector<int>,greater<>> pq1;
        priority_queue<int,vector<int>,greater<>> pq2;
        for (int i=0;i<candidates;i++){
            pq1.push(costs[i]);
        }
        for (int i=n-1;i>=n-candidates && i >= candidates ;i--){
            pq2.push(costs[i]);
        }
        int cursor1 =candidates;
        int cursor2 = n-candidates-1;
        long long cost =0;
        while (k--){
            int a = INT_MAX;
            int b =INT_MAX;
            if (!pq1.empty()) a =pq1.top();
            if (!pq2.empty())b =pq2.top();
            if (a<=b){
                cost +=a;
                pq1.pop();
                if (cursor1<=cursor2){
                    pq1.push(costs[cursor1]);
                    cursor1++;
                }
            }else{
                cost +=b;
                pq2.pop();
                if (cursor1<=cursor2){
                    pq2.push(costs[cursor2]);
                    cursor2--;
                }
            }
        }
        return cost;
        

    }
};