class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int,int>> v;
        for(int i = 0; i < n; i++) v.push_back({nums2[i], nums1[i]});


        sort(rbegin(v), rend(v));
        priority_queue<int, vector<int>, greater<int>> pq;

        long long sum = 0, res =0;
        for(int i = 0; i<n; i++) {
            pq.push(v[i].second);
            sum += v[i].second;
            if(pq.size() > k){
                sum -=pq.top();
                pq.pop();
            }
            if(pq.size() == k) res= max(res, sum*v[i].first);
        }

        return res;
    }
};