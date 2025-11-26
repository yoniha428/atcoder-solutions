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
  int n, m; cin >> n >> m;
  vector<int> x(n), y(m);
  for(auto&& xi : x) cin >> xi, xi--;
  for(auto&& yi : y) cin >> yi, yi--;
  vector<int> xinv(n * m, -1), yinv(n * m, -1);
  rep(i, n){
    if(xinv.at(x.at(i)) != -1){
      println("No");
      return;
    }
    xinv.at(x.at(i)) = i;
  }
  rep(i, m){
    if(yinv.at(y.at(i)) != -1){
      println("No");
      return;
    }
    yinv.at(y.at(i)) = i;
  }
  // println("initialized");
  
  vector<bool> xactive(n, false), yactive(m, false);
  vector<set<int>> activeij(n), activeji(m);
  vector<set<int>> activei(m), activej(n);
  set<pair<int, int>> active;
  vector ans(n, vector<int>(m, -1));

  auto write = [&](int i, int j, int val){
    ans.at(i).at(j) = val;
    if(!xactive.at(i)){
      xactive.at(i) = true;
      rep(jj, m){
        if(yactive.at(jj)){
          activej.at(i).erase(jj);
          activeij.at(i).emplace(jj);
          activeji.at(jj).emplace(i);
          active.emplace(i, jj);
        }
        else activei.at(jj).emplace(i);
      }
    }
    if(!yactive.at(j)){
      yactive.at(j) = true;
      rep(ii, n){
        if(xactive.at(ii)){
          activei.at(j).erase(ii);
          activeij.at(ii).emplace(j);
          activeji.at(j).emplace(ii);
          active.emplace(ii, j);
        }
        else activej.at(ii).emplace(j);
      }
    }
    if(activei.at(j).contains(i)) activei.at(j).erase(i);
    if(activej.at(i).contains(j)) activej.at(i).erase(j);
    if(activeij.at(i).contains(j)) activeij.at(i).erase(j);
    if(activeji.at(j).contains(i)) activeji.at(j).erase(i);
    if(active.contains({i, j})) active.erase({i, j});
  };

  rrep(val, n * m){
    // println("val = {}", val + 1);
    // rep(i, n){
    //   rep(j, m) print("{} ", ans.at(i).at(j) + 1);
    //   println();
    // }
    
    int i = xinv.at(val), j = yinv.at(val);
    if(i != -1 && j != -1){
      write(i, j, val);
    }

    else if(i != -1 || j != -1){
      if(i != -1){
        if(!activej.at(i).empty()){
          int jj = *activej.at(i).begin();
          write(i, jj, val);
        }
        else{
          if(activeij.at(i).empty()){
            println("No");
            return;
          }
          int jj = *activeij.at(i).begin();
          write(i, jj, val);
        }
      }
      if(j != -1){
        if(!activei.at(j).empty()){
          int ii = *activei.at(j).begin();
          write(ii, j, val);
        }
        else{
          if(activeji.at(j).empty()){
            println("No");
            return;
          }
          int jj = *activeij.at(i).begin();
          write(i, jj, val);
        }
      }
    }
    else{
      if(active.empty()){
        println("No");
        return;
      }
      auto [ii, jj] = *active.begin();
      write(ii, jj, val);
    }
  }

  println("Yes");
  rep(i, n){
    rep(j, m) print("{} ", ans.at(i).at(j) + 1);
    println();
  }
}

signed main(){
  int t; cin >> t;
  while(t--) solve();
}
/*
値が大きい方から順に見ると？
XにもYにもあるなら、それが交差するところに置くしかない
自分より大きいのを置いていない行or列に置いちゃだめ

iもjも指定されているとき、そこに置ける
iが指定されているとき、(i, j)の中に「jが」activeなマスが必要
jが指定されているとき、(i, j)の中に「iが」activeなマスが必要
どちらも指定されていないとき、iもjもactiveなマスが必要

置いたとき、iもjもactiveになる

条件を満たすどんなマスに置いてもYesNoが変わらないか？
どちらかのみ指定されているときは、どちらかがactiveになっていないマスを選んだほうが得
iが指定されているならjがactiveかつiがactiveでないマスを選んだほうが良い
*/
