default:
	cd build && cmake .. && make
	./build/game

run:
	./build/game

clean:
	rm -r -f build && mkdir build