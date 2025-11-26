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

using mint = modint1000000007;

signed main(){
  int h, w; cin >> h >> w;
  vector<string> s(h); for(auto&& si : s) cin >> si;
  vector<vector<mint>> imosh(h), imosw(w), imoshw(h + w - 1);
  rep(i, h) imosh.at(i).resize(w, 0);
  rep(i, w) imosw.at(i).resize(h, 0);
  rep(i, w) imoshw.at(i).resize(min({i + 1, h, w}), 0);
  rep(i, h) imoshw.at(h + w - 2 - i).resize(min({i + 1, h, w}), 0);
  imosh.at(0).at(0) = 1;
  imosh.at(0).at(1) = -1;

  // それぞれ何要素目まで.か調べる
  vector<vector<int>> doth(h), dotw(w), dothw(h + w - 1);
  rep(i, h) doth.at(i).resize(w, -1);
  rep(i, w) dotw.at(i).resize(h, -1);
  rep(i, w) dothw.at(i).resize(min({i + 1, h, w}), -1);
  rep(i, h) dothw.at(h + w - 2 - i).resize(min({i + 1, h, w}), -1);

  // cout << "init ok" << endl;

  rep(i, h){
    int l = -1;
    rep(j, w){
      if(s.at(i).at(j) == '.'){
        if(l == -1) l = j;
      }
      else if(l != -1){
        for(int k = l; k < j; k++) doth.at(i).at(k) = j;
        l = -1;
      }
    }
    if(l != -1) for(int j = l; j < w; j++) doth.at(i).at(j) = w;
  }

  // cout << "doth ok" << endl;

  rep(i, w){
    int l = -1;
    rep(j, h){
      if(s.at(j).at(i) == '.'){
        if(l == -1) l = j;
      }
      else if(l != -1){
        for(int k = l; k < j; k++) dotw.at(i).at(k) = j;
        l = -1;
      }
    }
    if(l != -1) for(int j = l; j < h; j++) dotw.at(i).at(j) = h;
  }

  // cout << "dotw ok" << endl;
  
  rep(i, h + w - 1){
    int l = -1;
    rep(j, dothw.at(i).size()){
      if(s.at((i < w ? 0 : i - (w - 1)) + j).at((i < w ? w - 1 - i : 0) + j) == '.'){
        if(l == -1) l = j;
      }
      else if(l != -1){
        for(int k = l; k < j; k++) dothw.at(i).at(k) = j;
        l = -1;
      }
    }
    if(l != -1) for(int j = l; j < (int)dothw.at(i).size(); j++) dothw.at(i).at(j) = dothw.at(i).size();
  }

  // rep(i, h){
  //   rep(j, w) print("{} ", doth.at(i).at(j));
  //   println();
  // }
  // println();
  // rep(i, h){
  //   rep(j, w) print("{} ", dotw.at(j).at(i));
  //   println();
  // }
  // println();
  // rep(i, h){
  //   rep(j, w) print("{} ", dothw.at(i - j + w - 1).at(min(i, j)));
  //   println();
  // }
  // println();

  // cout << "dot ok" << endl;

  vector<mint> nowh(h, 0), noww(w, 0), nowhw(h + w - 1, 0);
  rep(i, h) rep(j, w){
    // cout << format("pre i = {}, j = {}", i, j) << endl;

    nowh.at(i) += imosh.at(i).at(j);
    noww.at(j) += imosw.at(j).at(i);
    nowhw.at(i - j + w - 1) += imoshw.at(i - j + w - 1).at(min(i, j));

    mint sum = nowh.at(i) + noww.at(j) + nowhw.at(i - j + w - 1);
    // println("i = {}, j = {}, sum = {}", i, j, sum.val());
    if(i == h - 1 && j == w - 1) cout << sum.val() << '\n';

    // cout << "doth" << endl;
    if(doth.at(i).at(j) != -1){
      if(doth.at(i).at(j) != j + 1){
        imosh.at(i).at(j + 1) += sum;
        if(doth.at(i).at(j) != w) imosh.at(i).at(doth.at(i).at(j)) -= sum;
      }
    }
    // cout << "dotw" << endl;
    if(dotw.at(j).at(i) != -1){
      if(dotw.at(j).at(i) != i + 1){
        imosw.at(j).at(i + 1) += sum;
        if(dotw.at(j).at(i) != h) imosw.at(j).at(dotw.at(j).at(i)) -= sum;
      }
    }
    // cout << "dothw" << endl;
    if(dothw.at(i - j + w - 1).at(min(i, j)) != -1){
      if(dothw.at(i - j + w - 1).at(min(i, j)) != min(i, j) + 1){
        imoshw.at(i - j + w - 1).at(min(i, j) + 1) += sum;
        if(dothw.at(i - j + w - 1).at(min(i, j)) != (int)dothw.at(i - j + w - 1).size()) imoshw.at(i - j + w - 1).at(dothw.at(i - j + w - 1).at(min(i, j))) -= sum;
      }
    }
  }
}
/*
imos？
縦横斜めそれぞれで個別にimosしそう

i-j+w-1でどう？
*/
