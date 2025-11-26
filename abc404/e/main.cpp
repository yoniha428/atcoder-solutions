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
  int n; cin >> n; n--;
  vector<int> c(n); for(auto&& i : c) cin >> i;
  vector<bool> a(n);
  for(auto&& i : a){
    int w; cin >> w;
    i = w;
  }
  int ans = 0;
  rrep(i, n){
    if(!a.at(i)) continue;
    ans++;
    if(c.at(i) == i + 1) continue;
    bool find = false;
    for(int j = i - c.at(i); j < i; j++) find |= a.at(j);
    if(find) continue;
    int to = -1, min_j = i;
    for(int j = i - c.at(i); j < i; j++) if(chmin(min_j, j - c.at(j))) to = j;
    a.at(to) = true;
  }
  cout << ans << '\n';
}
