SRCS = main.cpp game.cpp ai.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(OBJS:.o=.d)

all: tic-tac-toe-game.o

tic-tac-toe-game.o: $(OBJS)
	g++ -o $@ $^

%.o: %.cpp
	g++ -MMD -MP -c $< -o $@

-include $(DEPS)

clean:
	rm -f *.o *.exe *.d