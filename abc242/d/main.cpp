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
  auto f = [&](auto f, int i, int j) -> char{
    if(i == 0) return s.at(j);
    if(j == 0) return char('A' + (s.at(0) - 'A' + i) % 3);
    return char('A' + (f(f, i - 1, j / 2) - 'A' + j % 2 + 1) % 3); 
  };
  int q; cin >> q;
  while(q--){
    int t, k; cin >> t >> k; k--;
    cout << f(f, t, k) << '\n';
  }
}
/*
s^(i)[j] = f(s^(i-1)[j/2], j%2)

*/