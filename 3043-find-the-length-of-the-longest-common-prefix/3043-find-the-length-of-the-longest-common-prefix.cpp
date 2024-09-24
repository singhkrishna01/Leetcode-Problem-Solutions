class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>mp;
        for(int i = 0 ; i < arr2.size() ; i++) {
            int x = arr2[i];
            while(x > 0) {
                mp[x] = 1;
                x/=10;
            }
        }
        int ans = 0;
        int maxi = 0;
        for(int i = 0 ; i < arr1.size() ; i++) {
            int x = arr1[i];
            if(x > maxi) {
                while(x > 0) {
                maxi = x;
                int count = 0;
                if(mp[x] == 1) {
                    while(x > 0) {
                        count++;
                        x/=10;
                    }
                }
                ans = max(ans,count);
                x/=10;
            }
        }
        }
        return ans;
    }
};