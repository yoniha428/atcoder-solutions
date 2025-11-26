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
  int n; cin >> n;
  string s(n, '-'); for(auto&& c : s) cin >> c;
  vector g(n, vector<int>());
  rep(i, n - 1){
    int a, b; cin >> a >> b; a--; b--;
    g.at(a).emplace_back(b);
    g.at(b).emplace_back(a);
  }
  // for(auto& gi : g){
  //   for(auto gij : gi) cout << gij << ' ';
  //   cout << endl;
  // }
  vector ans(n, vector<mint>(3, 0));
  auto dfs = [&](auto dfs, int from, int root = -1) -> void{
    bool isa = s.at(from) == 'a';
    mint only = 1, all = 1;
    for(auto& to : g.at(from)) if(to != root){
      dfs(dfs, to, from);
      only *= ans.at(to).at(isa) + ans.at(to).at(2);
      all *= ans.at(to).at(0) + ans.at(to).at(1) + 2 * ans.at(to).at(2);
    }
    ans.at(from).at(isa) = only;
    ans.at(from).at(2) = all - only;
  };
  dfs(dfs, 0);
  cout << ans.at(0).at(2).val() << '\n';
}
/*
aのみにするときの値を求めるとき、
1. ab共に含む部分木と繋いじゃダメ(繋ぐとaのみでなくなる)
2. aのみの部分木は繋がないとダメ(切るとその部分木がaのみで不適)
3. bのみの部分木は値に寄与しない(繋いだらaのみでなくなり、繋がないとbのみで不適)

ab共に含むときの値を求めるとき、基本的には
1. ab共に含む部分木とは繋いでも繋がなくてもよい
2. aやbのみの部分木は必ず繋ぐ
だが、fromがaのときに、ab共に含むところやbを含むところを全く繋がないとaのみになる
ので、それを引く
*/