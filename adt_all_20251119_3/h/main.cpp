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
  vector<int> a(n); for(auto&& ai : a) cin >> ai, ai--;
  vector index(n, vector<int>{-1});
  rep(i, n) index.at(a.at(i)).emplace_back(i);
  int ans = 0;
  rep(i, n){
    for(int j = 1; j < (int)index.at(i).size(); j++){
      ans += (index.at(i).at(j) - (index.at(i).at(j - 1))) * 
             (n - (index.at(i).at(j)));
    }
    // println("{}", ans);
  }
  println("{}", ans);
}
/*
主客転倒っぽい？
どんなi, jに対して自分が答えに寄与するかを考える
iは自分の左にある自分と同じ値のインデックス+1から、自分のインデックスまで
jは自分のインデックスから、自分の右にある自分と同じ値のインデックス-1まで
*/
