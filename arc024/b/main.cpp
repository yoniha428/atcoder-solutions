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
  vector<int> a(n); for(auto&& ai : a) cin >> ai;
  bool same = true;
  for(auto ai : a) same &= ai == a.at(0);
  if(same){
    cout << -1 << '\n';
    return 0;
  }
  vector<pair<int, int>> rle;
  for(auto ai : a){
    if(rle.empty() || rle.back().first != ai) rle.emplace_back(ai, 1);
    else rle.back().second++;
  }
  if(rle.back().first == rle.front().first){
    rle.front().second += rle.back().second;
    rle.pop_back();
  }
  int ans = 0;
  for(auto [val, len] : rle) chmax(ans, (len + 1) / 2);
  cout << ans << '\n';
}
