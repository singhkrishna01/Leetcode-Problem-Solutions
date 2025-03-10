class Solution {
public:

    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        int maxi = items[0][1];
        for(auto &xt : items)
        {
            maxi = max(maxi , xt[1]);
            xt[1] = maxi;
        }
        vector<int>ans;
        int n = items.size();
        
        for(int key : queries){
            int left = 0;
            int right = n - 1;

            int count = 0;

            while (left <= right) {
                int mid = (right + left) / 2;
                if (items[mid][0] <= key) {
                    count = mid + 1;
                    left = mid + 1;
                }
                else
                    right = mid - 1;
            }
            
            if(count==0)
                ans.push_back(0);
            else
                ans.push_back(items[count-1][1]);
        }
        return ans;
    }
};