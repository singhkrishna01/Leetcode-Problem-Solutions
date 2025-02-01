class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int con=1,n=nums.size(); 
        if(nums[0]&1)con=0; 
        else con=1;
        for(int i=1;i<n;++i){
          if(!con and nums[i]%2==0){
             con^=1;   
          }  
          else if(con and nums[i]&1){
            con^=1;
          }
          else return false;
        }
        return true;
    }
};