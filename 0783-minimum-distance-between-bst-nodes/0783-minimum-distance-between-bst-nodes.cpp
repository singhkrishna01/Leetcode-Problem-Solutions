
#define Node TreeNode
using ll = long long; 
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        ll ans = INT_MAX ; 
        function<pair<ll,ll>(Node*)> dfs = [&](Node* root) -> pair<ll,ll>{
            if (!root) return {INT_MAX, INT_MIN};
            auto [leftMin, leftMax] = dfs(root->left); 
            auto [rightMin, rightMax] = dfs(root->right);
            ans = min({ans, abs(leftMax - root->val), abs(rightMin - root->val)}); 
            return {min(leftMin, (ll)root->val), max(rightMax, (ll)root->val)}; 
        };
        dfs(root); 
        return ans ; 
    }
};