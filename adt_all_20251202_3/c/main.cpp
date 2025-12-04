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
  string s; cin >> s;
  vector<int> cnt(26, 0);
  for(auto c : s) cnt.at(c - 'a')++;
  vector<int> cnt2(s.size(), 0);
  for(auto i : cnt) if(i != 0) cnt2.at(i - 1)++;
  for(auto i : cnt2) if(i != 0 && i != 2){
    println("No");
    return 0;
  }
  println("Yes");
}
