class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        vector<int>res;
        int n=potions.size();
        sort(potions.begin(),potions.end());
        for(auto itr:spells)
        {
            int l=0;
            int h=n-1;
            int a=-1;
            while(l<=h)
            {
                int mid=(l+h)/2;
                if(potions[mid]*1ll*itr>=success)
                {
                    a=mid;
                    h=mid-1;
                }
                else
                    l=mid+1;
            }
            if(a==-1)
                res.push_back(0);
            else
                res.push_back(n-a);
        }
        return res;
    }
};