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
  int n, d; cin >> n >> d;
  // if(n == 15) return 0;
  vector<int> a(n); for(auto&& ai : a) cin >> ai, ai--;
  int amax = 1000000;
  vector<int> cnt(amax, 0); for(auto&& ai : a) cnt.at(ai)++;
  vector<int> presum(amax + 1, 0); rep(i, amax) presum.at(i + 1) = presum.at(i) + cnt.at(i);
  mint ans = 1;
  rep(i, amax){
    if(cnt.at(i) == 0) continue;
    ans += cnt.at(i) * (presum.at(min(amax, i + d + 1)) - presum.at(i + 1));
  }
  println("{}", ans.val());
}
/*
自分より大きく自分+D以下

自分の数*(相手の数+1)


*/

