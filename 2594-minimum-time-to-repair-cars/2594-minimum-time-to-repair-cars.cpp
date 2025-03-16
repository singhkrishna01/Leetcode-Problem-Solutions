class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long mx=*max_element(ranks.begin(),ranks.end());
        long long l = 0;
        long long h = mx*cars*cars;
        long long ans=h;

        while(l<=h){
            long long m = l+(h-l)/2;
            for(auto ele: ranks){
                count+=sqrt(m/ele);
            }
            if(count>=cars){
                h=m-1;
                ans=min(ans,m);
            }
            else l=m+1;
        }
        return ans;
    }
};