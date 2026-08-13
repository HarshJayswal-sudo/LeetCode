class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,int>ch;
        for(int i=0;i<s.size();i++){
            ch[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            ch[t[i]]--;
        }
        for(auto it:ch){
            if(it.second!=0) return false;
        }
        return true;
    }
};