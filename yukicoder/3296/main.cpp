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
  vector<bool> isprime(100001, true);
  vector<int> prime;
  for(int p = 2; p * p <= n; p++){
    if(!isprime.at(p)) continue;
    prime.emplace_back(p);
    for(int i = 2; i * i * p * p <= n; i++) isprime.at(i * p) = false;
  }
  int ans = 0;
  for(auto p : prime){
    for(int w = p * p; w <= n; w *= p) ans += w;
  }
  cout << ans << '\n';
}
