class Solution {
public:
    long long coloredCells(int n) {
        long long nthMiddleRow= 1+(n-1)*2;
        long long ans=0;
        for(long long i=1;i<nthMiddleRow;i+=2){
            ans+=i;
        }
        ans*=2;
        ans+=nthMiddleRow;
        return ans;
    }
};