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
  int n, m; cin >> n >> m;
  vector<bool> ac(n, false);
  vector<int> wa(n, 0);
  int pena = 0;
  while(m--){
    int p; string s; cin >> p >> s; p--;
    if(s == "AC"){
      if(!ac.at(p)) pena += wa.at(p);
      ac.at(p) = true;
    }
    else{
      wa.at(p)++;
    }
  }
  cout << reduce(all(ac), 0ll) << ' ' << pena << '\n';
}
