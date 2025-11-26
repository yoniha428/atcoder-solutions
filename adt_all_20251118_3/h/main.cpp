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
  vector<pair<int, int>> xy(n); for(auto&& [x, y] : xy) cin >> x >> y;
  sort(all(xy));
  vector<int> v1, v2;
  rep(j, n) rep(i, j){
    auto [xi, yi] = xy.at(i);
    auto [xj, yj] = xy.at(j);
    int dx = xj - xi, dy = yj - yi;
    if(dx < 0){
      dx *= -1;
      dy *= -1;
    }
    int key1 = (dx + 10000000) * 1000000000 + (dy + 10000000);
    v1.emplace_back(key1);
    int g = gcd(dx, dy);
    dx /= g; dy /= g;
    int key2 = (dx + 10000000) * 1000000000 + (dy + 10000000);
    v2.emplace_back(key2);
  }
  sort(all(v1)); sort(all(v2));
  vector<pair<int, int>> r1, r2;
  for(auto vi : v1){
    if(r1.empty() || vi != r1.back().first) r1.emplace_back(vi, 1);
    else r1.back().second++;
  }
  for(auto vi : v2){
    if(r2.empty() || vi != r2.back().first) r2.emplace_back(vi, 1);
    else r2.back().second++;
  }
  int sum1 = 0, sum2 = 0;
  for(auto [key, val] : r2) sum1 += val * (val - 1) / 2;
  for(auto [key, val] : r1) sum2 += val * (val - 1) / 2;
  assert(sum2 % 2 == 0);
  println("{}", sum1 - sum2 / 2);
}
