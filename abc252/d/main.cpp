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
  vector<int> cnt(200000, 0);
  rep(i, n){
    int a; cin >> a; a--;
    cnt.at(a)++;
  }
  int ans = n * (n - 1) * (n - 2) / 6;
  for(auto i : cnt){
    // 自分2つ、他1つor自分3つ
    ans -= i * (i - 1) / 2 * (n - i) + i * (i - 1) * (i - 2) / 6;
  }
  cout << ans << '\n';
}
