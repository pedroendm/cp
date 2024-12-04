/*
The solution is constructive.

Say ans[k-1] holds the answer for a board of size k-1 by k-1.

The number of ways to put two knights in a board k by k is:
- the ways of putting the knights in a board k-1 by k-1, i.e., ans[k-1];
- plus 2*k - 1 choose 2 ways, which is the number of ways of putting the two knights just in the frontier
- plus the ways of putting on knight in the frontier and the other inside, which is (2k - 1)(k - 1)^2
- however, in the last step we counted invalid 8*k - 16 solutions, so we subtract that (see below)

                 2
                 3
                 .
                 .
                 .
                 4
                 3
2 3 4 4 .... 4 3 2

2 (2*2 + 3*2 + 4*(k-4)) = 2 (4 + 6 -4k + 16) = 8 + 12 8k - 32 = 8k - 16.
*/
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

long long n_choose_two(long long n) {
    long long ans = 1;
    for(long long i = n; i >= n - 2 + 1; i--) ans *= i;
    return ans / 2;
}
    
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
        
    int n; cin >> n;
    vector<long long> ans(n);
    ans[0] = 0;

    for(int i = 1; i < n; i++) {
        long long k = i + 1;
        ans[i] = ans[i-1] + n_choose_two(2*k - 1) + ((2*k - 1) * (k - 1) * (k - 1)) - (8*k - 16);
    }

    for(int i = 0; i < n; i++) {
        cout << ans[i] << '\n';
    }
}