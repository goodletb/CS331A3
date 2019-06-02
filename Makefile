CXX = g++
CXXFLAGS = -std=c++11 -g
PROG = cs331a3
SRCS = main.cpp WordBag.cpp NaiveBayesClassifier.cpp
HEADERS = WordBag.h NaiveBayesClassifier.h
OBJS = main.o WordBag.o NaiveBayesClassifier.o

build: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o ${PROG}

${OBJS}: ${SRCS}
	${CXX} -c $(@:.o=.cpp)

clean:
	rm -f *.o ${PROG}