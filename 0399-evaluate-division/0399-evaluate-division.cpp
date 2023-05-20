class Solution {
private:
    void dfs(string s, string d, map<string, vector<pair<string, double>>> &m, double& ans, double temp, set<string> v){
        if(v.find(s) != v.end())
            return ;
        
        v.insert(s);
        
        if(s == d){
            ans = temp;
            return ;
        }
        for(auto n: m[s])
            dfs(n.first, d, m, ans, temp * n.second, v);
    }
public:
    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& v, vector<vector<string>>& q) {
        map<string, vector<pair<string, double>>> m;
        
        for(int i = 0; i<e.size(); i++){
            m[e[i][0]].push_back({e[i][1], v[i]});
            m[e[i][1]].push_back({e[i][0], 1/v[i]});
        }
        
        vector<double> res;
        
        for(int i = 0; i<q.size(); i++){
            string s = q[i][0];
            string d = q[i][1];
            double ans = -1.0;
            set<string> v;
            if(m.find(s) != m.end())
                dfs(s, d, m, ans, 1.0, v);
            
            res.push_back(ans);
        }
        
        return res;
    }
};