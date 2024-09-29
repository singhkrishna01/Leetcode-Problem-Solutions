class Solution {
public:
    int largestAltitude(vector<int>& g) {
        for(int i = 0, s = 0; i < g.size() && ((g[0] = max(g[0], s += g[i])) || 1); i++);
        return max(g[0], 0);
    }
};