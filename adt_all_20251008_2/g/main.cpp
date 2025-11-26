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
  
}
/*
3 -1  1 -2  2  3
0 -4 -2 -2  2  3
0  0  2  2  2  3
0  0  0  0  0  3
0  0  0 -3 -3  0
0  0  3  0  0  0
-3 -3 0  0  0  0
0  0  3  0  0  0
0  0  0  -3 -3 0

区間和がkの倍数であることは必要だか十分でない
右のk-1要素を除いてすべて0にできる
左のn-k+1要素を0にしたときに右のk-1要素が0になるためには？
k=3として、
a0 a1 a2 a3
0 a1-a0 a2-a0 a3
0 0 (a2-a0)-(a1-a0) a3-(a1-a0)
0 0 a2-a1 a3-a1+a0

k=2だと
a0 a1 a2 a3
0 a1-a0 a2 a3
0 0 a2-(a1-a0) a3
0 0 0 a3-(a2-a1+10)

逆に0から作るためには
k=3として
0 0 0 0
a0 a0 a0 0
a0 a1 a1 a1-a0

k=2として
0 0 0 0
a0 a0 0 0
a0 a1 a1-a0 0
a0 a1 a2 a2-(a1-a0)=a2-a1+10

k=4
0 0 0 0 0
a0 a0 a0 a0 0
a0 a1 a1 a1 a1-a0
a0 a1 
*/
