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

constexpr int mod = 1e9 + 7; // 998244353;
constexpr double eps = 1e-12;
constexpr double PI = acos(-1);

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

vvi dp(105, vi(100005, 0));


void solve(){
    int n, m; re(n); re(m);
    vi x(n);
    for (int i=0; i<n; i++) re(x[i]);

    int upper, lower;
    if (x[0] == 0) {
        for (int row=1; row<=m; row++) dp[row][0] = 1;
        upper = m;
        lower = 1;
    } else {
        dp[x[0]][0] = 1;
        upper = min(x[0] + 1, m);
        lower = max(x[0] - 1, 1);
    }
    
    for (int col=1; col<n; col++) {
        if (x[col] != 0) {
            dp[x[col]][col] += dp[x[col]-1][col-1];
            dp[x[col]][col] += dp[x[col]][col-1];
            dp[x[col]][col] %= mod;
            dp[x[col]][col] += dp[x[col]+1][col-1];
            dp[x[col]][col] %= mod;
            upper = min(x[0] + 1, m);
            lower = max(x[0] - 1, 1);
            continue;
        }
        for (int row=1; row<=m; row++) {
            dp[row][col] += dp[row-1][col-1];
            dp[row][col] += dp[row][col-1];
            dp[row][col] %= mod;
            dp[row][col] += dp[row+1][col-1];
            dp[row][col] %= mod;
        }
        upper = min(upper + 1, m);
        lower = max(lower - 1, 1);
    }
    int res = 0;
    for (int row=1; row<=m; row++) {
        res += dp[row][n-1];
        res %= mod;
    }
    print(res);
    return;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}