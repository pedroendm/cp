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
            
        int n;
        cin >> n;

        vector<bool> v(n+1);

        for(int i = 0; i < n-1; i++) {
            int t;
            cin >> t;
            v[t] = true;
        }

        for(int i = 1; i <= n; i++) {
            if(!v[i]) {
                cout << i << endl;
                break;
            }
        }
    }