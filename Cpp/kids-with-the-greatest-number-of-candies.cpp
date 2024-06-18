class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        //int arr[];
        int count=0;
        vector<bool> isgreat;
        int max=INT_MIN;

        
        for(int i=0;i<candies.size();i++){
            if(candies[i]>max){
                max=candies[i];
            }
        }
        for(int i=0;i<candies.size();i++){
            count=extraCandies+candies[i];{
            
                if(count>=max){
                    isgreat.push_back(true);
                }
                else{
                   isgreat.push_back(false);
                }
            }
           
        }
        
        return isgreat;
    }
    
};