
class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int x = 0, y = 0,ans = INT_MAX;
        for(auto &i: divisors){
            x = 0;
            for(auto &j: nums){
                if(j%i==0){
                    x++;
                }
            }
            
            }
        }
        return ans;
    }
};