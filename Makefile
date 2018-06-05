run:
	cd build && cmake .. && make
	./build/game

clean:
	rm -r -f build && mkdir build