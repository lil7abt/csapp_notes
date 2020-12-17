default: main

main: usenmsp.o namesp.o
#将file1.o和file2.o连接为可执行的二进制文件main
	g++ -o main usenmsp.o namesp.o
	
usenmsp.o: usenmsp.cpp
#表示只编译file1.c文件，成功时输出目标文件file1.o
	g++ -c usenmsp.cpp
namesp.o: namesp.cpp
	g++ -c namesp.cpp

clean: 
	rm *.o
	rm *~