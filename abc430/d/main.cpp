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
  const int inf = 1ll << 60;
  map<int, int> mp; mp.emplace(0, inf);
  int ans = 0;
  while(n--){
    int x; cin >> x;
    auto itrr = mp.lower_bound(x);
    int diff = inf;
    if(itrr != mp.end()){
      // 右に要素がある
      int diffr = abs(x - itrr->first);
      if(diffr < itrr->second){
        if(itrr->second == inf) ans += diffr;
        else ans -= itrr->second - diffr;
        itrr->second = diffr;
      }
      chmin(diff, diffr);
    }
    if(itrr != mp.begin()){
      // 左に要素がある
      auto itrl = itrr; itrl--;
      int diffl = abs(x - itrl->first);
      if(diffl < itrl->second){
        if(itrl->second == inf) ans += diffl;
        else ans -= itrl->second - diffl;
        itrl->second = diffl;
      }
      chmin(diff, diffl);
    }
    ans += diff;
    mp.emplace(x, diff);
    println("{}", ans);
  }
}
