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
  vector<int> a(n + 1), b(n);
  for(auto&& ai : a) cin >> ai;
  for(auto&& bi : b) cin >> bi;
  int ans = 0;
  rep(i, n){
    // b[i]でa[i]を殴り、余力でa[i+1]を殴る
    int mi = min(a.at(i), b.at(i));
    ans += mi;
    a.at(i) -= mi;
    b.at(i) -= mi;
    mi = min(a.at(i + 1), b.at(i));
    a.at(i + 1) -= mi;
    b.at(i) -= mi;
    ans += mi;
  }
  cout << ans << '\n';
}
