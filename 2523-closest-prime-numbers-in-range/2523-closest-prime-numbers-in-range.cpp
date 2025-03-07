
class Solution {
    private : 
    bool isprime(int n){
        if( n == 1 ) return false;
        if(n == 2) return true;
        if( n%2==0) return false;

        for(int i=3;i*i<=n;i+=2){
            if(n%i==0) return false;
        }
        return true;
    }
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int>res;
        vector<int>val;
        for(int i=left;i<=right;i++){
            if(isprime(i)){
                val.push_back(i);
            }
        }
        if(val.size() < 2){
            return {-1,-1};
        }
        int mindiff = INT_MAX;
        pair<int,int>closestpair;
        for(int i=0;i<val.size()-1;i++){
            int diff = val[i+1] - val[i];
            if( diff < mindiff){
                mindiff = diff;
                closestpair = {val[i] , val[i+1]};
            }
        }
        return {closestpair.first , closestpair.second};
    }
};