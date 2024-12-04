/*
For n % 4 == 0, is easy to see that we can always find a solution and those sets using the famous idea of Gauss.
For instance, for n = 8, our solution will be {1,8,3,6} and {2,7,4,5}.

For n % 4 == 3, the same.
Just take the solution for n+1. Note that if n%4 == 3, then (n+1)%4 == 0.
Now remove the n+1 from the solution and pass (n+1)/2 to the other set.
For instance, for n=7, construct solution as if n=8:
    {1,8,3,6} and {2,7,4,5}
Remove the 8 and pass (n+1)/2 = 4 to the other set.
Since the starting sets were a solution, by removing n+1 and then moving (n+1)/2 to this set, 
its easy to see that we again have a stable solution, but now for n.

For n % 4 == 1 and n % 4 = 2, it's not possible to find such solutions.
Just see that if start by a solution to n-1 in the case of n % 4 == 1 or n+2 in the case of n % 4 == 2,
there's no way I can add or remove numbers while mainting the sum equal, I would need rational numbers.

POST: basically because the sum of the numbers is odd, so I can never divide the numbers into two sets of equal sum.
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
    
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
        
    int n; cin >> n;

    if(n % 4 == 1 || n % 4 == 2) {
        cout << "NO\n"; 
    } else {
        set<int> a, b;
        int k;
        if(n % 4 == 3) k = n + 1;
        else k = n;

        for(int i = 1; i <= k/2; i+=2) {
            a.insert(i);
            a.insert(k-i+1);
        }

        for(int i = 2; i <= k/2; i+=2) {
            b.insert(i);
            b.insert(k-i+1);
        }

        if(n % 4 == 3) { 
            a.erase(k);
            a.insert(k / 2);
            b.erase(k / 2);
        }

        cout << "YES\n";
        cout << a.size() << endl;
        for(auto it = a.begin(); it != a.end(); it++)
            cout << *it << ' ';
        cout << endl;
        cout << b.size() << endl;
        for(auto it = b.begin(); it != b.end(); it++)
            cout << *it << ' ';
        cout << endl;
    }
}