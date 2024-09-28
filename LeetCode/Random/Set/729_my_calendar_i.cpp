class MyCalendar {
    set<pair<int, int>> schedule;

public:
    MyCalendar() { }

    bool book(int start, int end) {
        // Time: O(logn), Space: O(1)
        // now make sure the new event doesn't overlap with the previous event or the next event

        // if there is an event after the new one, it must be non-overlapping
        auto next_event = schedule.lower_bound(make_pair(start, end));
        if(next_event != schedule.end() && end > next_event->first)
            return false;

        // if there is an event before the new one, it must be non-overlapping
        if(next_event != schedule.begin()){
            auto prev_event = std::prev(next_event);
            if(start >= prev_event->first && start < prev_event->second)
                return false;
        }

        schedule.emplace(start, end);

        return true;
    }
};