class Solution {
public:
    int minimizedStringLength(string s) {
        
        unordered_set<char>mp;
        for(char ch: s){
            mp.insert(ch);
        }
      return mp.size();
    }
};