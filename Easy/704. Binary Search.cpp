class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums[lower_bound(nums.begin(), nums.end(), target) - nums.begin()] == target){
            return (lower_bound(nums.begin(), nums.end(), target) - nums.begin());
        }
        return -1;
    }
};