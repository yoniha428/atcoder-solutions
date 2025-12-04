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
  int first = -1, second = -1;
  string s_first, s_second;
  while(n--){
    string s; int t; cin >> s >> t;
    if(t > first){
      second = first;
      first = t;
      s_second = s_first;
      s_first = s;
    }
    else if(t > second){
      second = t;
      s_second = s;
    }
  }
  cout << s_second << '\n';
}
