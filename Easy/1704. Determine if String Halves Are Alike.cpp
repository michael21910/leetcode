class Solution {
public:
    bool halvesAreAlike(string s) {
        int count_a = 0, count_b = 0;
        for(int i = 0; i < s.length() / 2; i++){
            if((s[i] == 'a')||(s[i] == 'e')||(s[i] == 'i')||(s[i] == 'o')||(s[i] == 'u')||(s[i] == 'A')||(s[i] == 'E')||(s[i] == 'I')||(s[i] == 'O')||(s[i] == 'U')){
                count_a++;
            }
        }
        for(int i = s.length() / 2; i < s.length(); i++){
            if((s[i] == 'a')||(s[i] == 'e')||(s[i] == 'i')||(s[i] == 'o')||(s[i] == 'u')||(s[i] == 'A')||(s[i] == 'E')||(s[i] == 'I')||(s[i] == 'O')||(s[i] == 'U')){
                count_b++;
            }
        }
        return (count_a == count_b);
    }
};