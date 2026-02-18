# ===== Compiler & flags =====
CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -Iinclude

# ===== Project structure =====
SRC_DIR  = src
INC_DIR  = include
OBJ_DIR  = obj

# ===== Files =====
SRC_FILES = \
	$(SRC_DIR)/Heur_1.cpp \
	$(SRC_DIR)/Heur_2.cpp \
	$(SRC_DIR)/Heur_3.cpp \
	$(SRC_DIR)/Checker.cpp \
	$(SRC_DIR)/WarehouseInstance.cpp \
	$(SRC_DIR)/WarehouseLoader.cpp \
	$(SRC_DIR)/WarehouseSolution.cpp \
	main.cpp

OBJ_FILES = $(SRC_FILES:%.cpp=$(OBJ_DIR)/%.o)

TARGET = warehouse_solver

# ===== Rules =====
all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Create object files
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ===== Utilities =====
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
