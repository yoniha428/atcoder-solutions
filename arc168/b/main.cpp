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
  vector<int> a(n); for(auto&& ai : a) cin >> ai;
  int sum = 0;
  for(auto ai : a) sum ^= ai;
  if(sum != 0){
    cout << -1 << '\n';
    return 0;
  }
  sort(all(a), greater());
  vector<pair<int, int>> rle;
  for(auto ai : a){
    if(rle.empty() || ai != rle.back().first){
      if(!rle.empty() && rle.back().second % 2 == 1){
        cout << rle.back().first - 1 << '\n';
        return 0;
      }
      rle.emplace_back(ai, 1);
    }
    else rle.back().second++;
  }
  cout << 0 << '\n';
}
/*
普通のnimがAlice必勝、つまりxorがnon-0ならk=infとできるので-1
kを固定すると、各山のGrundy数は石の数%(k+1)
*/
