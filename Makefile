CXXFLAGS=-g
LDLIBS=-lX11 -lstdc++ -lm

mandelbrot: mandelbrot.o gfx.o

clean: 
	rm -f mandelbrot *.o
