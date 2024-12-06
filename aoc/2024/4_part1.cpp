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
    
bool dfs(vector<string>& m, string& w, int x, int y, int p, pair<int, int>& dir) {
    if(x < 0 || x >= m.size() || y < 0 || y >= m[0].size()) return false;
    if(w[p] != m[x][y]) return false;
    if(p == w.size() - 1) return true;
    return dfs(m, w, x+dir.first, y+dir.second, p+1, dir);
}
            
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
        
    vector<string> m;
    string s;
    while(cin >> s) m.push_back(s);
    
    string w = "XMAS";
    
    int ans = 0;
    for(int x = 0; x < m.size(); x++) {
        for(int y = 0; y < m[x].size(); y++) {
            for(int i = -1; i <= 1; i++) {
                for(int j = -1; j <= 1; j++) {
                    pair<int, int> dir{i, j};
                    ans += dfs(m, w, x, y, 0, dir);
                }
            }
        }
    }

    cout << ans << endl;
}