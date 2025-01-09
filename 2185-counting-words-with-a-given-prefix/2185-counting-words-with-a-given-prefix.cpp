class Solution {
public:
    int prefixCount(const std::vector<std::string>& words, const std::string& pref) {
        int cnt = 0;
        for (const auto& word : words) {
            if (word.rfind(pref, 0) == 0) {
                cnt++;
            }
        }
        return cnt;
    }
};