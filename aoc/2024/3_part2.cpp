#include <bits/stdc++.h>
#include <regex>
        
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

int compute_muls(string s) {
    long long ans = 0;

    regex mul("mul\\(([[:digit:]]{1,3}),([[:digit:]]{1,3})\\)");
    smatch match;

    while (regex_search(s, match, mul)) {
        int a = stoi(match[1]);
        int b = stoi(match[2]);
        ans += a*b;
        s = match.suffix().str();
    }

    return ans;
}
       
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
        
    long long ans = 0;

    std::stringstream buffer;
    buffer << std::cin.rdbuf(); // Read all input until EOF
    std::string s = buffer.str();

    regex dos("(do\\(\\))|(don't\\(\\))");
    smatch match;

    bool enabled = true;
    
    while (regex_search(s, match, dos)) {
        if(enabled) ans += compute_muls(match.prefix());

        if(match.str() == "do()") enabled = true;
        else enabled = false;

        s = match.suffix().str();
    } 

    if(enabled) ans += compute_muls(s);

    cout << ans << endl;
}