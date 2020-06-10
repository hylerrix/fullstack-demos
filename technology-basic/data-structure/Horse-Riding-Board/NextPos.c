#include "horse.h"

extern SqStack S;

PosType NextPos(PosType curpos, int direction)    // 8 个候选方向
{
    switch(direction)
    {
    	case 1: curpos.x+=1;curpos.y-=2;break;
    	case 2: curpos.x+=2;curpos.y-=1;break;
    	case 3: curpos.x+=2;curpos.y+=1;break;
    	case 4: curpos.x+=1;curpos.y+=2;break;
    	case 5: curpos.x-=1;curpos.y+=2;break;
    	case 6: curpos.x-=2;curpos.y+=1;break;
    	case 7: curpos.x-=2;curpos.y-=1;break;
    	case 8: curpos.x-=1;curpos.y-=2;break;
    }
    return curpos;
}