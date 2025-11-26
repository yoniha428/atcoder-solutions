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
  if(n != m){
    cout << "No" << '\n';
    return 0;
  }
  dsu d(n);
  vector<int> cnt(n, 0);
  while(m--){
    int a, b; cin >> a >> b; a--; b--;
    cnt.at(a)++; cnt.at(b)++;
    d.merge(a, b);
  }
  bool ok = d.groups().size() == 1;
  for(auto i : cnt) ok &= i == 2;
  cout << (ok ? "Yes" : "No") << '\n';
}
