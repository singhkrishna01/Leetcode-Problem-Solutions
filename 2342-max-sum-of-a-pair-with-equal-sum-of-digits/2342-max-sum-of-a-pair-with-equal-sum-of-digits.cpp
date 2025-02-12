#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> hash;
        int res = -1;

        for(int num : nums){
            int digSum = getDigitSum(num);

            if(hash.count(digSum)){
                res = max(res, num + hash[digSum]);
                hash[digSum] = max(num, hash[digSum]);
            } else {
                hash[digSum] = num;
            }
        }
        return res;
    }

    int getDigitSum(int n){
        int res = 0;
        while(n > 0){
            res += n % 10;
            n /= 10;
        }        
        return res;
    }
};