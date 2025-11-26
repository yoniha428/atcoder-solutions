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
  int n, m; cin >> n >> m;
  vector d(n, vector<int>(n, -1)); d.at(0).at(0) = 0;
  deque<pair<int, int>> bfs; bfs.emplace_back(0, 0);
  auto isqrt = [](int x){
    int ret = sqrt(x);
    while(ret * ret <= x) ret++;
    while(ret * ret > x) ret--;
    // println("sqrt({}) = {}", x, ret);
    return ret;
  };
  while(!bfs.empty()){
    auto [fi, fj] = bfs.front(); bfs.pop_front();
    rep(ti, n){
      // (ti - fi) * (ti - fi) + (tj - fj) * (tj - fj) == mとなる必要がある
      int target = m - (ti - fi) * (ti - fi);
      if(target < 0) continue;
      int sq = isqrt(target);
      if(sq * sq != target) continue;
      // println("{} {} {} {}", fi, fj, ti, sq);
      // tj - fj = sq あるいは tj - fj = -sq
      for(auto tj : {fj - sq, fj + sq}){
        // println("{} {} {} {}", fi, fj, ti, fj);
        if(tj < 0 || tj >= n || d.at(ti).at(tj) != -1) continue;
        d.at(ti).at(tj) = d.at(fi).at(fj) + 1;
        bfs.emplace_back(ti, tj);
        // println("{} {}", ti, tj);
      }
    }
  }
  // println();
  for(auto&& ai : d){
    for(auto aij : ai) print("{} ", aij);
    println();
  }
}
