default: main

main: file1.o file2.o
#将file1.o和file2.o连接为可执行的二进制文件main
	g++ -o main file1.o file2.o
	
file1.o: file1.cpp
#表示只编译file1.c文件，成功时输出目标文件file1.o
	g++ -c file1.cpp
file2.o: file2.cpp
	g++ -c file2.cpp

clean: 
	rm *.o
	rm *~