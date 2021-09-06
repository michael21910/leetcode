class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> output;
        for(int i = 0; i < nums.size(); i++){
            bool isFinished = false;
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    output.push_back(i);
                    output.push_back(j);
                    isFinished = !isFinished;
                    break;
                }
            }
            if(isFinished){
                break;
            }
        }
        return output;
    }
};