class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        // Store reserved seats of each row
        unordered_map<int, set<int>> reserved;

        for (auto &x : reservedSeats) {
            int row = x[0];
            int seat = x[1];

            reserved[row].insert(seat);
        }

        // Every completely empty row can have 2 groups
        int ans = 2 * n;

        // Check only rows which have reserved seats
        for (auto &x : reserved) {

            int row = x.first;
            set<int> seats = x.second;

            // This row was counted as 2 groups initially.
            // We will calculate it again.
            ans -= 2;

            // Check block 2,3,4,5
            bool left = true;

            for (int seat = 2; seat <= 5; seat++) {
                if (seats.count(seat)) {
                    left = false;
                    break;
                }
            }

            // Check block 4,5,6,7
            bool middle = true;

            for (int seat = 4; seat <= 7; seat++) {
                if (seats.count(seat)) {
                    middle = false;
                    break;
                }
            }

            // Check block 6,7,8,9
            bool right = true;

            for (int seat = 6; seat <= 9; seat++) {
                if (seats.count(seat)) {
                    right = false;
                    break;
                }
            }

            // Both left and right can be used
            if (left && right) {
                ans += 2;
            }

            // Otherwise, at least one block can be used
            else if (left || middle || right) {
                ans += 1;
            }
        }

        return ans;
    }
};