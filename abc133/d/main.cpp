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
  vector<int> ans(n);
  rep(i, n - 1) ans.at(i + 1) = 2 * a.at(i) - ans.at(i);
  int diff = reduce(all(a)) - reduce(all(ans));
  rep(i, n) ans.at(i) += (i % 2 ? -1 : 1) * diff;
  rep(i, n) cout << ans.at(i) << (i == n - 1 ? '\n' : ' ');
}
/*
ans.at(i) / 2 + ans.at(i + 1) / 2 = a.at(i)
ans.at(0) = xとすると、
ans.at(1) = 2 * a.at(i) - x
ans.at(0)がx増えると答えもx増える
*/
