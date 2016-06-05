compile:
	g++ -Wall src/*.cpp `sdl-config --cflags --libs` -o cavestory
run:
	./cavestory
