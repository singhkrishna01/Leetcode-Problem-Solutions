class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector <int> ans;
        vector<int>vec;
        vec=nums;
        sort(nums.begin(),nums.end());
       std::set<int> unique_numbers(nums.begin(), nums.end());

        for(int i=0;i<vec.size();i++)
        {
            for(int j=0;j<nums.size();j++)
            {
                if(vec[i]==nums[j])
                  {  ans.push_back(j);
                  break;}
            }
        }

      
       
return ans;
        
    }
};