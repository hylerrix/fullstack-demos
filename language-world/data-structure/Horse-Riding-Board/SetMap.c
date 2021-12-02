#include "horse.h"

extern SqStack S;

void SetMap()    // 各点的8个方向按照权值递增排列
{
    int a[8];
    int i,j,k,m,min,s,h;
    PosType n1, n2;
    for (i = 0; i < N; i++) {
    	for (j = 0; j < N; j++) {
    		for (h = 0; h < 8; h++) {
    		    // 用数组 a[8] 记录当前位置的下一个位置的可行路径条数
    	        n2.x = i;
    	        n2.y = j;
    	        n1 = NextPos(n2, h+1);
    	        if (n1.x >= 0 && n1.x < N && n1.y >= 0 && n1.y < N) {
    	        	a[h] = weight[n1.x][n1.y];
    	        } else {
    	        	a[h] = 0;
    	        }
    	    }
    	    // 对方向索引权值升序排列存入 Board[N][N][8]，不能到达的方向排在最后
    	    for (m = 0; m < 8; m++) {
    	    	min = 9;
    	    	for (k = 0; k < 8; k ++) {
    	    		if (min > a[k]) {
    	    			min = a[k];
    	    			Board[i][j][m] = k;
    	    			s = k;
    	    		}
    	    	}
    	    	a[s] = 9;    // 选过的设为 9
    	    }
        }
    }
}