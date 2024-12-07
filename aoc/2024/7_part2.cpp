#include <bits/stdc++.h>
        
using namespace std;
        
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
    
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, const std::pair<T1, T2>& p) {
    out << "(" << p.first << ", " << p.second << ")";
    return out;
}

bool search(ull test_value, vector<ull>& numbers) {
    stack<pair<ull, ull>> s;

    s.push({0, numbers[0]});

    while(!s.empty()) {
        auto p = s.top();
        s.pop();

        if(p.first == numbers.size() - 1) {
            if(p.second == test_value) 
                return true;
        } else {
            s.push({p.first + 1, p.second + numbers[p.first + 1]});
            s.push({p.first + 1, p.second * numbers[p.first + 1]});
            string t = to_string(p.second) + to_string(numbers[p.first + 1]);
            s.push({p.first + 1, stoull(t)});
        }
    }

    return false;
}
            
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
        
    string s;
    ull ans = 0;

    while(getline(cin, s)) {
        // change : to a space so parsing is easier
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ':') {
                s[i] = ' ';
                break;
            }
        }

        istringstream parse(s);
        
        ull test_value;
        parse >> test_value;

        vector<ull> numbers;
        ull t;
        while(parse >> t) numbers.push_back(t);

        if(search(test_value, numbers)) {
            //cout << "Calibration possible for test value " << test_value << endl;
            ans += test_value;
        }
    }

    cout << ans << endl;
}