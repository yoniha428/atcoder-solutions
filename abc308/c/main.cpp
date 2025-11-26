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
  vector<pair<int, int>> ab(n); for(auto&& [a, b] : ab) cin >> a >> b;
  vector<int> ans(n); rep(i, n) ans.at(i) = i;
  stable_sort(all(ans), [&](int i, int j){
    auto&& [ai, bi] = ab.at(i);
    auto&& [aj, bj] = ab.at(j);
    return ai * (aj + bj) > aj * (ai + bi);
  });
  rep(i, n) cout << ans.at(i) + 1 << (i == n - 1 ? '\n' : ' ');
}
