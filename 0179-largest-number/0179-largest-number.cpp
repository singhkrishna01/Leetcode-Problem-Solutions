class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto cmp =[&](int a , int b ){
            return (to_string(a)+to_string(b))>(to_string(b)+to_string(a));
        };

        sort(nums.begin(), nums.end(), cmp);
        string ans = "";
        for(auto it :nums){
           
        }   
        return ans[0]=='0'?"0":ans ;
    }
};