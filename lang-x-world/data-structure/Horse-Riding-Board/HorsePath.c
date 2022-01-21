#include "horse.h"

extern SqStack S;

int HorsePath(PosType start)    // 马走过的路径
{
	PosType curpos;
	int horsestep = 0, off;
    ElemType elem;
    curpos = start;
    do {
    	if (Pass(curpos))
    	{
    		horsestep++;
    		elem.di = 0;
    		elem.ord = horsestep;
    		elem.seat = curpos;
    		Push(elem);
    		if (N*N == horsestep)
    			return 1;
    		off = Board[elem.seat.x][elem.seat.y][elem.di]+1;
    		curpos = NextPos(elem.seat, off);    // 取得下一个坐标点
    	} else {
    		if (!StackEmpty()) {   // 栈 s 非空
                while (!StackEmpty() && elem.di == 8) {
                	Pop(&elem);
                	if (!StackEmpty()) {    // 判断，弹出后是否为空
                        elem = GetTop();
                        horsestep = elem.ord;
                	}
                }
                if (!StackEmpty() && elem.di < 8) {
                	Pop(&elem);
                	off = Board[elem.seat.x][elem.seat.y][++elem.di];
                	curpos = NextPos(elem.seat, off+1);
                	Push(elem);
                }
            }
    	}
    } while (!StackEmpty());
    return 0;
}