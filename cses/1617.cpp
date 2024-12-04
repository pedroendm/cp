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
    
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
        
    int n; cin >> n;
    int ans = 2;
    for(int i = 2; i <= n; i++) {
        ans = (ans * 2) % (static_cast<int>(1e9) + 7);
    }
    cout << ans << endl;
}