class Solution {
public:
    int min(int x,int y){
        return (x<y)?x:y;
    }
    int calculateSteps(int n, long long curr, long long next) {
            curr *= 10;  
            next *= 10;  
        }
        return steps;
    }
    int findKthNumber(int n, int k) {
        if(n==1)    return 1;
        int curr = 1;  
        k--;  

        while (k > 0) {
            int steps = calculateSteps(n, curr, curr + 1);
            if (steps <= k) {
                curr++;
                k -= steps;
            } else {
                curr *= 10;
                k-=1;
            }
        }

        return curr;
    }
};