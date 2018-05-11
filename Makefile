run:
	cd build && cmake .. && make
	./build/CutiaEngine

clean:
	rm -r -f build && mkdir build