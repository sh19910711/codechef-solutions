#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
#include <limits>
#include <tuple>
using namespace std;

typedef long long Int;

const Int N_MAX = 200 + 11;
const Int M_MAX = 400 + 11;
const Int C_MAX = 400 + 11;
const Int MEMO_NONE = -1;

Int N;
Int M;
Int C[M_MAX];

void input() {
  cin >> N >> M;
  for ( int i = 0; i < M; ++ i ) {
    cin >> C[i];
  }
  for ( int i = 0; i < M; ++ i ) C[i] --;
}

Int cnt[M_MAX];
Int ml[C_MAX];
Int mr[C_MAX];

void init() {
  fill(cnt, cnt + M_MAX, 0);
  fill(ml, ml + C_MAX, -1);
  fill(mr, mr + C_MAX, -1);
}

Int solve() {
  for ( int i = 0; i < M; ++ i ) {
    const auto& c_id = C[i];
    if ( ml[c_id] == -1 ) ml[c_id] = i;
    mr[c_id] = i;
  }
  for ( int i = 0; i < C_MAX; ++ i ) {
    const auto& c_id = i;
    if ( ml[c_id] != -1 ) {
      for ( int j = ml[c_id]; j <= mr[c_id]; ++ j ) {
        cnt[j] ++;
      }
    }
  }
  return -1;
}

int main() {
  int tests;
  cin >> tests;
  for ( int i = 0; i < tests; ++ i ) {
    init();
    input();
    cout << solve() << endl;
  }
  return 0;
}
