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
  vector<int> a(5); for(auto&& ai : a) cin >> ai;
  vector<pair<int, string>> ans;
  rep(i, 1ll << 5){
    if(i == 0) continue;
    string name;
    int point = 0;
    rep(j, 5) if(i >> j & 1){
      point -= a.at(j);
      name += char(j + 'A');
    }
    ans.emplace_back(point, name);
  }
  sort(all(ans));
  for(auto [point, name] : ans) println("{}", name);
}
