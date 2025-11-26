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

void solve(){
  int n, m, k; cin >> n >> m >> k;
  string s; cin >> s;
  vector g(n, vector<int>());
  while(m--){
    int u, v; cin >> u >> v; u--; v--;
    g.at(u).emplace_back(v);
  }
  vector dp(2 * k + 1, vector<bool>(n, false));
  rep(i, n) if(s.at(i) == 'A') dp.at(0).at(i) = true;
  rep(i, 2 * k){
    if(i % 2 == 0){
      rep(from, n){
        bool ok = true;
        for(auto to : g.at(from)) ok &= dp.at(i).at(to);
        dp.at(i + 1).at(from) = ok;
      }
    }
    else{
      rep(from, n){
        bool ok = false;
        for(auto to : g.at(from)) ok |= dp.at(i).at(to);
        dp.at(i + 1).at(from) = ok;
      }
    }
  }
  cout << (dp.at(2 * k).at(0) ? "Alice" : "Bob") << '\n';
}

/*
Bobが基本的に有利
2*k-1回行ったときの頂点にBがあれば有利な方の勝ち
不利な方は、相手がどう選んでも最終的な到着点が自分の頂点にならなければならない

Aliceが勝つパターンを考えれば良さそう

Aliceの手番→勝つような操作がある(すべてのパターンにorを取る)
Bobの手番→すべての操作で勝つ(andを取る)

逆順に見る？
2*K回操作した時点でAにいなければいけない
2*K-1回時点でAにしか辺がない頂点にいなければいけない
2*k-2回時点で上の頂点に辺があるような辺にいなければいけない
0回時点で1回時点の頂点に辺があるような辺にいなければいけない
*/

signed main(){
  int t; cin >> t;
  while(t--) solve();
}
