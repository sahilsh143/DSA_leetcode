class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {

        int n = s.size();

        // 1. Count characters
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        // 2. Check whether a palindrome can be formed
        int odd = 0;
        int middle = -1;

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1) {
                odd++;
                middle = i;
            }
        }

        if (odd > 1) {
            return "";
        }

        // 3. Frequency of characters in the first half
        vector<int> halfFreq(26, 0);

        for (int i = 0; i < 26; i++) {
            halfFreq[i] = freq[i] / 2;
        }

        int halfLen = n / 2;

        // ---------------------------------------------------
        // CASE 1:
        // Try using target's first half exactly.
        // ---------------------------------------------------

        vector<int> temp = halfFreq;
        string firstHalf = "";

        bool possible = true;

        for (int i = 0; i < halfLen; i++) {

            int c = target[i] - 'a';

            if (temp[c] == 0) {
                possible = false;
                break;
            }

            firstHalf += target[i];
            temp[c]--;
        }

        if (possible) {

            // Construct palindrome
            string result = firstHalf;

            // Middle character for odd length
            if (n % 2 == 1) {
                result += char('a' + middle);
            }

            // Reverse of first half
            for (int i = halfLen - 1; i >= 0; i--) {
                result += firstHalf[i];
            }

            // Example:
            // s = "bb", target = "ba"
            // result = "bb"
            // "bb" > "ba" -> return "bb"

            if (result > target) {
                return result;
            }
        }

        // ---------------------------------------------------
        // CASE 2:
        // Make first half slightly greater than target's
        // first half.
        // ---------------------------------------------------

        for (int pos = halfLen - 1; pos >= 0; pos--) {

            temp = halfFreq;
            string prefix = "";

            bool possible = true;

            // Keep everything before pos equal to target
            for (int i = 0; i < pos; i++) {

                int c = target[i] - 'a';

                if (temp[c] == 0) {
                    possible = false;
                    break;
                }

                prefix += target[i];
                temp[c]--;
            }

            if (!possible) {
                continue;
            }

            // At pos, choose the smallest character
            // greater than target[pos]
            for (int c = target[pos] - 'a' + 1; c < 26; c++) {

                if (temp[c] == 0) {
                    continue;
                }

                string newHalf = prefix;

                newHalf += char('a' + c);

                temp[c]--;

                // Put remaining characters in sorted order
                for (int x = 0; x < 26; x++) {
                    while (temp[x] > 0) {
                        newHalf += char('a' + x);
                        temp[x]--;
                    }
                }

                // Build complete palindrome
                string result = newHalf;

                // Middle character
                if (n % 2 == 1) {
                    result += char('a' + middle);
                }

                // Reverse first half
                for (int i = halfLen - 1; i >= 0; i--) {
                    result += newHalf[i];
                }

                return result;
            }
        }

        return "";
    }
};