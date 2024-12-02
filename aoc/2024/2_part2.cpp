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

// returns first position with a problem
int find_problem(vector<int>& diffs, int start, int end) {
    int problem = -1;
    for(int i = start; i < end; i++) {
        if(diffs[i] == 0) {
            problem = i;
        }
        else if(abs(diffs[i]) > 3) {
            problem = i;
        }
        else if(i > 0){
            if(diffs[i] < 0 && diffs[i - 1] > 0)
                problem = i;
            else if(diffs[i] > 0 && diffs[i - 1] < 0)
                problem = i;
        }

        if(problem != -1) break;
    }
    return problem;
}
            
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
        
    int ans = 0;

    string s;
    int p = 0;
    while(getline(cin, s)) {
        istringstream stream(s);
        //cout << "Problem " << p++ << " ------------" << endl;

        vector<int> diffs;
        int p, c;
        stream >> p;
        while(stream >> c) {
            diffs.push_back(c - p);
            p = c;
        }

        /*
        for(int j = 0; j < diffs.size(); j++) {
            cout << diffs[j] << '\t';
        }
        cout << endl;
        */

        // look for first diff where a problem occurs
        int problem = find_problem(diffs, 0, diffs.size());
        
        if(problem != -1) {
            //cout << "found problem @" << problem << endl;

            // remove the problem
            diffs[problem] = diffs[problem] + diffs[problem + 1];
            for(int j = problem + 1; j < diffs.size(); j++) {
                diffs[j] = diffs[j + 1];
            }

            /*
            for(int j = 0; j < diffs.size() - 1; j++) {
                cout << diffs[j] << '\t';
            }
            cout << endl;
            */

            problem = find_problem(diffs, 0, diffs.size() - 1);
        } 

        if(problem == -1) ans++;

        //if(problem == -1) cout << "SAFE!" << endl;
        //else cout << "NOT SAFE! Another problem at " << problem << endl;
        //cout << "------------" << endl;
    }

    cout << ans << endl;
}