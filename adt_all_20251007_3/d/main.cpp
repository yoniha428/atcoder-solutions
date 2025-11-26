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
  int x, y; cin >> x >> y;
  vector<int> ans(10); ans.at(0) = x; ans.at(1) = y;
  rep(i, 8){
    string s = to_string(ans.at(i) + ans.at(i + 1));
    reverse(all(s));
    ans.at(i + 2) = stoll(s);
  }
  println("{}", ans.at(9));
}
