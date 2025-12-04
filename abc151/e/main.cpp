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

using mint = modint1000000007;

signed main(){
  int n, k; cin >> n >> k;
  vector<int> a(n); for(auto&& ai : a) cin >> ai;
  sort(all(a));
  vector<mint> fact(n, 1);
  rep(i, n - 1) fact.at(i + 1) = fact.at(i) * (i + 1);
  mint ans = 0;
  rep(i, n){
    if(i >= k - 1) ans += a.at(i) * fact.at(i) / (fact.at(k - 1) * fact.at(i - (k - 1)));
    if(n - 1 - i >= k - 1) ans -= a.at(i) * fact.at(n - 1 - i) / (fact.at(k - 1) * fact.at(n - 1 - i - (k - 1)));
  }
  cout << ans.val() << '\n';
}
/*
自分がmaxに採用されるのは、(自分より小さい要素数)C(k-1)
*/