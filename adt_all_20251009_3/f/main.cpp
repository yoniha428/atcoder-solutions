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
  int inf = 1ll << 60;
  vector g(n, vector<int>(n, inf));
  while(m--){
    int a, b, c; cin >> a >> b >> c;
    a--; b--;
    g.at(a).at(b) = c;
    g.at(b).at(a) = c;
  }
  vector<int> per(n); rep(i, n) per.at(i) = i;
  int ans = 0;
  do{
    int sum = 0;
    rep(i, n - 1){
      if(g.at(per.at(i)).at(per.at(i + 1)) == inf) break;
      sum += g.at(per.at(i)).at(per.at(i + 1));
    }
    chmax(ans, sum);
  }while(next_permutation(all(per)));
  println("{}", ans);
}
