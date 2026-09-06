class Solution {
public:
    bool helper(int src, vector<bool>& vis, vector<bool>& rec,
                vector<vector<int>>& edg) {
        vis[src] = true;
        rec[src] = true;
        for (int i = 0; i < edg.size(); i++) {
            int u = edg[i][1];
            int v = edg[i][0];
            if (u == src) {
                if (!vis[v]) {
                    if (helper(v, vis, rec, edg)) {
                        return true;
                    }
                } else {
                    if (rec[v]) {
                        return true;
                    }
                }
            }
        }
        rec[src] = false;
        return false;
    }
    void toposort(int src, vector<bool>& vis, stack<int>& s,
                  vector<vector<int>>& edg) {
        vis[src] = true;
        for (int i = 0; i < edg.size(); i++) {
            int u = edg[i][1];
            int v = edg[i][0];
            if (u == src) {
                if (!vis[v]) {
                    toposort(v, vis, s, edg);
                }
            }
        }
        s.push(src);
    }
    vector<int> findOrder(int n, vector<vector<int>>& edg) {
        vector<bool> vis(n, false);
        vector<bool> rec(n, false);
        vector<int> ans;
        for (int i = 0; i < vis.size(); i++) {
            if (helper(i, vis, rec, edg)) {
                return ans;
            }
        }
        stack<int> s;
        vector<bool> vis2(n, false);
        for (int i = 0; i < vis2.size(); i++) {
            if(!vis2[i])toposort(i, vis2, s, edg);
        }

        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};