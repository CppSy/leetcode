/* Given a string s which consists of lowercase or uppercase letters, return the length of the longest
palindrome that can be built with those letters.
Letters are case sensitive, for example, "Aa" is not considered a palindrome. */


class Solution {
public:
    int longestPalindrome(string s) {
        int oddFrequencyCount = 0;
        unordered_map<char, int> charFrequency;
        for (char ch : s) {
            charFrequency[ch]++;
            if (charFrequency[ch] % 2 == 1)
                oddFrequencyCount++;
            else
                oddFrequencyCount--;
        }
        if (oddFrequencyCount > 1)
            return s.length() - oddFrequencyCount + 1;
        return s.length();
    }
};