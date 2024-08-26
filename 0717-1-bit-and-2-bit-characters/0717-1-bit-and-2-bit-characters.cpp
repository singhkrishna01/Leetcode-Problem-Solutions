class Solution {
public:
    bool isOneBitCharacter(vector<int>& b) {
        return (b.size() == 1 or rbegin(b)[1] == 0) ? 1 : distance(find(rbegin(b) + 1, rend(b), 0), rbegin(b)) % 2;
    }
};