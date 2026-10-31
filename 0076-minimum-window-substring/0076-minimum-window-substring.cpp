class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size()) return "";
        unordered_map<char,int> mp;
        for(int i=0;i<t.size();i++){
            mp[t[i]]++;
        } 
        int totalchar = t.length();
        int start = 0;
        int minLen = INT_MAX;
        int stidx = 0;
        for(int endidx = 0; endidx<s.length();endidx++){
            char ch = s[endidx];
            if(mp.find(ch) != mp.end() && mp[ch] > 0){
                totalchar--;
            }
            mp[ch]--;
            if(totalchar == 0){
                while(true){
                    char charst = s[stidx];
                    if (mp.find(charst) != mp.end() && mp[charst] == 0) {
                        break;
                    }
                    mp[charst]++;
                    stidx++;

                }
                if(endidx - stidx + 1 < minLen){
                    minLen = endidx - stidx + 1;
                    start = stidx;
                }
                mp[s[stidx]]++;
                totalchar++;
                stidx++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);      
        
    }
};