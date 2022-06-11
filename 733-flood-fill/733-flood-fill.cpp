class Solution {
private:
    void DFS(vector<vector<int>>& image, int i, int j, int newColor, int baseColor){
        int rows = image.size();
        int cols = image[0].size();
        
        if(i < 0 || j < 0 || i >= rows || j >= cols || image[i][j] == newColor || image[i][j] != baseColor )
            return;
        
        image[i][j]=newColor;
        DFS(image, i-1, j, newColor, baseColor); //up
        DFS(image, i, j-1, newColor, baseColor); //left
        DFS(image, i+1, j, newColor, baseColor); //right
        DFS(image, i, j+1, newColor, baseColor); //down
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        DFS(image,sr,sc,newColor,image[sr][sc]);
        return image;
    }
};