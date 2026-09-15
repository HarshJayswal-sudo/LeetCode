class Solution {
public:
    void bfs(vector<vector<int>>& image, int row, int col, int color, int n, int m, vector<vector<bool>> &vis, int oldcolor){
        image[row][col] = color;
        vis[row][col] = true;

        if(row-1>=0 && !vis[row-1][col] && image[row-1][col] == oldcolor)
        bfs(image, row-1 , col, color , n,m,vis, oldcolor);

        if(col-1>=0 && !vis[row][col-1] && image[row][col-1] == oldcolor)
        bfs(image, row , col-1, color , n,m,vis, oldcolor);

        if(row+1<n && !vis[row+1][col] && image[row+1][col] == oldcolor)
        bfs(image, row+1 , col, color , n,m,vis, oldcolor);

        if(col+1<m && !vis[row][col+1] && image[row][col+1] == oldcolor)
        bfs(image, row , col+1, color , n,m,vis, oldcolor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        bfs(image, sr , sc, color , n,m,vis, image[sr][sc]);
        return image;
    }
};