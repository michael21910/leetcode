class Solution {
public:
    bool isPerfectSquare(int num) {
        long long int n = 1, Num = 1;
        while(num >= Num){
            if(num == Num){
                return true;
            }
            n++;
            Num = n * n;
        }
        return false;
    }
};