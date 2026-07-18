class MyCalendarTwo {
public:

    vector<pair<int,int>> booked;
    vector<pair<int,int>> overlaps;

    MyCalendarTwo() {

    }

    bool book(int start, int end) {

        // Step 1
        for(auto &p : overlaps)
        {
            if(max(start,p.first) < min(end,p.second))
                return false;
        }

        // Step 2
        for(auto &p : booked)
        {
            int s = max(start,p.first);
            int e = min(end,p.second);

            if(s < e)
                overlaps.push_back({s,e});
        }

        // Step 3
        booked.push_back({start,end});

        return true;
    }
};