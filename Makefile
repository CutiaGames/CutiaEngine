default:
	mkdir -p build
	cd build && cmake .. && make
	./build/game

install:
	git submodule init
	git submodule update

run:
	./build/game

clean:
	rm -r -f build && mkdir build