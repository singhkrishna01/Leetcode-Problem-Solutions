class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
    int n = nums.size();
    int max_sum = 0;

    for (int i = 0; i < n; ++i) {
        int current_sum = 0;
        for (int j = i; j < n; ++j) {
            current_sum += nums[j];
            max_sum = max(max_sum, abs(current_sum));
        }
    }

    return max_sum;
}
};