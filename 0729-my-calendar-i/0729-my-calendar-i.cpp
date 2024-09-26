class MyCalendar {
public:
    set<pair<int, int>> calender;
    MyCalendar() {}

    bool book(int start, int end) {
        auto itr = calender.lower_bound(make_pair(start, end));
        if (itr != calender.end() && itr->first < end ||
            itr != calender.begin() && prev(itr)->second > start)
            return false;
        calender.insert(make_pair(start, end));
        return true;
    }
};