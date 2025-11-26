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
  vector<int> a(n), b(m);
  vector f(m, vector<bool>(n, false));
  for(auto&& ai : a) cin >> ai;
  rep(i, m){
    cin >> b.at(i);
    int c; cin >> c;
    while(c--){
      int j; cin >> j; j--;
      f.at(i).at(j) = true;
    }
  }
  vector<bool> per(n, false); rep(i, 9) per.at(n - 1 - i) = true;
  int ans = 0;
  do{
    int sum = 0;
    rep(i, n) if(per.at(i)) sum += a.at(i);
    rep(i, m){
      int cnt = 0;
      rep(j, n) if(per.at(j)) cnt += f.at(i).at(j);
      if(cnt >= 3) sum += b.at(i);
    }
    chmax(ans, sum);
  }while(next_permutation(all(per)));
  cout << ans << '\n';
}
