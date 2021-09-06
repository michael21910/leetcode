class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int i = 0, j = 0;
        while(i < word1.length() && j < word2.length()){
            ans = ans + word1[i++] + word2[j++];
        }
        while(i < word1.length()){
            ans = ans + word1[i++];
        }
        while(j < word2.length()){
            ans = ans + word2[j++];
        }
        return ans;
    }
};