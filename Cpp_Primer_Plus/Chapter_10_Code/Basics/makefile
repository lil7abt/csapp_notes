default: main

main: usestock00.o stock00.o
#将file1.o和file2.o连接为可执行的二进制文件main
	g++ -o main usestock00.o stock00.o
	
usestock00.o: usestock00.cpp
#表示只编译file1.c文件，成功时输出目标文件file1.o
	g++ -c usestock00.cpp
namesp.o: stock00.cpp
	g++ -c stock00.cpp

clean: 
	rm *.o