class Solution {
public:

    string roman(int n) {
        if(n == 1)
            return "I";
        else if(n == 5)
            return "V";
        else if(n == 10)
            return "X";
        else if(n == 50)
            return "L";
        else if(n == 100)
            return "C";
        else if(n == 500)
            return "D";
        else
            return "M";
    }

    string intToRoman(int num) {

        string ans;

        int value[] = {
            1000, 900, 500, 400,
            100, 90, 50, 40,
            10, 9, 5, 4, 1
        };

        string symbol[] = {
            "M", "CM", "D", "CD",
            "C", "XC", "L", "XL",
            "X", "IX", "V", "IV", "I"
        };

        for(int i = 0; i < 13; i++) {

            while(num >= value[i]) {

                ans += symbol[i];

                num -= value[i];
            }
        }

        return ans;
    }
};