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
  int ia, ja, ib, jb; cin >> ia >> ja >> ib >> jb;
  int n, m, l; cin >> n >> m >> l;
  vector<pair<char, int>> a(m), b(l);
  for(auto&& [s, a] : a) cin >> s >> a;
  for(auto&& [s, a] : b) cin >> s >> a;

  map<char, pair<int, int>> dij{{'U', {-1, 0}}, {'D', {1, 0}}, {'L', {0, -1}}, {'R', {0, 1}}};

  auto solve = [&](char s, char t, int move, int ia, int ja, int ib, int jb) -> int{
    if(s == t) return (ia == ib && ja == jb) ? move : 0;
    if(ia == ib && ja == jb) return 0;
    auto [dia, dja] = dij.at(s);
    auto [dib, djb] = dij.at(t);
    
    // 縦横が違うので、i座標が変わらない方のi座標とj~~で会うしかない
    int imeet = (dia != 0 && dib != 0 ? (ia + ib) / 2 : dia == 0 ? ia : ib);
    int jmeet = (dja != 0 && djb != 0 ? (ja + jb) / 2 : dja == 0 ? ja : jb);
    // aが(imeet, jmeet)にたどり着くのは何ターン後か？
    int turn = dia != 0 ? (imeet - ia) / dia : (jmeet - ja) / dja;
    if(turn <= 0 || turn > move || !(ia + dia * turn == ib + dib * turn && ia + dia * turn == imeet && ja + dja * turn == jb + djb * turn && ja + dja * turn == jmeet)) return 0;
    // assert(ia + dia * turn == ib + dib * turn && ia + dia * turn == imeet && ja + dja * turn == jb + djb * turn && ja + dja * turn == jmeet);
    return 1;
  };

  int ans = 0;

  auto itra = a.begin(), itrb = b.begin();
  while(itra != a.end()){
    auto& [s, a] = *itra;
    auto& [t, b] = *itrb;
    int min_move = min(a, b);
    a -= min_move; b -= min_move;
    auto [dia, dja] = dij.at(s);
    auto [dib, djb] = dij.at(t);

    // println("{}", solve(s, t, min_move, ia, ja, ib, jb));
    ans += solve(s, t, min_move, ia, ja, ib, jb);
    ia += dia * min_move; ja += dja * min_move;
    ib += dib * min_move; jb += djb * min_move;
    if(a == 0) itra++;
    if(b == 0) itrb++;
  }
  println("{}", ans);
}
