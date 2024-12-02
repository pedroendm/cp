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

    if(n == 1) {
        cout << 1;
    }
    else if(n <= 3) {
        cout << "NO SOLUTION";
    } 
    else if(n <= 4) {
        cout << 2 << ' ' << 4 << ' ' << 1 << ' ' << 3; 
    }
    else {
        int t = n;
        while(t > 0) {
            cout << t << ' ';
            t -= 2;
        }
        t = n - 1;
        while(t > 0) {
            cout << t << ' ';
            t -= 2;
        }
    }
    cout << endl;
}