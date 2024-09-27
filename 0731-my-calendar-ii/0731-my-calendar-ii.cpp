class MyCalendarTwo {
    map<int,int> mp;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int count = 0;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            count += (*it).second;
            if (count >= 3) {
                mp[start]--;
                mp[end]++;
                if (mp[start] == 0) {
                    mp.erase(start);
                }
                if (mp[end] == 0) {
                    mp.erase(end);
                }
                return false;
            }
        }
        return true;
    }
};