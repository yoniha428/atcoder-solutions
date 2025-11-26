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
  vector<tuple<int, int, int>> ab(n);
  rep(t, n){
    auto&& [a, b, i] = ab.at(t);
    cin >> a >> b;
    i = t;
  }
  sort(all(ab), [](auto x, auto y){
    auto [xa, xb, xi] = x;
    auto [ya, yb, yi] = y;
    return xa * (ya + yb) == ya * (xa + xb) ? xi < yi : xa * (ya + yb) > ya * (xa + xb);
  });
  for(auto& [a, b, i] : ab) cout << i + 1 << '\n';
}
