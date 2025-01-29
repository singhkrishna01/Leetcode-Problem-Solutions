class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int prefSum = nums[0] , currSum = nums[0];
        for(int i=1;i<n;i++){
            currSum += nums[i];
            ans = max({ans , currSum , currSum - prefSum});
            prefSum = min(prefSum , currSum);
        }
        return ans;
    }
};