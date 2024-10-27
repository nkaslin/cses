#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<vector<pll>> vvpll;
typedef vector<pll> vpll;
typedef vector<pi> vpi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define all(x) (x).begin(), (x).end()
#define len(x) ((ll)(x).size())
#define vprint(x) for(auto it: x) cout << it << " "; cout << endl;

const int mod = 1000000007; // 998244353;
double eps = 1e-12;
const double PI = acos(-1);

#define vprint(x) for(auto it: x) cout << it << " "; cout << endl;

// simplifies res = max(res, x) to smax(res, x)
template<typename T, typename U> void smax(T &a, const U &b) { if (a < b) a = b; }
template<typename T, typename U> void smin(T &a, const U &b) { if (a > b) a = b; }

namespace io {
    // define re, pr, de (used with the dbg macro)
    template<class T, class... U> void re(T&& a, U&&... b) {
        cin >> forward<T>(a); 
        (int[]){(cin >> forward<U>(b), 0)...};
    }
    template<class T, class... U> void print(T&& a, U&&... b) {
        cout << forward<T>(a); 
        (int[]){(cout << " " << forward<U>(b), 0)...};
        cout << "\n";
    }
    template<class T, class... U> void de(T&& a, U&&... b) {
        cerr << forward<T>(a); 
        (int[]){(cerr << " " << forward<U>(b), 0)...};
        cerr << "\n";
    }
}

using namespace io;

#define dbg(...) { cerr << "[Line " << __LINE__ << "] " << #__VA_ARGS__ << " is "; io::de(__VA_ARGS__); }


ll dp[1000002];

void solve(){
    int n, x; re(n); re(x);
    vi c(n);
    for (int i=0; i<n; i++) re(c[i]);
    dp[0] = 1;
    for (int i=1; i<=x; i++) {
        for (int j=0; j<n; j++) {
            if (i - c[j] >= 0) {
                dp[i] += dp[i-c[j]];
                dp[i] %= mod;
            }
        }
    }
    print(dp[x]);

    
    return;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// using vi = vector<int>;
// #define pb push_back
// #define rsz resize
// #define all(x) begin(x), end(x)
// #define sz(x) (int)(x).size()
// using pi = pair<int, int>;
// #define f first
// #define s second
// #define mp make_pair
// void setIO(string name = "") {  // name is nonempty for USACO file I/O
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);  // see Fast Input & Output
// 	if (sz(name)) {
// 		freopen((name + ".in").c_str(), "r", stdin);  // see Input & Output
// 		freopen((name + ".out").c_str(), "w", stdout);
// 	}
// }

// ll dp[1000001];

// const int MOD = (int)1e9 + 7;

// int main() {
// 	int n, x;
// 	cin >> n >> x;
// 	vi coins(n);
// 	for (int i = 0; i < n; i++) { cin >> coins[i]; }
// 	dp[0] = 1;
// 	for (int weight = 0; weight <= x; weight++) {
// 		for (int i = 1; i <= n; i++) {
// 			if (weight - coins[i - 1] >= 0) {
// 				dp[weight] += dp[weight - coins[i - 1]];
// 				dp[weight] %= MOD;
// 			}
// 		}
// 	}
// 	cout << dp[x] << '\n';
// }