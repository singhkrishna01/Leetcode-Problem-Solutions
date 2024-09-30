class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 1;
        int totalSum = 0;
        for (int num: nums)
        {
            totalSum += num;
        }
        int leftSum = 0;
        for (int i = 0; i < n; i++)
        {
            int rightSum = totalSum - leftSum - nums[i];
            if (leftSum == rightSum) return i;
            leftSum += nums[i];
        }
        return -1;
    }
};