class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map<char,int>mmp;
        if(s.length()<k)
        return 0;
        for(auto it:s)
        {
                mmp[it]++;
        }
        if(mmp.size()==k)
        return 1;
        int cnt=0;
        for(auto it:mmp)
        if(it.second%2!=0)
        {
            cnt++;
        }
        if(cnt<=k)
        return 1;
        else return 0;
        

    }
};