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
     
    void solve() {
        long long n; cin >> n;
        cout << n << ' ';
        while(n != 1) {
            if(n % 2 == 0) n = n / 2;
            else n = 3*n + 1;
            cout << n << ' ';
        }
        cout << endl;
    }
             
    int main(void) {
        ios::sync_with_stdio(0);
        cin.tie(0);
            
        solve();
    }