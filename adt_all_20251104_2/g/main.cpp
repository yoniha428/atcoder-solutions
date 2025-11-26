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
  int n, k; cin >> n >> k;
  vector<int> a(n); for(auto&& ai : a) cin >> ai;
  map<int, int> cnt;
  int sum = 0, ans = 0;
  cnt.emplace(sum, 1);
  for(auto ai : a){
    sum += ai;
    if(cnt.contains(sum - k)) ans += cnt.at(sum - k);
    if(cnt.contains(sum)) cnt.at(sum)++;
    else cnt.emplace(sum, 1);
  }
  println("{}", ans);
}
/*
sum - x = kとなるxを探す
x = sum - k
*/
