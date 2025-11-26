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
  int n; string s; cin >> n >> s;
  vector<bool> f(3, false);
  int cnt = 0;
  rep(i, n){
    if(!f.at(s.at(i) - 'A')) cnt++;
    f.at(s.at(i) - 'A') = true;
    if(cnt == 3){
      cout << i + 1 << '\n';
      return 0;
    }
  }
}
