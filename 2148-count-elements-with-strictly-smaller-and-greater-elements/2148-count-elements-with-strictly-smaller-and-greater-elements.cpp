class Solution {
public:
    int countElements(vector<int>& nums) {

        bool p,q;
        int count=0;
       for(int i=0;i<nums.size();i++)
       {  p=false;
       q=false;
        for(int j=0;j<nums.size();j++)
        {
            if(i!=j)
            {
                if(nums[j]<nums[i])
                {
                    p=true;
                }
                if(nums[j]>nums[i])
                {
                    q=true;
                }
            }

            
        }

        if(p==true && q==true)
            count++;
       }
        
      return count;
    }
};