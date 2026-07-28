class Solution {
public:
    string smallestPalindrome(string s) {

        vector<int> f(26, 0);

        for (char ch : s) {
            f[ch - 'a']++;
        }

        string left = "";
        string middle = "";

        for (int i = 0; i < 26; i++) {

            if (f[i] % 2 == 1) {
                middle.push_back(char(i + 'a'));
            }

            left.append(f[i] / 2, char(i + 'a'));
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + middle + right;
    }
};