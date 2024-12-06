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
    
class Graph {
    public:
        vector<vector<int>> adjs;
        vector<vector<bool>> exists_path;
        Graph(int n) {
            adjs = vector<vector<int>>(n);
            exists_path = vector<vector<bool>>(n, vector<bool>(n, false));            
        }

        void add_edge(int from, int to) {
            adjs[from].push_back(to);
        }

        void dfs(int from, int cur, vector<bool>& visited) {
            exists_path[from][cur] = true;
            visited[cur] = true;
            for(int v: adjs[from]) 
                if(!visited[v])
                    dfs(from, v, visited);
        }

        void compute_exists_path() {
            for(int i = 0; i < 100; i++) {
                vector<bool> visited(100, false);
                dfs(i, i, visited);
            }
        }
};

pair<int, int> valid_update(Graph& g, const vector<int>& update) {
    for(int i = update.size() - 1; i > 0; i--) {
        for(int j = i - 1; j >= 0; j--) {
            if(g.exists_path[update[i]][update[j]]) return pair<int, int>{i, j};
        }
    }
    return pair<int, int>{-1, -1};
}
 
void print_update(vector<int> update) {
    for(int v: update) 
        cout << v << '\t';
    cout << endl;
}

void fix_update(Graph& g, vector<int>& update) {
    pair<int, int> v;
    while((v = valid_update(g, update)) != pair<int, int>{-1, -1}) {
        //cout << "I have "<< update[v.first]<<" in front of "<< update[v.second]<<", but I shouldn't" <<endl;
        //print_update(update);
        int t = update[v.first];
        update.erase(update.begin() + v.first);
        //print_update(update);
        update.insert(update.begin() + v.second, t);
        //print_update(update);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    Graph g(100);

    string s;
    while(cin >> s) {
        if(s.find("|") == string::npos) break;

        std::istringstream iss(s);
        std::string token;
        getline(iss, token, '|');
        int a = stoi(token);
        getline(iss, token, '|');
        int b = stoi(token);

        g.add_edge(a, b);
    }

    g.compute_exists_path();

    int ans = 0;
    do {
        std::istringstream iss(s);
        std::string token;
        vector<int> update;
        while(getline(iss, token, ',')) update.push_back(stoi(token));
        if(valid_update(g, update) != pair<int, int>{-1, -1}) {
            // fix update
            fix_update(g, update);
            // add
            ans += update[update.size() / 2];
        }
    } while(cin >> s);
    
    cout << ans << endl;
}   