class Solution {
public:
    int numberOfCuts(int n) {
        if(n == 1) // no cuts, the whole cake is just 1
            return 0;
        if(n % 2)
            return n;
        return n / 2;
    }
};