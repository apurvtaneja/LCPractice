```
class Solution {
private:
unordered_set<int> cols;     //for Columns
unordered_set<int> negDiag;  //for negative diagnals R-C
unordered_set<int> posDiag;  //for positive diagnals R+C
void backtrack(int n, int row, vector<vector<string>>& res, vector<string>& board){
if(row==n){
res.push_back(board);
return ;
}
for(int col = 0; col < n; col++){   //Shifting through each col
if( cols.find(col) != cols.end() or //If queen alread placed in this col
negDiag.find(row - col) != negDiag.end() or //If queen in negDiag
posDiag.find(row + col) != posDiag.end()    //If queen in posDiag
)
continue;
cols.insert(col);
negDiag.insert(row - col);
posDiag.insert(row + col);
board[row][col] = "Q";
backtrack(n, row +1, res, board);