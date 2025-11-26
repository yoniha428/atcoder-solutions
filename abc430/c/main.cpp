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
  int n, a, b; string s; cin >> n >> a >> b >> s;
  vector<int> suma(n + 1, 0), sumb(suma);
  rep(i, n){
    suma.at(i + 1) = suma.at(i) + (s.at(i) == 'a');
    sumb.at(i + 1) = sumb.at(i) + (s.at(i) == 'b');
  }
  int ans = 0;
  rep(i, n){
    int al = i, ar = n + 1;
    while(ar - al > 1){
      int mid = (al + ar) / 2;
      (suma.at(mid) - suma.at(i) >= a ? ar : al) = mid;
    }
    int bl = i, br = n + 1;
    while(br - bl > 1){
      int mid = (bl + br) / 2;
      (sumb.at(mid) - sumb.at(i) >= b ? br : bl) = mid;
    }
    ans += max(0ll, bl - al);
  }
  println("{}", ans);
}
