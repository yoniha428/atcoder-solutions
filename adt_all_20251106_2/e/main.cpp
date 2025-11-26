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
  map<int, int> mp;
  int q; cin >> q;
  while(q--){
    int op; cin >> op;
    if(op == 1){
      int x; cin >> x;
      if(mp.contains(x)) mp.at(x)++;
      else mp.emplace(x, 1);
    }
    if(op == 2){
      int x, c; cin >> x >> c;
      if(!mp.contains(x)) continue;
      if(mp.at(x) <= c) mp.erase(x);
      else mp.at(x) -= c;
    }
    if(op == 3){
      println("{}", (--mp.end())->first - mp.begin()->first);
    }
  }
}
