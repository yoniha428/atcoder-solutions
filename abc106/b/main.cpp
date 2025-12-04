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
  int ans = 0;
  for(int i = 1; i <= n; i += 2){
    int w = i, div = 1;
    for(int p = 2; p * p <= w; p++){
      int cnt = 0;
      while(w % p == 0){
        cnt++;
        w /= p;
      }
      div *= (cnt + 1);
    }
    if(w != 1) div *= 2;
    // if(div == 8) cout << i << '\n';
    ans += div == 8;
  }
  cout << ans << '\n';
}
