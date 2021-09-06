class Solution {
public:
    bool squareIsWhite(string coordinates) {
        if((coordinates[0] - 'a') % 2){
            if((coordinates[1] - '0') % 2){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            if((coordinates[1] - '0') % 2){
                return false;
            }
            else{
                return true;
            }
        }
    }
};