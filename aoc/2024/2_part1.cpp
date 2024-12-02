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
        
    int ans = 0;

    string s;
    while(getline(cin, s)) {
        istringstream stream(s);
        bool safe = true;
        char o = '0';

        int p, c;
        stream >> p;
        
        while (stream >> c) {
            if(!(abs(c - p) >= 1 && abs(c - p) <= 3)) {
                safe = false;
                break;
            }

            if(c - p > 0) {
                if(o == '0') o = 'i';
                else if(o == 'd') {
                    safe = false;
                    break;
                }
            } else if(c - p < 0) {
                if(o == '0') o = 'd';
                else if(o == 'i') {
                    safe = false;
                    break;
                }
            }
  
            p = c;
        }
        
        if(safe) ans++;
    }

    cout << ans << endl;
}