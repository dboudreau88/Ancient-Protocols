@echo off
echo Building 3D ASCII Renderer...

if not exist obj mkdir obj
if not exist bin mkdir bin

echo Compiling source files...
gcc -Wall -Wextra -O2 -Iinclude -c src/terminal.c -o obj/terminal.o
gcc -Wall -Wextra -O2 -Iinclude -c src/framebuffer.c -o obj/framebuffer.o
gcc -Wall -Wextra -O2 -Iinclude -c src/renderer.c -o obj/renderer.o
gcc -Wall -Wextra -O2 -Iinclude -c src/main.c -o obj/main.o

echo Linking...
gcc obj/terminal.o obj/framebuffer.o obj/renderer.o obj/main.o -o bin/ascii3d.exe -lm

if %ERRORLEVEL% EQU 0 (
    echo Build successful!
    echo Run with: bin\ascii3d.exe
) else (
    echo Build failed!
    exit /b 1
)
