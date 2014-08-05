#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
#include <limits>
using namespace std;

typedef long long Int;

const Int N_MAX = 200 + 11;
const Int M_MAX = 400 + 11;
const Int C_MAX = 400 + 11;

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


typedef pair<Int, Int> Node; // rem, c_id
typedef set<Node, greater<Node>> Set;

Int R[C_MAX]; // rem count
bool D[C_MAX]; // using
Set S;

void init() {
  fill(R, R + C_MAX, 0);
  fill(D, D + C_MAX, false);
  S = Set();
}

Int solve() {
  Int res = 0;
  for ( int i = 0; i < M; ++ i ) {
    const auto& c_id = C[i];

    if ( D[c_id] ) {
      S.erase(Node(R[c_id], c_id));
      R[c_id] --;
      S.insert(Node(R[c_id], c_id));
      continue;
    }

    res ++;
    D[c_id] = true;
    R[c_id] --;
    if ( S.size() >= N ) {
      const auto& rm = *S.begin();
      D[rm.second] = false;
      S.erase(rm);
    }
    S.insert(Node(R[c_id], c_id));
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
