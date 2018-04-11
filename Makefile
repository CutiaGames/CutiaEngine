run:
	cd build && cmake .. && make && ./CutiaEngine

clean:
	rm -r -f build && mkdir build