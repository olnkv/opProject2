mkdir build
copy *.txt build\*.txt
copy *.cpp build\*.cpp
cd build
cmake -G "MinGW Makefiles" -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ .
cmake --install .
cmake --build .
tests.exe