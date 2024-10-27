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
typedef vector<bool> vb;
typedef vector<vb> vvb;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define all(x) (x).begin(), (x).end()
#define len(x) ((ll)(x).size())
#define vprint(x) for(auto it: x) cout << it << " "; cout << endl;

ll mod = 1e9 + 7; // 998244353;
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

int board_size = 7;
vvb visited(board_size, vb(board_size, false));
string pattern;
int res = 0;

bool is_possible(int row, int col) {
    return row >= 0 && row < board_size && col >= 0 && col < board_size && !visited[row][col];
}

bool is_deadend(int row, int col) {
    if (is_possible(row+1, col) && is_possible(row-1, col) && !is_possible(row, col+1) && !is_possible(row, col-1))
        return 1;
    if (!is_possible(row+1, col) && !is_possible(row-1, col) && is_possible(row, col+1) && is_possible(row, col-1))
        return 1;
    return 0;
}

void dfs(int row, int col, int path_len) {
    if (row == board_size - 1 && col == 0) {
        if (path_len == board_size * board_size - 1) {
            res++;
        }
        return;
    }
    visited[row][col] = 1;
    char cur_move = pattern[path_len];
    if (cur_move == '?' || cur_move == 'D') {
        if (is_possible(row + 1, col) && !is_deadend(row + 1, col))
            dfs(row + 1, col, path_len + 1);
    } 
    if (cur_move == '?' || cur_move == 'U') {
        if (is_possible(row - 1, col) && !is_deadend(row - 1, col))
            dfs(row - 1, col, path_len + 1);
    } 
    if (cur_move == '?' || cur_move == 'R') {
        if (is_possible(row, col + 1) && !is_deadend(row, col + 1))
            dfs(row, col + 1, path_len + 1);
    } 
    if (cur_move == '?' || cur_move == 'L') {
        if (is_possible(row, col - 1) && !is_deadend(row, col - 1))
            dfs(row, col - 1, path_len + 1);
    }
    visited[row][col] = 0;
    return;
}

void solve(){
    re(pattern);
    dfs(0, 0, 0);
    print(res);
    return;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}