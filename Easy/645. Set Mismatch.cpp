class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int r = nums.size() - 1, l = 0;
        while (l < r) {
            if (nums[r] == r + 1){
                r--;
            }
            else if (nums[l] == l + 1){
                l++;
            }
            else if (nums[l] == nums[ nums[l] - 1 ]){
                swap(nums[l], nums[r]);
            }
            else{
                swap(nums[l], nums[ nums[l] - 1 ]);
            }
        }
        return {nums[l], l + 1};
    }
};