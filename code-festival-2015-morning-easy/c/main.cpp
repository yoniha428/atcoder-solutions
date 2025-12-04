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
  int n, k, m, r; cin >> n >> k >> m >> r;
  vector<int> s(n - 1); for(auto&& si : s) cin >> si;
  sort(all(s), greater());
  int sum = 0; rep(i, k - 1) sum += s.at(i);
  if(sum + m < r * k){
    cout << -1 << '\n';
    return 0;
  }
  if(k != n){
    sum += s.at(k - 1);
    if(sum >= r * k){
      cout << 0 << '\n';
      return 0;
    }
    sum -= s.at(k - 1);
  }
  cout << max(0ll, r * k - sum) << '\n';
}
