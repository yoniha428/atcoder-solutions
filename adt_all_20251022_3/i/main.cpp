#if __has_include(<yoniha/all.h>)
#include <yoniha/all.h>
using namespace atcoder;
#else
#include <bits/stdc++.h>
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif
#endif
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = (int)((n) - 1); i >= 0; i--)
template <typename T> bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template <typename T> bool chmin(T &a,const T &b){if(a>b){a=b;return true;}return false;}

// using mint = modint;

signed main(){
  int n; cin >> n;
  vector<pair<vector<int>, int>> hwd;
  vector<vector<int>> per{{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};
  rep(i, n){
    vector<int> x(3); for(auto&& xi : x) cin >> xi;
    for(auto& pi : per){
      vector<int> w(3);
      rep(i, 3) w.at(pi.at(i)) = x.at(i);
      hwd.emplace_back(x);
    }
  }
  sort(all(hwd));
}
/*
ha < hb && wa < wb && da < db
は、弱順序をなさないよぉ
*/