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
    
    vector<int> a, b;

    int v;
    while(cin >> v) {
        a.push_back(v);
        cin >> v;
        b.push_back(v);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long long ans = 0;
    for(int i = 0; i < a.size(); i++)
        ans += abs(a[i] - b[i]);

    cout << ans << endl;
}