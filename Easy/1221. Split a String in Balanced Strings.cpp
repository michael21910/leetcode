class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0, temp = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'R'){
                temp++;
            }
            else{
                temp--;
            }
            if(temp == 0){
                ans++;
            }
        }
        return ans;
    }
};