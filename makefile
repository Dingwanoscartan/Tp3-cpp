src := $(shell ls *.cpp)
objs:= $(patsubst %.cpp,%.o,$(src)) 
 
test : $(objs)
	g++ -o $@ $^ 
 
%.o : %.cpp
	g++ -c -o $@ $< 
 
clean :
	rm -f test *.o 

