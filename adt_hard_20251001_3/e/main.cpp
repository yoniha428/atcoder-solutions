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
  int n; cin >> n;
  vector<int> odd, even;
  while(n--){
    int a; cin >> a;
    (a % 2 == 0 ? even : odd).emplace_back(a);
  }
  sort(all(odd)); sort(all(even));
  int ans = -1;
  if(odd.size() >= 2) chmax(ans, odd.at(odd.size() - 1) + odd.at(odd.size() -2));
  if(even.size() >= 2) chmax(ans, even.at(even.size() - 1) + even.at(even.size() -2));
  cout << ans << '\n';
}
