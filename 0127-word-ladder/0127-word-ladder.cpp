class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n =wordList.size();
        int m = wordList[0].size();
        unordered_set<string>s(wordList.begin(),wordList.end());
        if(s.find(endWord) == s.end()) return 0;
       
        queue<string> q;
        q.push(beginWord);
        s.erase(beginWord);
        int changed = 1;

        while(!q.empty()){
            int levlength = q.size();
            for(int k =0;k<levlength;k++){
                string c = q.front();
                q.pop();
                for(int i=0;i<c.size();i++){
                    string original = c;
                    for(char x = 'a'; x<='z';x++){
                        c[i] = x;
                        if(s.find(c) != s.end()){
                            if(c == endWord){
                                changed++;
                                return changed;
                            }
                            q.push(c);
                            s.erase(c);
                        }
                    }
                    c = original;
                    
                }
            }
            changed++;
        }
        return 0;
    }
};