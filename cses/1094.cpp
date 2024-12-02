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
    vector<int> v(n);

    for(int& t: v)
        cin >> t;
    
    long long op = 0;
    for(int i = 1; i < n; i++) {
        int diff = v[i - 1] - v[i];
        if(diff > 0) {
            op += diff;
            v[i] += diff;
        }
    }
    cout << op << endl;
}