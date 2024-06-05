/*
Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.
 
Example 1:

Input: words = ["bella","label","roller"]
Output: ["e","l","l"]

Example 2:

Input: words = ["cool","lock","cook"]
Output: ["c","o"]

*/
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        array<char, 26> freq, minFreq;
        minFreq.fill(100);
        for(auto& w: words){
            freq.fill(0);
            for(char c: w) freq[c-'a']++;
            for(int i=0; i<26; i++)
                minFreq[i]=min(freq[i], minFreq[i]);
        }
        vector<string> ans;
        for(int i=0; i<26; i++){
            for(int j=0; j<minFreq[i]; j++)
                ans.push_back(string(1, i+'a'));
        }
        return ans;
    }
};



auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();