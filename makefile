ALL : build

GXX = g++
CFLAGS = --std=c++17 -Iinclude/
PACKAGE_DIR=$(shell dirname .)
INCDIR = ${PACKAGE_DIR}/include
EXECUTABLE_NAME = run
EXECUTABLE_FILE_NAME = src/main.cpp
LIBRARIES = array.so container.so iterator.so mylib.so queue.so stack.so string.so
LIBRARY_NAME=mystd
container.so:
	${GXX} -c -o $@ ${PACKAGE_DIR}/src/container.cpp ${CFLAGS}

iterator.so: container.so
	${GXX} -c -o $@ ${PACKAGE_DIR}/src/iterator.cpp ${CFLAGS} $^

queue.so: container.so
	${GXX} -c -o $@ ${PACKAGE_DIR}/src/queue.cpp ${CFLAGS} $^

stack.so: container.so
	${GXX} -c -o $@ ${PACKAGE_DIR}/src/stack.cpp ${CFLAGS} $^

mylib.so:
	${GXX} -c -o $@ ${PACKAGE_DIR}/src/mylib.cpp ${CFLAGS} 

array.so : container.so iterator.so mylib.so
	${GXX} -c -o $@ ${PACKAGE_DIR}/src/array.cpp ${CFLAGS} $^

string.so: array.so stack.so queue.so
	${GXX} -c -o $@ ${PACKAGE_DIR}/src/string.cpp ${CFLAGS} $^

${LIBRARY_NAME}.so: ${LIBRARIES}
	${GXX} -o $@ -Wl, -r ${LIBRARIES}

build : ${LIBRARY_NAME}.so
	${GXX} -o ${EXECUTABLE_NAME} ${PACKAGE_DIR}/${EXECUTABLE_FILE_NAME} ${CFLAGS} $<

run : build
	./${EXECUTABLE_NAME}

clean : 
	rm -rf ${EXECUTABLE_NAME} ${wildcard *.so}
