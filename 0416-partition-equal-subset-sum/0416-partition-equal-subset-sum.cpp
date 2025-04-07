class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0); 
        if (totalSum % 2 != 0) return false; 
        int target = totalSum / 2; 
        vector<bool> v(target + 1, false);
        v[0] = true;  
        for(int num : nums){
            for (int j = target; j >= num; j--) { 
                v[j] = v[j] || v[j - num];
            }
        } 
        return v[target];
    }
};