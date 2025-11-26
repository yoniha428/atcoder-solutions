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
  int n, m; cin >> n >> m;
  vector<int> a(n); for(auto&& ai : a) cin >> ai;
  vector cnt(20, vector<int>()); // 桁数ごとにmodを入れる
  for(auto ai : a){
    string s = to_string(ai);
    cnt.at(s.size() - 1).emplace_back(ai % m);
  }
  rep(i, 20) sort(all(cnt.at(i)));
  vector<int> powmod(20);
  {
    int w = 1;
    rep(i, 20){
      powmod.at(i) = w;
      w = w * 10 % m;
    }
  }
  int ans = 0;
  for(auto ai : a){
    // 右の桁数を全探索
    rep(i, 19){
      int val = ai * powmod.at(i + 1) % m;
      val = (val == 0 ? 0 : m - val);
      ans += upper_bound(all(cnt.at(i)), val) - lower_bound(all(cnt.at(i)), val);
    }
  }
  println("{}", ans);
}
