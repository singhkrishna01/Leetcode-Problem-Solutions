class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> st;
        int size = nums.size();
        int ans = 0;
        for (int i = 0; i < size; i++) {
            if (st.empty() || nums[st.top()] > nums[i]) {
                st.push(i);
            }
        }
        for (int j = size - 1; j >= 0; j--) {
            while (!st.empty() && nums[j] >= nums[st.top()]) {
                ans = max(ans, j - st.top());
                st.pop();
            }
        }

        return ans;
    }
};