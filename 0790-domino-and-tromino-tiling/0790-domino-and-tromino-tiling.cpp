class Solution 
{
public:
    int numTilings(int n) 
    {
        int MOD = 1e9 + 7;
        if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
         
        vector<long long> a(n + 1);
        a[0] = 1;
        a[1] = 1;
        a[2] = 2;

        for(int i=3; i <= n; i++){
            a[i] = (2 * a[i - 1] + a[i - 3]) % MOD;
        }

    return a[n];
    }

};