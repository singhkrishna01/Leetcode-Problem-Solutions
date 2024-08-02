class Solution {
public:
    int totalMoney(int n) {
        //ans= sigma(1+2+3+4+5+6+7)+7+14+....+(xi+..+xn).
        if(n<=7)return n*(n+1)/2;
        int x=28;
        int weeks=n/7;
        //int f_nth_week=1+weeks;
        int remain=n-weeks*7;
        int t1=x*weeks+7*(weeks*(weeks-1))/2;
        // 2*(f_nth_week)==1+weeks .
        // Formula for Sum of A.p.=(2*a+(n-1)*d)*n/2;
        int t2=(2*weeks+remain+1)*remain/2;
        return t1+t2;
    }
};