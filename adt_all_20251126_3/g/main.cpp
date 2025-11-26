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
  int ai, aj, bi, bj; cin >> ai >> aj >> bi >> bj;
  int n, m, l; cin >> n >> m >> l;
  vector<pair<char, int>> amove(m), bmove(l);
  for(auto&& [c, len] : amove) cin >> c >> len;
  for(auto&& [c, len] : bmove) cin >> c >> len;

  auto aitr = amove.begin(), bitr = bmove.begin();
  int ans = 0;
  auto dij = [](char dir) -> pair<int, int>{
    if(dir == 'U') return {-1, 0};
    if(dir == 'D') return {1, 0};
    if(dir == 'L') return {0, -1};
    if(dir == 'R') return {0, 1};
  };
  while(aitr != amove.end()){
    auto&& [adir, alen] = *aitr;
    auto&& [bdir, blen] = *bitr;
    int len = min(alen, blen);
    auto [dia, dja] = dij(adir);
    auto [dib, djb] = dij(bdir);

    int ti = -2, tj = -2; // -1はany、-2はno
    if(dib - dia == 0 && ai == bi) ti = -1;
    if(djb - dja == 0 && aj == bj) tj = -1;
    if(dib - dia != 0 && (ai - bi) % (dib - dia) == 0){
      int t = (ai - bi) / (dib - dia);
      ti = (t > 0 && t <= len ? t : -2);
    }
    if(djb - dja != 0 && (aj - bj) % (djb - dja) == 0){
      int t = (aj - bj) / (djb - dja);
      tj = (t > 0 && t <= len ? t : -2);
    }
    // println("{} {} {} {} {} {}", ai, aj, bi, bj, ti, tj);
    if(ti == -1 && tj == -1) ans += len;
    else if((ti == -1 || tj == -1 || ti == tj) && ti != -2 && tj != -2) ans++;

    ai += len * dia; aj += len * dja;
    bi += len * dib; bj += len * djb;
    alen -= len;
    blen -= len;
    if(alen == 0) aitr++;
    if(blen == 0) bitr++;
  }
  println("{}", ans);
}
/*
移動方向が同じときは、場所が同じならlen, そうでないなら0
移動方向が違うときは、
ai+t*di[adir]=bi+t*di[bdir]かつ
aj+t*dj[adir]=bj+t*dj[bdir]
となるt∈{1, 2, ..., len}があるなら1, そうでないなら0

tについて解くと、
ai-bi=t*(di[bdir]-di[adir])
*/
