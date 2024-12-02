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
            
        string s;
        cin >> s;

        int m = 0;
        int i = 0;
        while(i < s.size()) {
            int j = i+1;
            while(j < s.size() && s[j] == s[i]) j++;
            m = max(m, j - i);
            i += j - i;
        }
        cout << m << endl;
    }