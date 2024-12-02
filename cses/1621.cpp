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
    set<int> s;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        s.insert(t);
    }

    cout << s.size() << endl;
}