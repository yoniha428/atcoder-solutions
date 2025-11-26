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

void solve(){
  int n; string s; cin >> n >> s;
  vector<pair<char, int>> rle;
  for(auto c : s){
    if(rle.empty() || rle.back().first != c) rle.emplace_back(c, 1);
    else rle.back().second++;
  }
  if(rle.size() == 1){
    cout << 0 << '\n';
    return;
  }
  vector<int> presum1(n + 1, 0), presum0(presum1);
  rep(i, n){
    presum1.at(i + 1) = presum1.at(i) + (s.at(i) == '1');
    presum0.at(i + 1) = presum0.at(i) + (s.at(i) == '0');
  }
  int sum = 0, ans = 1ll << 60;
  for(auto [c, cnt] : rle){
    if(c == '1') chmin(ans, sum + (n - (sum + cnt)) + presum1.at(sum) + (presum1.at(n) - presum1.at(sum + cnt)));
    if(c == '0') chmin(ans, sum + (n - (sum + cnt)) + presum0.at(sum) + (presum0.at(n) - presum0.at(sum + cnt)));
    sum += cnt;
  }
  cout << ans << '\n';
}

signed main(){
  int t; cin >> t;
  while(t--) solve();
}
/*
例えば1にするとして
元が0なら変更して真ん中に入れる
元が1なら変更して先頭に入れて、変更して真ん中に入れる
*/
