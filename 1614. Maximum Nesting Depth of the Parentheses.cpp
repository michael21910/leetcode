class Solution {
public:
    int maxDepth(string s) {
        int ans = 0, temp = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                temp++;
                if(temp > ans){
                    ans = temp;
                }
            }
            if(s[i] == ')'){
                temp--;
            }
        }
        return ans;
    }
};