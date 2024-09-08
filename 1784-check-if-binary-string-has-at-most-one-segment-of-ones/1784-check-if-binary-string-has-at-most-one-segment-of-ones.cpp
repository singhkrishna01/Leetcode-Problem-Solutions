class Solution {
public:
    bool checkOnesSegment(string s) {
        int countZero = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='0')
                countZero = 1;
            else if(countZero && s[i]=='1')
                return false;
        }
        return true;
    }
};