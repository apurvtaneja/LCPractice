​
class Solution {
public:
vector<vector<int>> perm;
void generatePermutation(vector<int>& arr, int n, int i){
if(i==n){
perm.push_back(arr);
return;
}
for(int j = i; j <n; j++){
swap(arr[i], arr[j]);
generatePermutation(arr, n, i+1);
swap(arr[i], arr[j]);
}
}
string getPermutation(int n, int k) {
vector<int> arr;
for(int i = 1; i<=n; i++)
arr.push_back(i);
generatePermutation(arr, n, 0);
sort(perm.begin(), perm.end());
string ans = "";
for(int i = 0; i<perm[k-1].size(); i++)
ans += to_string(perm[k-1][i]);
return ans;
}
};