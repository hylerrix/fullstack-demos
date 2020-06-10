Path_Obj = Objects
Path_UI = UI
Path_Handle = Handle
Path_Build = Build

Objects = $(Path_Obj)/Main.o $(Path_Obj)/Build_Huff.o \
    $(Path_Obj)/UI_Entrance.o $(Path_Obj)/UI_ShowMenu.o \
	$(Path_Obj)/Handle_Comp.o $(Path_Obj)/Handle_Enci.o $(Path_Obj)/Handle_Freq.o

a.out: $(Objects)
	gcc -o a.out $(Objects)

$(Path_Obj)/Main.o: Huffman.h
	gcc -c main.c -o $(Path_Obj)/main.o

# UI
$(Path_Obj)/UI_Entrance.o: Huffman.h
	gcc -c $(Path_UI)/UI_Entrance.c -o $(Path_Obj)/UI_Entrance.o
$(Path_Obj)/UI_ShowMenu.o: Huffman.h
	gcc -c $(Path_UI)/UI_ShowMenu.c -o $(Path_Obj)/UI_ShowMenu.o

# Build
$(Path_Obj)/Build_Huff.o: Huffman.h
	gcc -c $(Path_Build)/Build_Huff.c -o $(Path_Obj)/Build_Huff.o

# Handle
$(Path_Obj)/Handle_Comp.o: Huffman.h
	gcc -c $(Path_Handle)/Handle_Comp.c -o $(Path_Obj)/Handle_Comp.o
$(Path_Obj)/Handle_Enci.o: Huffman.h
	gcc -c $(Path_Handle)/Handle_Enci.c -o $(Path_Obj)/Handle_Enci.o
$(Path_Obj)/Handle_Freq.o: Huffman.h
	gcc -c $(Path_Handle)/Handle_Freq.c -o $(Path_Obj)/Handle_Freq.o
$(Path_Obj)/Handle_Huff.o: Huffman.h
	gcc -c $(Path_Handle)/Handle_Huff.c -o $(Path_Obj)/Handle_Huff.o

.PHONY: clean
clean:
	rm -f a.out lft.* $(Path_Obj)/*