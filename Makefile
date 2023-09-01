all: src/main.cpp
	em++ -Wall -Wextra -std=c++17 -I./reqs/include src/main.cpp -sWASM=1 -sUSE_SDL=2 -sUSE_SDL_IMAGE=2 -sUSE_SDL_TTF=2 -sUSE_WEBGL2=1 -o build/videoedit.js -o build/videoedit.html

clean:
	rm -f build/videoedit.js
