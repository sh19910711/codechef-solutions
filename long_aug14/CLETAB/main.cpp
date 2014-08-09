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
const Int INF = ( 10000 + 11 );

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

typedef tuple <Int, Int> Node; // next, c_id
typedef priority_queue <Node, vector<Node>, greater<Node>> Queue;

Int O[C_MAX][2 * M_MAX];
Int OC[C_MAX];
Int OI[C_MAX];
bool D[C_MAX];

void init() {
  for ( int i = 0; i < C_MAX; ++ i ) {
    fill(O[i], O[i] + 2 * M_MAX, INF);
  }
  fill(OC, OC + C_MAX, 0);
  fill(OI, OI + C_MAX, 0);
  fill(D, D + C_MAX, false);
}

Int solve() {
  for ( int i = 0; i < M; ++ i ) {
    const auto& c_id = C[i];
    auto& n = OC[c_id];
    O[c_id][n ++] = i;
  }

  Queue Q;
  Int res = 0;
  for ( int i = 0; i < M; ++ i ) {
    const auto& c_id = C[i];
    if ( D[c_id] ) {
      Queue q;
      while ( ! Q.empty() ) {
        const auto& x = Q.top();
        Q.pop();
        if ( c_id != get<1>(x) ) q.push(x);
      }
      Q.swap(q);
      Q.emplace(O[c_id][OI[c_id] ++], c_id);
      continue;
    }
    if ( Q.size() < N ) {
      Q.emplace(O[c_id][OI[c_id] ++], c_id);
    } else {
      while ( ! D[get<1>(Q.top())] ) Q.pop();
      const auto& rm = Q.top();
      const auto& rm_c_id = get<1>(rm);
      D[rm_c_id] = false;
      Q.emplace(O[c_id][OI[c_id] ++] - i, c_id);
    }
    res ++;
    D[c_id] = true;
  }
  return res;
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
