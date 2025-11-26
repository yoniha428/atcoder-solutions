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
  string r, c; cin >> r >> c;

  vector<vector<string>> possible(n);
  string w = "ABC";
  rep(i, n - 3) w += '.';
  sort(all(w));
  rep(i, n){
    do{
      char first = '.';
      for(auto c : w) if(c != '.'){
        first = c;
        break;
      }
      if(first == r.at(i)) possible.at(i).emplace_back(w);
    }while(next_permutation(all(w)));
    // println("{}", w);
  }

  int size = 1; for(auto&& i : possible) size *= i.size();
  // println("{}", size);
  rep(bit, size){
    vector<string> ans(n);
    int bitw = bit;
    rep(j, n){
      ans.at(j) = possible.at(j).at(bitw % possible.at(j).size());
      bitw /= possible.at(j).size();
    }

    // これが条件を満たしているか見る
    bool ok = true;
    rep(j, n){
      char first = '.';
      rep(i, n) if(ans.at(i).at(j) != '.'){
        first = ans.at(i).at(j);
        break;
      }
      ok &= first == c.at(j);
      vector<int> cnt(3, 0);
      rep(i, n) if(ans.at(i).at(j) != '.') cnt.at(ans.at(i).at(j) - 'A')++;
      for(auto&& i : cnt) ok &= i == 1;
    }

    if(ok){
      println("Yes");
      for(auto&& i : ans) println("{}", i);
      return 0;
    }
  }

  println("No");
}
/*
例えばi行目の最初の文字がAなら、A...., .A..., ..A..のみを調べれば良い
*/