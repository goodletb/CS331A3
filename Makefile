CXX = g++
CXXFLAGS = -std=c++11 -g
PROG = cs331a3
SRCS = main.cpp WordBag.cpp
HEADERS = WordBag.h
OBJS = main.o WordBag.o

build: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o ${PROG}

${OBJS}: ${SRCS}
	${CXX} -c $(@:.o=.cpp)

clean:
	rm -f *.o ${PROG}