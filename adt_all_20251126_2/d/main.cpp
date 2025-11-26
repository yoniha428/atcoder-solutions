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
  int n, x, y, z; cin >> n >> x >> y >> z;
  vector<pair<int, int>> a(n), b(n), sum(n);
  rep(i, n){
    auto&& [val, idx] = a.at(i);
    cin >> val; val *= -1;
    idx = i;
  }
  rep(i, n){
    auto&& [val, idx] = b.at(i);
    cin >> val; val *= -1;
    idx = i;
  }
  rep(i, n){
    auto&& [val, idx] = sum.at(i);
    val = a.at(i).first + b.at(i).first;
    idx = i;
  }
  sort(all(a)); sort(all(b)); sort(all(sum));
  vector<bool> f(n, false);
  int cnt = 0;
  for(auto [val, idx] : a){
    if(cnt == x) break;
    if(f.at(idx)) continue;
    f.at(idx) = true;
    cnt++;
  }
  cnt = 0;
  for(auto [val, idx] : b){
    if(cnt == y) break;
    if(f.at(idx)) continue;
    f.at(idx) = true;
    cnt++;
  }
  cnt = 0;
  for(auto [val, idx] : sum){
    if(cnt == z) break;
    if(f.at(idx)) continue;
    f.at(idx) = true;
    cnt++;
  }
  rep(i, n) if(f.at(i)) println("{}", i + 1);
}
