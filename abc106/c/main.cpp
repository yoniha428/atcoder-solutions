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
  string s; int k; cin >> s >> k; k--;
  // 1でない数が最初に出てくるのはいつか
  int nonone = -1;
  rep(i, s.size()) if(s.at(i) != '1'){
    nonone = i;
    break;
  }
  // cout << nonone << ' ' << k << '\n';
  if(nonone != -1 && nonone <= k) cout << s.at(nonone) << '\n';
  else cout << 1 << '\n';
}
