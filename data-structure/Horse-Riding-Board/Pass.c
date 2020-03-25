#include "horse.h"

extern SqStack S;

int Pass(PosType curpos)    // 判断当前位置是否合法
{
    SqStack s1 = S;
    if (curpos.x < 0 || curpos.x > (N-1) || curpos.y < 0 || curpos.y > (N-1))
    	return 0;
    for ( ; s1.top != s1.base; ) {
    	--s1.top;
    	if (curpos.x == (*s1.top).seat.x && curpos.y == (*s1.top).seat.y)
    		return 0;
    }
    return 1;
}