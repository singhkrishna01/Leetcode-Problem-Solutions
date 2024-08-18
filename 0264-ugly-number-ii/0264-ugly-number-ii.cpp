class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> primes = {2, 3, 5};
        priority_queue<long, vector<long>, greater<long>> uglyHeap;
        unordered_set<long> visited;
        
        uglyHeap.push(1);
        visited.insert(1);
        
        long curr;
        for (int i = 0; i < n; ++i) {
            curr = uglyHeap.top();
            uglyHeap.pop();
           
                    visited.insert(new_ugly);
                }
            }
        }
        return (int)curr;
    }
};