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
  int n, m, c; cin >> n >> m >> c;
  vector<int> a(n); for(auto&& ai : a) cin >> ai;
  map<int, int> mp;
  for(auto& ai : a){
    if(mp.contains(ai)) mp.at(ai)++;
    else mp.emplace(ai, 1);
  }
  int sum = 0;
  auto itrr = mp.begin();
  while(sum < c){
    sum += itrr->second;
    itrr++;
    if(itrr == mp.end()) itrr = mp.begin();
  }
  int ans = sum * (mp.begin()->first + m - (--mp.end())->first);
  // cout << ans << '\n';
  for(auto itrl = mp.begin(); itrl != mp.end(); itrl++){
    // itrのところをなしにして、その分を補充する
    sum -= itrl->second;
    while(sum < c){
      sum += itrr->second;
      itrr++;
      if(itrr == mp.end()) itrr = mp.begin();
    }
    auto itrl_next = itrl; itrl_next++;
    if(itrl_next == mp.end()) break;
    ans += (itrl_next->first - itrl->first) * sum;
  }
  cout << ans << '\n';
}
/*
人を通り過ぎた後にだけ答えが変わる
尺取りみたいにできる？
*/
