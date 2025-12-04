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
  string s; cin >> s;
  vector<mint> dp(13); dp.at(0) = 1;
  for(auto c : s){
    vector<mint> ep(13);
    if(isdigit(c)){
      rep(j, 13) ep.at((j * 10 + c - '0') % 13) += dp.at(j);
    }
    else{
      rep(i, 10) rep(j, 13) ep.at((j * 10 + i) % 13) += dp.at(j);
    }
    // rep(i, 13) cout << ep.at(i).val() << ' ';
    // cout << '\n';
    dp = ep;
  }
  cout << dp.at(5).val() << '\n';
}
