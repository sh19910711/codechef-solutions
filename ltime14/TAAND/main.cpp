#include <iostream>
#include <limits>
using namespace std;

typedef long long Int;

const Int BIT_SIZE = 31;
const Int N_MAX = 3 * 100000 + 11;
const Int INF = numeric_limits<Int>::min();

Int N;
Int A[N_MAX];
Int T[BIT_SIZE][N_MAX];

int main() {
    for ( int i = 0; i < BIT_SIZE; ++ i ) {
        for ( int j = 0; j < N_MAX; ++ j ) {
            T[i][j] = INF;
        }
    }
    
    Int n;
    cin >> n;
    for ( int i = 0; i < n; ++ i ) cin >> A[i];
    
    for ( int i = n - 1; i >= 0; -- i ) {
        for ( int j = 0; j < BIT_SIZE; ++ j ) {
            if ( i + 1 < n ) T[j][i] = T[j][i + 1];
        }
        for ( int j = 0; j < BIT_SIZE; ++ j ) {
            int bj = 1 << j;
            if ( A[i] & bj ) T[j][i] = max(T[j][i], A[i]);
        }
    }
    
    Int res = 0;
    for ( int i = 0; i + 1 < n; ++ i ) {
        for ( int j = 0; j < BIT_SIZE; ++ j ) {
            Int ret = T[j][i + 1];
            if ( ret != INF ) res = max(res, A[i] & T[j][i + 1]);
        }
    }
    cout << res << endl;
    
    return 0;
}