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
  int h, w; cin >> h >> w;
  vector<string> s(h); for(auto&& si : s) cin >> si;
  vector cnt(h + w, vector<int>(26, 0));
  vector<int> kind(h + w);
  deque<int> q;
  rep(i, h){
    for(auto& c : s.at(i)){
      if(cnt.at(i).at(c - 'a') == 0) kind.at(i)++;
      cnt.at(i).at(c - 'a')++;
    }
    if(kind.at(i) == 1) q.emplace_back(i);
  }
  rep(j, w){
    rep(i, h){
      char c = s.at(i).at(j);
      if(cnt.at(h + j).at(c - 'a') == 0) kind.at(h + j)++;
      cnt.at(h + j).at(c - 'a')++;
    }
    if(kind.at(h + j) == 1) q.emplace_back(h + j);
  }
  while(!q.empty()){
    auto x = q.front(); q.pop_front();
    cout << x << '\n';
    if(x >= h){
      int j = x - h;
      int cnti = 0;
      rep(i, h) cnti += s.at(i).at(j) != '-';
      if(cnti >= 2){
        rep(i, h){
          char& c = s.at(i).at(j);
          if(c != '-'){
            cnt.at(i).at(c - 'a')--;
            if(cnt.at(i).at(c - 'a') == 0){
              kind.at(i)--;
              if(kind.at(i) == 1) q.emplace_back(i);
            }
            c = '-';
          }
        }
      }
    }
    else{
      int i = x;
      int cnti = 0;
      rep(j, w) cnti += s.at(i).at(j) != '-';
      if(cnti >= 2){
        rep(j, w){
          char& c = s.at(i).at(j);
          if(c != '-'){
            cnt.at(j + h).at(c - 'a')--;
            if(cnt.at(j + h).at(c - 'a') == 0){
              if(kind.at(j + h) == 1) q.emplace_back(j + h);
              kind.at(j + h)--;
            }
            c = '-';
          }
        }
      }
    }
  }
  int ans = 0;
  rep(i, h) rep(j, w) ans += s.at(i).at(j) != '-';
  cout << ans << '\n';
}
/*
種類数でソートみたいなことできないかしら

i行目をi、j列目をh+jとして表す
*/
