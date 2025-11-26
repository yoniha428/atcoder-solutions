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
  int n, k; cin >> n >> k;
  vector<int> a(n); for(auto&& ai : a) cin >> ai;
  vector memo(k + 1, vector<int>(2, -1));
  int cnt = 0;
  auto dfs = [&](auto dfs, int x, bool isfirst) -> bool{
    cnt++;
    if(x < a.at(0)){
      return !isfirst;
    }
    if(memo.at(x).at(isfirst) == -1){
      if(isfirst){
        bool ok = false;
        for(auto ai : a) if(x - ai >= 0) ok |= dfs(dfs, x - ai, !isfirst);
        memo.at(x).at(isfirst) = ok;
      }
      else{
        bool ok = true;
        for(auto ai : a) if(x - ai >= 0) ok &= dfs(dfs, x - ai, !isfirst);
        memo.at(x).at(isfirst) = ok;
      }
    }
    return memo.at(x).at(isfirst);
  };
  cout << (dfs(dfs, k, true) ? "First" : "Second") << '\n';
}
/*
x<a1に対して、x個で回ってくると負け
x+ai個で回ってくれば勝ち

(x個, 先手番)が先手必勝⇔∃i, (x-ai個, 後手番)が先手必勝
(x個, 後手番)が先手必勝⇔∀i, (x-ai個, 先手番)が先手必勝
*/
