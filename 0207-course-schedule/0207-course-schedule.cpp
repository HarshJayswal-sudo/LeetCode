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
    bool canFinish(int n, vector<vector<int>>& edg) {
        vector<bool> vis(n, false);
        vector<bool> rec(n, false);
        for (int i = 0; i < vis.size(); i++) {
            if (!vis[i]) {
                if (helper(i, vis, rec, edg)) {
                    return false;
                }
            }
        }
        return true;
    }
};