class Solution {
public:
    int longestSubarray(vector<int>& nums) {
         int result = 0;
         int i = -1 , j = -1;
         int countZero = 0 , countOne = 0;
         int n = nums.size();
         while(true){
                 if(nums[i]==1)countOne++;
                 else countZero++;

                 if(countZero > 1){
                     i--;
                     countZero--;
                     break;
                 }
                 result = max(result , countOne);
             }

             while(j < i){
                 f2 = true;
                 j++;
                 if(nums[j] == 1)countOne--;
                 else countZero--;

                 if(countZero == 0){
                     break;
                 }
             }

             if(f1 == false && f2 == false)break;
         }
         return result==n?(n-1) : result;
    }
};