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

#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = (int)((n) - 1); i >= 0; i--)
template <typename T> bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template <typename T> bool chmin(T &a,const T &b){if(a>b){a=b;return true;}return false;}

// using mint = modint;

signed main(){
  int n; cin >> n;
  vector<int> h(n), c(n);
  for(auto&& hi : h) cin >> hi;
  for(auto&& ci : c) cin >> ci;
  vector a(n, vector<int>(n));
  for(auto&& ai : a) for(auto&& aij : ai) cin >> aij;

  c.emplace_back(1ll << 30);
  a.emplace_back(vector<int>(n, 1));

  vector<pair<int, int>> ans_cur, ans_best;
  int score_best = 0;
  vector<int> h_cur(h), c_cur(c);
  vector<bool> usable(n + 1, false); usable.at(n) = true;
  while(*max_element(all(h_cur)) > 0){
    // 色々殴る
    int damage_max = 0, takara = -1, buki = -1;

    rep(i, n) if(h_cur.at(i) > 0 && h_cur.at(i) < 100){
      damage_max = 1;
      takara = i;
      buki = n;
      break;
    }

    if(damage_max == 0) rep(i, n){
      rep(j, n + 1) if(usable.at(j) &&
      chmax(damage_max, min(h_cur.at(i), a.at(j).at(i)))){
        takara = i;
        buki = j;
      }
    }
    
    // 実際に殴って、耐久値を減らして、得るなら武器を得る
    h_cur.at(takara) -= damage_max;
    c_cur.at(buki)--;
    if(h_cur.at(takara) == 0) usable.at(takara) = true;
    if(c_cur.at(buki) == 0) usable.at(buki) = false;

    ans_cur.emplace_back((buki == n ? -1 : buki), takara);
  }
  if(chmax(score_best, reduce(all(h)) - (int)ans_cur.size() + 1)) ans_best = ans_cur;

  for(auto&& [w, b] : ans_best) cout << w << ' ' << b << '\n';
}
/*
すべての宝石について、持っている武器のうち一番いいもので殴ったときに一番減るやつを選ぶ
武器Nを素手としてよいかも
*/
