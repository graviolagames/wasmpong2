CC=emcc

WASM_DIR = ../website/wasm/

.PHONY: clean

pong.wasm: main.o
	$(CC) main.o  -s WASM=1 -s USE_SDL=2 -s MODULARIZE=1 -s "EXPORTED_FUNCTIONS=['_main','_moduleUpdate']" -s "EXPORTED_RUNTIME_METHODS=['ccall']" -o pong.js
	cp pong.wasm $(WASM_DIR)
	cp pong.js $(WASM_DIR)
	rm -f pong.wasm 
	rm -f pong.js 
	

main.o: main.c
	$(CC) -c main.c -o main.o

clean:
	rm -f main.o pong.wasm pong.js
	rm -f $(WASM_DIR)pong.wasm
	rm -f $(WASM_DIR)pong.js
	