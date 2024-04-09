class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> map;
        int n1 = list1.size(), n2 = list2.size();
        for(int i = 0; i < n2; i++) {
            map[list2[i]] = i;
        }
        int minIndexSum = n1 + n2;
        vector<string> ans;
        for(int i = 0; i < n1; i++) {
            string s = list1[i];
            if(map.count(s)) {
                int indexSum = i + map[s];
                if(minIndexSum > indexSum) {
                    ans.clear();
                    minIndexSum = indexSum;
                    ans.push_back(s);
                } else if (minIndexSum == indexSum) {
                    ans.push_back(s);
                }
            }
        }
        return ans;
    }
};