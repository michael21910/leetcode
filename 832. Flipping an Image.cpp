class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        vector<vector<int>> ans(image.size(), vector<int>(image.size(), 0));
        for(int i = 0; i < image.size(); i++){
            for(int j = image[i].size() - 1; j >= 0; j--){
                ans[i][image[i].size() - j - 1] = (!(image[i][j]));
            }
        }
        return ans;
    }
};