class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int even = 0;

        for(int i = 0;i<n;i++){
            int k = 0;

            while(nums[i]>0){
                int rem = nums[i]%10;
                k++;
                nums[i]=nums[i]/10;
 
            }
            if(k%2==0){
                even++;
            }            
        }
        return even;
    }
};