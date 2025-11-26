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
  string s; cin >> s;
  int cnt = 0;
  while(!s.empty() && s.back() == 'a'){
    s.pop_back();
    cnt++;
  }
  reverse(all(s));
  rep(i, cnt) if(!s.empty() && s.back() == 'a') s.pop_back();
  bool ok = true;
  rep(i, s.size()) ok &= s.at(i) == s.at(s.size() - 1 - i);
  println("{}", ok ? "Yes" : "No");
}
