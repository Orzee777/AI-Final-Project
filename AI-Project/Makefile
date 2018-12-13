CC=g++
TARGETS=../src/matrix.cpp ../src/fcl.cpp ../src/layer.cpp ../src/loadmnist.cpp ../src/relu.cpp ../src/sigmoid.cpp ../src/softmax.cpp
 
make:
	mkdir bin; cd bin; $(CC) -I ../include -c $(TARGETS) -O3; cd ..
	
clean:
	rm bin/*.o; rmdir bin; rm test.exe
	
test:
	$(CC) -I include bin/*.o main.cpp -o test -O3