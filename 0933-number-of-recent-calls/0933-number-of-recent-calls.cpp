// Method 1 - using map - bad TC
// class RecentCounter {
// public:
//     unordered_map<int,int> m;
//     RecentCounter() {
        
//     }
    
//     int ping(int t) {
//         m[t]++;

//         int ans = 0;

//         int lower = t - 3000, upper = t;
//         for(auto &x : m){
//             if(x.first >= lower && x.second <= upper){
//                 ans = ans + x.second;
//             }
//         }
//         return ans;
//     }
// };


// Method 2 - using deque - best Time complexity
class RecentCounter {
public:
    queue<int> q;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        // we should keep only t-3000 time elements in queue
        int lower = t - 3000;
        // pop all unecessary items
        while(!q.empty() && lower > q.front()){
            q.pop();
        }

        q.push(t);
        // current size of queue
        return q.size();
    }
};



/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */