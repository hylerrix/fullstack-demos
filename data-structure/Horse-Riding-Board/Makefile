objects = Index.o Stack.o NextPos.o OutputPath.o \
	Pass.o SetMap.o SetWeight.o HorsePath.o

a.out: $(objects)
	gcc $(objects) -o a.out

Index.o: Horse.h
Stack.o: Horse.h
NextPos.o: Horse.h
OutputPath.o: Horse.h
Pass.o: Horse.h
SetMap.o: Horse.h
SetWeight.o: Horse.h
HorsePath.o: Horse.h

.PHONY: clean
clean:
	-rm $(objects) a.out