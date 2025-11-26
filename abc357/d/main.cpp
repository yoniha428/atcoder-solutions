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

using mint = modint998244353;

signed main(){
  int n; cin >> n;
  int len = to_string(n).size();
  mint lenpow = mint(10).pow(len);
  // cout << "lenpow" << endl;
  mint ans = (lenpow.pow(n) - 1) / (lenpow - 1) * n;
  cout << ans.val() << '\n';
}
/*
n * 100010001(0はnの長さ-1個、1の個数はn個)
sum((10^a)^i)=(10^a/(10^a-1))((10^a)^n-1)
*/
