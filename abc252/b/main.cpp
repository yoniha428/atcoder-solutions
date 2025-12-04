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
  vector<int> a(n); for(auto&& ai : a) cin >> ai;
  vector<bool> hate(n, false);
  while(k--){
    int b; cin >> b; b--;
    hate.at(b) = true;
  }
  int amax = *max_element(all(a));
  bool ans = false;
  rep(i, n) ans |= a.at(i) == amax && hate.at(i);
  cout << (ans ? "Yes" : "No") << '\n';
}
