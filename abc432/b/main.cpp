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
  string x; cin >> x;
  sort(all(x));
  int ans = 1ll << 60;
  do{
    if(x.at(0) == '0') continue;
    int val = 0;
    for(auto c : x){
      val *= 10;
      val += c - '0';
    }
    chmin(ans, val);
  }while(next_permutation(all(x)));
  println("{}", ans);
}
