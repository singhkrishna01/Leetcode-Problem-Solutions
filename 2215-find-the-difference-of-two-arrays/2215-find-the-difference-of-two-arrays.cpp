class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>v;
        unordered_map<int,int>mp;
        for(int i=0;i<nums2.size();i++)
        {
            mp[nums2[i]]=1;
        }
        vector<int>va;
        for(int i=0;i<nums1.size();i++)
        {
            int a=nums1[i];
            if(mp[a]<1)
            {
                va.push_back(a);
            }      
            mp[a]=2;     
        }
        v.push_back(va);
        va.clear();
        for(int i=0;i<nums2.size();i++)
        {
            int a=nums2[i];
            if(mp[a]<2)
            {
                va.push_back(a);
            } 
            mp[a]=3;
        }
        v.push_back(va);
        return v;
    }
};