class Solution {
public:
    string sortVowels(string s) {
        
        vector<int> lower(26, 0);
        vector<int> upper(26, 0);

        // Count lowercase and uppercase vowels
        for(int i = 0; i < s.size(); i++)
        {
            // lowercase a e i o u
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
               s[i] == 'o' || s[i] == 'u')
            {
                lower[s[i] - 'a']++;
                s[i] = '#';
            }

            // uppercase A E I O U
            else if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' ||
                    s[i] == 'O' || s[i] == 'U')
            {
                upper[s[i] - 'A']++;
                s[i] = '#';
            }
        }

        string vowel;

        // Uppercase vowels in sorted order
        for(int i = 0; i < 26; i++)
        {
            char c = 'A' + i;

            while(upper[i])
            {
                vowel += c;
                upper[i]--;
            }
        }

        // Lowercase vowels in sorted order
        for(int i = 0; i < 26; i++)
        {
            char c = 'a' + i;

            while(lower[i])
            {
                vowel += c;
                lower[i]--;
            }
        }

        // Replace # with sorted vowels
        int first = 0, second = 0;

        while(second < vowel.size())
        {
            if(s[first] == '#')
            {
                s[first] = vowel[second];
                second++;
            }

            first++;
        }

        return s;
    }
};