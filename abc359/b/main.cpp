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
  vector a(n, vector<int>());
  rep(i, 2 * n){
    int ai; cin >> ai; ai--;
    a.at(ai).emplace_back(i);
  }
  int ans = 0;
  for(auto ai : a){
    int a0 = ai.at(0), a1 = ai.at(1);
    ans += abs(a0 - a1) == 2;
  }
  cout << ans << '\n';
}
