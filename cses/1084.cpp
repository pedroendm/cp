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

int n, m, k;
vector<int> a(n);
vector<int> b(n);

int apart(int x, int low_b) {
    for(int i = low_b; i < m; i++) {
        if(b[i] <= x - k)
        if(b[i] >= x - k && b[i] <= x + k)
            return i;
    }
    return -1;
}
    
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
        
    cin >> n >> m >> k;

    for(int& v: a) cin >> v;
    
    for(int& v: b) cin >> v;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = 0;
    int p = 0;
    for(int i = 0; i < n; i++) {
        int v = apart(a[i], p);
        if(v != -1) {
            p = v + 1;
            ans++;
        }
    }
}