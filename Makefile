CC=g++
TARGETS=../src/chai.cpp ../src/fcl.cpp ../src/layer.cpp ../src/loadmnist.cpp ../src/relu.cpp ../src/sigmoid.cpp ../src/softmax.cpp

make:
	mkdir bin; cd bin; $(CC) -I ../include -c $(TARGETS) -O3; cd ..

clean:
	rm bin/*.o; rmdir bin; rm test.exe
	
test:
	$(CC) -I include examples/Digit_Recognition.cpp bin/*.o -o test -O3