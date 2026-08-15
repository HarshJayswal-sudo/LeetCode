class Solution {
public:
    string getHint(string secret, string guess) {
        string ans;
        int bull = 0, cow = 0;
        unordered_map<char, int> s, g;
        for (int c = 0; c < secret.size(); c++) {
            if (secret[c] == guess[c])
                bull++;
            else{
                s[secret[c]]++; g[guess[c]]++;
            }
        }
        for (auto &it : g) {
            if (s.count(it.first)) {
                cow += min(it.second, s[it.first]);
            }
        }
        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};