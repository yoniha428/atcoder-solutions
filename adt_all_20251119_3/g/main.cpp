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
  int n, a, b; cin >> n >> a >> b;
  int l = lcm(a, b);
  auto f = [](int a){return a * (a + 1) / 2;};
  println("{}", f(n) - f(n / a) * a - f(n / b) * b + f(n / l) * l);
}
/*
aの倍数+bの倍数-aの倍数かつbの倍数

0+a+2a+...+n/a*a

 + f(n / b) * b - f(n / l) * l
*/