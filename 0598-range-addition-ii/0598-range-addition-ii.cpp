class Solution {
public:
   int maxCount(int m, int n, vector<vector<int>>& ops) {
    int mnr = m, mnc = n;
    for(auto o: ops){ 
        mnr = min(mnr, o[0]);
        mnc = min(mnc, o[1]);
    }
    return mnr * mnc;
}
};