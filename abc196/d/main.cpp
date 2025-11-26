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
  int h, w, a, b; cin >> h >> w >> a >> b;
  auto dfs = [&](auto dfs, vector<vector<bool>> field, int acnt, int bcnt) -> int{
    if(acnt == a && bcnt == b) return 1;
    int ret = 0;
    rep(i, h) rep(j, w) if(!field.at(i).at(j)){
      if(acnt < a && j + 1 < w && !field.at(i).at(j + 1)){
        field.at(i).at(j) = field.at(i).at(j + 1) = true;
        ret += dfs(dfs, field, acnt + 1, bcnt);
        field.at(i).at(j) = field.at(i).at(j + 1) = false;
      }
      if(acnt < a && i + 1 < h && !field.at(i + 1).at(j)){
        field.at(i).at(j) = field.at(i + 1).at(j) = true;
        ret += dfs(dfs, field, acnt + 1, bcnt);
        field.at(i).at(j) = field.at(i + 1).at(j) = false;
      }
      if(bcnt < b){
        field.at(i).at(j) = true;
        ret += dfs(dfs, field, acnt, bcnt + 1);
        field.at(i).at(j) = false;
      }
      return ret;
    }
    return 0;
  };
  vector empty(h, vector<bool>(w, false));
  cout << dfs(dfs, empty, 0, 0) << '\n';
}
