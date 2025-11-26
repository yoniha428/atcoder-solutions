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
  int n, h, w; cin >> n >> h >> w;
  vector<pair<int, int>> ab(n); for(auto&& [a, b] : ab) cin >> a >> b;
  bool ans = false;
  auto dfs = [&](auto dfs, vector<bool> used, vector<vector<bool>> field) -> void{
    // rep(i, n) cout << used.at(i) << (i == n - 1 ? '\n' : ' ');
    // rep(i, h) rep(j, w) cout << field.at(i).at(j) << (j == w - 1 ? "\n" : "");
    int si = -1, sj = -1;
    rep(i, h){
      bool br = false;
      rep(j, w){
        if(!field.at(i).at(j)){
          si = i; sj = j;
          br = true;
          break;
        }
      }
      if(br) break;
    }
    if(si == -1 && sj == -1){
      ans = true;
      return;
    }
    rep(t, 2 * n) if(!used.at(t % n)){
      auto [a, b] = ab.at(t % n);
      if(t / n) swap(a, b);
      if(si + a - 1 >= h || sj + b - 1 >= w) continue;
      bool can_put = true;
      for(int ii = si; ii < si + a; ii++) for(int jj = sj; jj < sj + b; jj++){
        can_put &= !field.at(ii).at(jj);
      }
      if(!can_put) continue;
      used.at(t % n) = true;
      for(int ii = si; ii < si + a; ii++) for(int jj = sj; jj < sj + b; jj++){
        field.at(ii).at(jj) = true;
      }
      dfs(dfs, used, field);
      used.at(t % n) = false;
      for(int ii = si; ii < si + a; ii++) for(int jj = sj; jj < sj + b; jj++){
        field.at(ii).at(jj) = false;
      }
    }
  };
  dfs(dfs, vector<bool>(n, false), vector(h, vector<bool>(w, false)));
  cout << (ans ? "Yes" : "No") << '\n';
}
/*
それぞれのタイルに対して、左上が0~h-1, 0~w-1になるように置くか、置かないか
100^nとかになって間に合わない
盤面とusedを渡してDFSで全探索みたいな？
*/
