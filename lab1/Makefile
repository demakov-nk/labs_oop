############################## Build objects ##############################
build/rect.o: src/rect.cpp src/rect.hpp
	g++ -g -c -o build/rect.o src/rect.cpp

build/barrel.o: src/barrel.cpp src/barrel.hpp
	g++ -g -c -o build/barrel.o src/barrel.cpp

build/matrix.o: src/matrix.cpp src/matrix.hpp
	g++ -g -c -o build/matrix.o src/matrix.cpp

build/my_string.o: src/my_string.cpp src/my_string.hpp
	g++ -g -c -o build/my_string.o src/my_string.cpp

build/text_wrapper.o: src/text_wrapper.cpp src/text_wrapper.hpp
	g++ -g -c -o build/text_wrapper.o src/text_wrapper.cpp

build/rect_test_funcs.o: tests/rect_test_funcs.cpp tests/rect_test_funcs.h
	g++ -g -c -o build/rect_test_funcs.o tests/rect_test_funcs.cpp

obj = build/rect.o build/barrel.o build/matrix.o build/my_string.o build/text_wrapper.o 
rect_test_obj = build/rect.o build/rect_test_funcs.o

############################## Build outs ##############################
build/a.out: $(obj) src/lab1.cpp
	g++ -g -o build/a.out src/lab1.cpp $(obj)

build/debug.out: $(obj) src/lab1.cpp
	g++ -g -o build/debug.out src/lab1.cpp $(obj)

build/leaks.out: $(obj) src/lab1.cpp
	g++ -fsanitize=address -g -o build/leaks.out src/lab1.cpp $(obj)
### Unit tests
build/test_rect_basic_methods.out: $(rect_test_obj) tests/test_rect_basic_methods.cpp
	g++ -g -o build/test_rect_basic_methods.out tests/test_rect_basic_methods.cpp $(rect_test_obj)

build/test_rect_properties.out: $(rect_test_obj) tests/test_rect_properties.cpp
	g++ -g -o build/test_rect_properties.out tests/test_rect_properties.cpp $(rect_test_obj)

build/test_rect_operations.out: $(rect_test_obj) tests/test_rect_operations.cpp
	g++ -g -o build/test_rect_operations.out tests/test_rect_operations.cpp $(rect_test_obj)

build/test_bounding_rect.out: $(rect_test_obj) tests/test_bounding_rect.cpp
	g++ -g -o build/test_bounding_rect.out tests/test_bounding_rect.cpp $(rect_test_obj)

outs = build/a.out build/debug.out build/leaks.out
rect_test_outs = build/test_rect_basic_methods.out build/test_rect_properties.out \
				 build/test_rect_operations.out build/test_bounding_rect.out

############################## Main targets ##############################
build: build/a.out

run: build
	build/a.out

debug: build/debug.out
	gdb build/debug.out

leaks: build/leaks.out
	build/leaks.out < tests/leaks_test_input.txt

test_rect_basic_methods: build/test_rect_basic_methods.out
	build/test_rect_basic_methods.out

test_rect_properties: build/test_rect_properties.out
	build/test_rect_properties.out

test_rect_operations: build/test_rect_operations.out
	build/test_rect_operations.out

test_bounding_rect: build/test_bounding_rect.out
	build/test_bounding_rect.out

test: test_rect_basic_methods test_rect_properties test_rect_operations test_bounding_rect

############################## Phony targets ##############################
.PHONY: clean
clean:
	rm -f $(obj) build/rect_test_funcs.o $(outs) $(rect_test_outs)
