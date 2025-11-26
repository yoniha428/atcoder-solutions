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
  vector<pair<int, int>> rh(n);
  vector cnt(100000, vector<int>(3, 0));
  vector<int> r;
  for(auto&& [ri, hi] : rh){
    cin >> ri >> hi; ri--; hi--;
    cnt.at(ri).at(hi)++;
    r.emplace_back(ri);
  }
  sort(all(r));
  for(auto [ri, hi] : rh){
    cout <<
    lower_bound(all(r), ri) - r.begin() + cnt.at(ri).at((hi + 1) % 3) << ' ' <<
    r.end() - upper_bound(all(r), ri) + cnt.at(ri).at((hi + 2) % 3) << ' ' <<
    cnt.at(ri).at(hi) - 1 << '\n';
  }
}
