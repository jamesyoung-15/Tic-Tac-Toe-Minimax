SRCS = main.cpp game.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(OBJS:.o=.d)

all: tic-tac-toe-game

tic-tac-toe-game: $(OBJS)
	g++ -o $@ $(CPPFLAGS) $^

%.o: %.cpp
	g++ -MMD -MP -c $< -o $@

-include $(DEPS)

clean:
	rm -f *.o *.exe *.d