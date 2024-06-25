class Solution {
public:
    bool check(vector<int> one,vector<int> two){
        sort(one.begin(),one.end());
        sort(two.begin(),two.end());
        for(int i=0;i<one.size();i++){
            if(one[i]!=two[i]){
                return false;
            }
        }
        return true;
    }
    bool check2(int count1[26],int count2[26]){
        for(int i=0;i<26;i++){
            if((count1[i]==0 && count2[i]>0)||(count1[i]>0 && count2[i]==0)){
            return false;                
            }
        }
        return true;
    }
    bool closeStrings(string word1, string word2) {
        if(word1.length()!=word2.length()){
            return false;
        }
        vector<int> one;
        vector<int> two;
        int count1[26]={0};
        int count2[26]={0};
        for(int i=0;i<word1.length();i++){
            int a=word1[i]-'a';
            int b=word2[i]-'a';
            count1[a]++;
            count2[b]++;
        }
        for(int i=0;i<26;i++){
            if(count1[i]!=0){
                one.push_back(count1[i]);
            }
            if(count2[i]!=0){
                two.push_back(count2[i]);
            }
        }
        bool ans=check(one,two)&&check2(count1,count2);
        return ans;
    }
};