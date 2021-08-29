class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        vector<int> vec;
        int ans = 0;
        for(int i = 0; i < rectangles.size(); i++){
            vec.push_back( min(rectangles[i][0], rectangles[i][1]) );
        }
        sort(vec.begin(), vec.end());
        int arr[vec.size()], target = vec[ vec.size() - 1 ];
        for(int i = vec.size() - 1; i >= 0; i--){
            if(vec[i] == target){
                ans++;
            }
            else{
                break;
            }
        }
        return ans;
    }
};