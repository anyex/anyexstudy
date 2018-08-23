#

TARGS += ../bin/Employee \
		 ../bin/lineRead \
		 ../bin/my_sed \
		 ../bin/reverse \
		 ../bin/tac \
		 ../bin/Exam030407_Employee \
		 ../bin/Exam030407_Reverse \

all: $(TARGS)

../bin/%: %.o
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C++ Linker'
	g++ -o $(@) $(^)
	@echo 'Finished building target: $@'
	@echo ' '

%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -c -o $(@) $(^) -g -Wall
	@echo 'Finished building: $<'
	@echo ' '

.PNONY: clean all

clean:
	-rm -rf $(TARGS) *.o