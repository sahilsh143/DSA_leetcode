class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> freq(26, 0);

        // Count characters of s
        for (char c : s) {
            freq[c - 'a']++;
        }

        string ans = "";

        // Try to match target from left to right
        for (int i = 0; i < n; i++) {

            // If target[i] is available, use it
            if (freq[target[i] - 'a'] > 0) {
                ans += target[i];
                freq[target[i] - 'a']--;
            }
            else {
                // We cannot continue matching target.
                // Backtrack to find a position to make greater.
                break;
            }
        }

        // We need to construct the answer from scratch
        // using backtracking.
        freq.clear();
        freq.resize(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        for (int i = n - 1; i >= 0; i--) {

            // Use target[0...i-1] as prefix
            vector<int> temp = freq;

            bool possible = true;

            for (int j = 0; j < i; j++) {
                if (temp[target[j] - 'a'] == 0) {
                    possible = false;
                    break;
                }
                temp[target[j] - 'a']--;
            }

            if (!possible)
                continue;

            // At position i, choose smallest character
            // greater than target[i].
            for (int c = target[i] - 'a' + 1; c < 26; c++) {

                if (temp[c] > 0) {

                    string result = target.substr(0, i);

                    result += char('a' + c);
                    temp[c]--;

                    // Put remaining characters in sorted order
                    for (int x = 0; x < 26; x++) {
                        while (temp[x] > 0) {
                            result += char('a' + x);
                            temp[x]--;
                        }
                    }

                    return result;
                }
            }
        }

        return "";
    }
};