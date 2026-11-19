class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char>s;
        int count =0;
        for(char i: jewels){
            s.insert(i);
        }
        for(char j: stones){
            if(s.find(j) != s.end()) count++;
        }
        return count;
    }
};