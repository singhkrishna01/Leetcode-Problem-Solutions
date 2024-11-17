class Solution {
public:
    int t[101];
    int helper(vector<int> & nums, int size, int index){

        if(index >= size)
            return 0;
        if(t[index] != -1) return t[index];
        int op1 = nums[index] + helper(nums, size, index + 2);
        int op2 = helper(nums, size, index + 1);

        return t[index] = max(op1, op2);
    }
    int rob(vector<int>& nums) {
        int size = nums.size();
        memset(t, -1, sizeof(t));
        return helper(nums, size, 0);
        
    }
};