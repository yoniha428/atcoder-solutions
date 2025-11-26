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
  int k; cin >> k; k--;
  string s = "9876543210";
  vector<int> ans;
  rep(i, 1ll << 10){
    int sum = 0;
    rep(j, 10) if(i >> j & 1){
      sum *= 10;
      sum += s.at(j) - '0';
    }
    if(sum != 0) ans.emplace_back(sum);
  }
  sort(all(ans));
  println("{}", ans.at(k));
}
