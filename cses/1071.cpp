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
        
    int t; cin >> t;

    for(int i = 0; i < t; i++) {
        long long x, y; cin >> x >> y;
        long long v;
        long long d;
        if(x < y) {
            v = (y - 1) * (y - 1);
            if(y % 2 == 0) {
                d = x; 
            } else {
                d = 2*y - x; 
            }
            v += d;
        } else {
            v = (x - 1) * (x - 1);
            if(x % 2 == 0) {
                d = 2 * x - y; 
            } else {
                d = y; 
            }
            v += d;
        }
        cout << v << endl;
    }
}