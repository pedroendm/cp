#include <bits/stdc++.h>
        
using namespace std;
        
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
    
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, const std::pair<T1, T2>& p) {
    out << "(" << p.first << ", " << p.second << ")";
    return out;
}

bool dfs(vector<string>& m, const string& w, int x, int y, int p, const pair<int, int>& dir) {
    if(x < 0 || x >= m.size() || y < 0 || y >= m[0].size()) return false;
    if(w[p] != m[x][y]) return false;
    if(p == w.size() - 1) return true;
    return dfs(m, w, x+dir.first, y+dir.second, p+1, dir);
}

bool check_x_mas(vector<string>& m, int x, int y) {
    return (dfs(m, "MAS", x, y, 0, {1, 1}) || dfs(m, "SAM", x, y, 0, {1, 1})) &&
      (dfs(m, "MAS", x, y+2, 0, {1, -1}) || dfs(m, "SAM", x, y+2, 0, {1, -1}));
}
            
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
        
    vector<string> m;
    string s;
    while(cin >> s) m.push_back(s);
    
    int ans = 0;
    for(int x = 0; x < m.size() - 2; x++) {
        for(int y = 0; y < m[x].size() - 2; y++) {
            ans += check_x_mas(m, x, y);
        }

    }
    cout << ans << endl;
}