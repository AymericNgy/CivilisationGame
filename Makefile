#pour compiler avec make debug faire make clean avant si make a ete fait avant et inversement

CPP=g++
LD=g++



CPPFLAGS=-std=c++17
LDFLAGS=-std=c++17
LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio

SRC_DIR := ./src
OBJ_DIR := ./obj
SRC_FILES := $(shell find $(SRC_DIR) -name '*.cpp')
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))



# Compiler avec ou sans l'option -g
ifeq ($(DEBUG),yes)
  CPPFLAGS += -g -O0
endif




all : jeu

# Règle pour activer le mode debug
debug: 
	make DEBUG=yes


clean:
	rm -rf obj/* && rm ./jeu


jeu: $(OBJ_FILES)
	g++ $(LDFLAGS) -o $@ $^ $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(SRC_DIR)/%.hpp
	@mkdir -p $(dir $@)
	g++ $(CPPFLAGS) -c -o $@ $<






# pour lancer debug : valgrind --leak-check=yes ./jeu 

# pour lancer debug et avoir graphe evolution memoire : valgrind --tool=massif ./jeu 
# puis executer : ms_print massif.out.<pid>




