#include <stdio.h>
#include <algorithm>
using namespace std;
int N, S, T, X[35], Y[35];
int ret, U[35];
void dfs(int nd, int cost, int used) {
    if(cost+(N-X[nd]+N-Y[nd]-2) >= ret)
        return;
    if(used == S) {
        ret = min(ret, cost+(N-X[nd]+N-Y[nd]-2));
        return;
    }
    int i;
    for(i = 1; i <= T; i++) {
        if(!U[i]) {
            U[i] = 1;
            dfs(i, cost+abs(X[i]-X[nd])+abs(Y[i]-Y[nd]), used+1);
            U[i] = 0;
        }
    }
}
int main() {
    int i, j, cases = 0;
    while(scanf("%d %d %d", &N, &T, &S) == 3) {
        if(N+S+T == 0)
            break;
        X[0] = 0, Y[0] = 0, U[0] = 0;
        for(i = 0; i < T; i++) {
            scanf("%d %d", &X[i+1], &Y[i+1]);
            U[i+1]=0;
        }
        ret = 0xffffff;
        dfs(0, 0, 0);
        printf("Case %d: %d\n", ++cases, ret);
    }
    return 0;
}
