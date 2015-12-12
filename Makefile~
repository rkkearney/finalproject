titlescreen: titlescreen.o titlescreenfunc.o
	gcc titlescreen.o titlescreenfunc.o gfx4.o -lm -lX11 -o titlescreen 

titlescreen.o: titlescreen.c titlescreenfunc.h
	gcc -c titlescreen.c -o titlescreen.o

titlescreenfunc.o: titlescreenfunc.c
	gcc -c titlescreenfunc.c gfx4.o -o titlescreenfunc.o

clean:
	rm *.o titlescreen

