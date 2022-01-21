#include "horse.h"

extern SqStack S;

void SetWeight()
{
	int i, j, k;
	PosType m;
	ElemType elem;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			elem.seat.x = i;
			elem.seat.y = j;
			weight[i][j] = 0;
			for (k = 0; k < 8; k++) {
				m = NextPos(elem.seat, k+1);
				if (m.x >= 0 && m.x < N && m.y >= 0 && m.y < N) {
					weight[i][j]++;    // (i,j) 点有几个方向可以移动
				}
			}
		}
	}
}