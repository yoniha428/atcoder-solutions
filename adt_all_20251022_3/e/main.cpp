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
  int h, w; cin >> h >> w;
  vector<string> s(w), t(w);
  rep(i, h){
    string u; cin >> u;
    rep(i, w) s.at(i) += u.at(i);
  }
  rep(i, h){
    string u; cin >> u;
    rep(i, w) t.at(i) += u.at(i);
  }
  sort(all(s)); sort(all(t));
  cout << (s == t ? "Yes" : "No") << '\n';
}
