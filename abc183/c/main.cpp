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
  vector t(n, vector<int>(n));
  for(auto&& ai : t) for(auto&& aij : ai) cin >> aij;
  vector<int> per(n - 1); rep(i, n - 1) per.at(i) = i + 1;
  int ans = 0;
  do{
    int sum = t.at(0).at(per.at(0)) + t.at(per.at(n - 2)).at(0);
    rep(i, n - 2) sum += t.at(per.at(i)).at(per.at(i + 1));
    ans += sum == k;
  }while(next_permutation(all(per)));
  cout << ans << '\n';
}
