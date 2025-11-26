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
  vector<bool> mask(30);

  auto dfs = [&](this auto dfs, vector<int> zero, vector<int> one, int bit) -> bool {
    bool zero_ok = false, one_ok = false;
    if(!zero.empty()){
      bool same = true;
      for(auto i : zero) same &= (a.at(i) >> bit & 1) == (a.at(zero.at(0)) >> bit & 1);
      zero_ok = same;
    }
    if(!one.empty()){
      bool same = true;
      for(auto i : zero) same &= (a.at(i) >> bit & 1) == (a.at(zero.at(0)) >> bit & 1);
      one_ok = same;
    }
    if(zero_ok != one_ok){
      return one_ok;
    }
    vector<int> zero_new, one_new;
  };
  rrep(bit, 30){
    bool same = true;
    for(auto ai : a) same &= (ai >> bit & 1) == (a.at(0) >> bit & 1);
    if(same) mask.at(bit) = a.at(0) >> bit & 1;
    else{
      vector<int> zero, one;
      rep(i, n) (a.at(i) >> bit & 1 ? one : zero).emplace_back(i);
      mask.at(bit) = dfs(zero, one, bit);
    }
  }
}
/*
上のbitから順に「全部0にできるか？」を考える
できない場合は、2つのグループに別れる
2つのグループのうち、より左のbitで全部0にできるグループのbitを立てるのがよい

今のところ1にする予定のベクトルを関数に投げる？
*/
