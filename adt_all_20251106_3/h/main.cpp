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
  int n, q; cin >> n >> q;
  vector<int> cnt(n, 0);
  vector<bool> color(n, false);
  dsu d(n);
  while(q--){
    int op; cin >> op;
    if(op == 1){
      int u, v; cin >> u >> v; u--; v--;
      if(d.same(u, v)) continue;
      int ul = d.leader(u), vl = d.leader(v);
      int nl = d.merge(u, v);
      cnt.at(nl) += cnt.at(nl == ul ? vl : ul);
    }
    if(op == 2){
      int v; cin >> v; v--;
      if(color.at(v)){
        color.at(v) = false;
        cnt.at(d.leader(v))--;
      }
      else{
        color.at(v) = true;
        cnt.at(d.leader(v))++;
      }
    }
    if(op == 3){
      int v; cin >> v; v--;
      println("{}", cnt.at(d.leader(v)) > 0 ? "Yes" : "No");
    }
  }
}
