CXX = g++
CXXFLAGS = -Wall -g

SRC = main.cpp archivos.cpp grafo.cpp nodo.cpp tienda.cpp utilidades.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = parcial

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)
