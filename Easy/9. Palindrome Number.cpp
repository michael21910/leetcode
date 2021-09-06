class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        string intToString = to_string(x), compare;
        for(int i = intToString.length() - 1; i >= 0; i--){
            compare.push_back(intToString[i]);
        }
        if(intToString == compare){
            return true;
        }
        return false;
    }
};