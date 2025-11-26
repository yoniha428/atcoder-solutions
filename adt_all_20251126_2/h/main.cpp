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
  int n, q; cin >> n >> q;
  vector<bool> f(n, false);
  vector change(n, vector<int>());
  vector<int> presum(q + 1, 0);
  int cnt = 0;
  rep(i, q){
    int x; cin >> x; x--;
    if(f.at(x)){
      cnt--;
      f.at(x) = false;
    }
    else{
      cnt++;
      f.at(x) = true;
    }
    change.at(x).emplace_back(i);
    presum.at(i + 1) = presum.at(i) + cnt;
  }
  // rep(i, q + 1) println("{}", presum.at(i));
  rep(i, n) if(change.at(i).size() % 2) change.at(i).emplace_back(q);
  // rep(i, n){
  //   for(auto j : change.at(i)) print("{} ", j);
  //   println();
  // }
  rep(i, n){
    int sum = 0;
    rep(j, change.at(i).size() / 2) sum += presum.at(change.at(i).at(2 * j + 1)) - presum.at(change.at(i).at(2 * j));
    println("{}", sum);
  }
}
