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
  int a, b, c; cin >> a >> b >> c;
  map<tuple<int, int, int>, double> memo;
  auto dfs = [&memo](auto dfs, int a, int b, int c) -> double{
    if(a == 100 || b == 100 || c == 100) return 0;
    if(!memo.contains({a, b, c})){
      double ret = 0, sum = a + b + c;
      if(a != 0) ret += (dfs(dfs, a + 1, b, c) + 1) * a / sum;
      if(b != 0) ret += (dfs(dfs, a, b + 1, c) + 1) * b / sum;
      if(c != 0) ret += (dfs(dfs, a, b, c + 1) + 1) * c / sum;
      memo.emplace(tuple<int, int, int>{a, b, c}, ret);
    }
    return memo.at({a, b, c});
  };
  cout << fixed << setprecision(30) << dfs(dfs, a, b, c) << '\n';
}
