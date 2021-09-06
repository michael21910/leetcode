class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0, temp = 0;
        for(int i = 0; i < gain.size(); i++){
            temp += gain[i];
            ans = max(ans, temp);
        }
        return ans;
    }
};