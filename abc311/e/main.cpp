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
  int h, w, n; cin >> h >> w >> n;
  vector hole(h, vector<bool>(w, false));
  while(n--){
    int a, b; cin >> a >> b; a--; b--;
    hole.at(a).at(b) = true;
  }
  vector presum(h + 1, vector<int>(w + 1, 0)); // 穴の数
  rep(i, h) rep(j, w){
    presum.at(i + 1).at(j + 1) = presum.at(i).at(j + 1) + presum.at(i + 1).at(j) - presum.at(i).at(j) + hole.at(i).at(j);
  }
  int ans = 0;
  rep(i, h) rep(j, w){
    if(hole.at(i).at(j)) continue;
    int lo = 1, hi = min(h - i, w - j) + 1;
    while(hi - lo > 1){
      int mid = (lo + hi) / 2;
      int sum = presum.at(i + mid).at(j + mid) - presum.at(i).at(j + mid) - presum.at(i + mid).at(j) + presum.at(i).at(j);
      (sum == 0 ? lo : hi) = mid;
    }
    ans += lo;
  }
  cout << ans << '\n';
}
/*
i, jを全探索、nを二分探索するとよさそう
*/
