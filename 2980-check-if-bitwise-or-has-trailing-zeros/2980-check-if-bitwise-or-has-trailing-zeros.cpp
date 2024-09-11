class Solution {
public:
     Solution(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

        bool hasTrailingZeros(vector<int> &nums)
{
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (!(nums[i] & 1))
        {
            ans++;
        }
        if (ans > 1)
        {
            return true;
        }
    }
    return false;
}
    
};