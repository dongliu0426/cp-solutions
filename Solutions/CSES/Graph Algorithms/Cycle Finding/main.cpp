#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

using ll = long long;
using ld = long double;
using str = string;

using pii = pair<int, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<str>;
using vii = vector<pii>;
template <class T> using v = vector<T>;

#define mp make_pair
#define f first
#define s second

#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define lb lower_bound
#define ub upper_bound

#define F0R(i,a) for(int i=0; i<(a); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define R0F(i,a) for(int i=(a)-1; i>=0; i--)
#define ROF(i,a,b) for(int i=(b); i>=a; i--)
#define trav(a,x) for (auto& a: x)

const int MOD = 1e9+7;
// const ll INF = 1e18;
const int MX = 2e5+5;
const ld PI = acos(-1);
const int X[] = {1, 0, -1, 0},
          Y[] = {0, 1, 0, -1};

/* ============================ */

void setIO(str PROB = "") {
    cin.tie(0)->sync_with_stdio(0);
    if(sz(PROB)) {
        freopen((PROB+".in").c_str(), "r", stdin);
        freopen((PROB+".out").c_str(), "w", stdout);
    }
}

/* ============================ */

int N;

const ll INF = 1e18;
struct node {
	int to, from, weight;
	node(int to, int from, int weight) : to(to), from(from), weight(weight) {}
};
ll dist[2505], pa[2505];
vector<node> adj;
void bellmanFord(int src) {
	for (int i = 1; i <= N; i++) dist[i] = INF;
	dist[src] = 0; int x=0;
	for (int i = 1; i <= N; i++) {
        x=-1;
        for (node j : adj)
            if (dist[j.to] > dist[j.from] + j.weight)
                dist[j.to] = dist[j.from] + j.weight,
                pa[j.to] = j.from,
                x=j.to;
    }
    if (x==-1) {
        cout <<"NO";
    } else {
        F0R(i,N-1) x=pa[x];
        cout <<"YES\n";
        vi cycle;
        for (int v = x;; v = pa[v]) {
            cycle.pb(v);
            if (v==x && sz(cycle)>1) break;
        }
        reverse(all(cycle));
        trav(c,cycle) cout << c <<" ";
    }

}

int main() {
    setIO("");

    cin >> N;
    int m; cin >> m;
    F0R(i,m) {
        int a,b,c; cin >> a >> b >> c;
        adj.pb(node(b,a,c));
    }
    bellmanFord(1);

}