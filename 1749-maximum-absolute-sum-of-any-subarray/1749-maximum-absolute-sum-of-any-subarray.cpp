class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();
        int minNeg=INT_MAX;
        int maxPos=INT_MIN;
        int sum=0;
        for(int it:nums)
        {
            sum+=it;
            minNeg=min(minNeg,sum);
            maxPos=max(maxPos,sum);
        }
        if(maxPos>=0 && minNeg<=0) return maxPos-minNeg;
        if(maxPos<0) return abs(minNeg);
        if(minNeg>0) return maxPos;
        return -1;
    }
};