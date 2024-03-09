
class NumberContainers {
public:
    unordered_map<int,set<int>> mp;
    unordered_map<int,int> mp1;
    NumberContainers() {
        
    }
    void change(int idx, int n) {
        if(mp1.count(idx)){
            int val=mp1[idx];
            mp[val].erase(idx);
            if(!mp[val].empty())
                mp1[*mp[val].begin()]=val;
        }
        mp1[idx]=n;
        mp[n].insert(idx);
    }
    
    int find(int n) {
        return mp[n].empty()?-1:*mp[n].begin();
    }
};