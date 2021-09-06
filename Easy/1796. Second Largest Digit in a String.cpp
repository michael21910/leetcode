class Solution {
public:
    int secondHighest(string s) {
        int count[10] = {0};
        for(int i = 0; i < s.length(); i++){
            if(s[i] >= '0' && s[i] <= '9'){
                count[ s[i] - '0' ]++;
            }
        }
        int counting = 0, ans;
        for(int i = 9; i >= 0; i--){
            if(count[i] != 0){
                counting++;
                if(counting == 2){
                    ans = i;
                    break;
                }
            }
        }
        return ans;
    }
};