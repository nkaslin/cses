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

constexpr ll mod = 1e9 + 7; // 998244353;
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


void solve(){
    int n; re(n);
    vi x(n);
    for (int i=0; i<n; i++) re(x[i]);

    vector<bool> res(accumulate(all(x), 0) + 1, 0);
    sort(all(x));
    for (int i=0; i<n; i++) {
        int cur=0;
        for (int j=i; j<n; j++) {
            cur += x[j];
            res[cur] = 1;
            dbg(cur);
        }
    }
    vi sol;
    for (int i=1; i<res.size(); i++) {
        if (res[i]) sol.pb(i);
    }
    print(sol.size());
    vprint(sol);
    return;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}