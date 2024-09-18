class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

        int res1=INT_MAX;
        int res2=INT_MAX;
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            if(nums[i]<=res1){
                res1=nums[i];
            }
            else{
                return true;
            }
        }
        return false;
    }
};