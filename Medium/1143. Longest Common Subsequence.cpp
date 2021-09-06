class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int x = text1.length() + 1, y = text2.length() + 1;
        int arr[x][y];
        //in array prev, 0 means from uppper left, 1 means left, 2 means top.

        //init the array.
        for(int i = 0; i < x; i++){
            for(int j = 0; j < y; j++){
                arr[i][j] = 0;
            }
        }

        //do the adding
        for(int i = 1; i < x; i++){
            for(int j = 1; j < y; j++){
                if(text1[i - 1] == text2[j - 1]){
                    arr[i][j] = arr[i - 1][j - 1] + 1;
                }
                else{
                    arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
                }
            }
        }
        return (arr[x - 1][y - 1]);
    }
};