class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> answer(nums.size());
        int totalXor = 0;
        int maxNum = (1 << maximumBit) - 1;  
        
        for (int i = 0; i < nums.size(); ++i) {
            totalXor ^= nums[i];
            answer[nums.size() - i - 1] = totalXor ^ maxNum; 
        }
        
        return answer;
    }
};