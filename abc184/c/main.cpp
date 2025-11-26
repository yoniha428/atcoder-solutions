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
  int a, b, c, d; cin >> a >> b >> c >> d;
  if(a == c && b == d){
    cout << 0 << '\n';
    return 0;
  }
  if(a + b == c + d || a - b == c - d || abs(a - c) + abs(b - d) <= 3){
    cout << 1 << '\n';
    return 0;
  }
  bool f = (a + b) % 2 == (c + d) % 2;
  for(int i = a - 3; i <= a + 3; i++) for(int j = b - 3; j <= b + 3; j++){
    if(abs(a - i) + abs(b - j) > 3) continue;
    f |= i + j == c + d || i - j == c - d || abs(i - c) + abs(j - d) <= 3;
  }
  cout << (f ? 2 : 3) << '\n';
}
