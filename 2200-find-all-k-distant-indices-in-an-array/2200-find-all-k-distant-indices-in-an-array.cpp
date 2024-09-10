class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k){
        vector<int> result;
        int n = nums.size();
        vector<int> keyIndices;
        for (int i = 0; i < n;i++){
            if (nums[i] == key) {
                keyIndices.push_back(i);
            }
        }
        int n1 = keyIndices.size() ;
        int j = 0; 
        for(int i = 0; i < n;i++){
            while(j < n1 && i > keyIndices[j] + k){
                j++;
            }
            if (j < n1 && i >= keyIndices[j] - k && i <= keyIndices[j] + k) {
                result.push_back(i);
            }
        }

        return result;
    }
};