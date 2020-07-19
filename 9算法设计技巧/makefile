SRC	= $(wildcard *.c)
TARGET = result
OBJ = $(SRC:.c=.o)
DEP = $(SRC:.c=.d)

CXX = g++
#Option for compiler
CXXFLAGS = -O2 -g -Wall

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^ 

$(OBJ):	$(SRC) | $(DEP)
	$(CXX) -c $(CXXFLAGS) $^

#For include essential head file
$(DEP): $(SRC)
	$(CXX) -MM -o $@ $^

-include $(DEP)

.PHONY: clean
clean:
	$(RM) $(OBJ) $(DEP) $(TARGET)

