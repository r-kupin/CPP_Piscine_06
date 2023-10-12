#
#     /$$$$$$                             /$$$$$$   /$$$$$$ 
#    /$$__  $$                           /$$$_  $$ /$$__  $$
#   | $$  \__/  /$$$$$$   /$$$$$$       | $$$$\ $$| $$  \__/
#   | $$       /$$__  $$ /$$__  $$      | $$ $$ $$| $$$$$$$ 
#   | $$      | $$  \ $$| $$  \ $$      | $$\ $$$$| $$__  $$
#   | $$    $$| $$  | $$| $$  | $$      | $$ \ $$$| $$  \ $$
#   |  $$$$$$/| $$$$$$$/| $$$$$$$/      |  $$$$$$/|  $$$$$$/
#    \______/ | $$____/ | $$____/        \______/  \______/ 
#             | $$      | $$                                
#             | $$      | $$                                
#             |__/      |__/                                
#

NAME = convert
NAME_LIB = $(NAME)_lib
ASAN = $(NAME)_asan
TEST = $(NAME)_test

SRCS = src/CharHandler.cpp  \
		src/InputEvaluator.cpp  \
		src/main.cpp  \
		src/NumberHandler.cpp  \
		src/ScalarConversion.cpp
LIB_SRCS = src/CharHandler.cpp  \
		src/InputEvaluator.cpp \
		src/NumberHandler.cpp  \
		src/ScalarConversion.cpp
TEST_SRCS = test/char_test.cpp  \
		test/correct_input.cpp  \
		test/int_test.cpp  \
		test/ratio_test.cpp  \
		test/wrong_input.cpp

OBJS = $(SRCS:.cpp=.o)
LIB_OBJS = $(LIB_SRCS:.cpp=.o)
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

TEST_LIB_DIR = ../googletest
TEST_LIB_INCL_DIR = $(TEST_LIB_DIR)/googletest/include
TEST_LIB_BILD_DIR = $(TEST_LIB_DIR)/build
TEST_LIB_LIB_DIR = $(TEST_LIB_BILD_DIR)/lib
TEST_LIB_CMAKE = $(TEST_LIB_DIR)/Makefile
TEST_LIBS = $(TEST_LIB_LIB_DIR)/libgtest.a \
			$(TEST_LIB_LIB_DIR)/libgtest_main.a

CXX = clang++
GXX = g++
LIB_CXX = ar rvs

CXXFLAGS = -Wall -Wextra -Werror -std=c++98
LINKER_FLAGS = -lgtest -lgtest_main -pthread
ASANFLAGS = -g -fsanitize=address

all: $(NAME)

asan: $(ASAN)
	@./$(ASAN)
	@make clean

valgrnd: $(NAME)
	valgrind ./$(NAME)
	@make fclean

test: $(TEST)
	@./$(TEST)

$(TEST_LIBS): $(TEST_LIB_DIR)
	@make -C $(TEST_LIB_BILD_DIR)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(ASAN): $(OBJS)
	$(CXX) $(ASANFLAGS) $(CXXFLAGS) $(OBJS) -o $(ASAN)

$(NAME_LIB): $(LIB_OBJS)
	$(LIB_CXX) $(NAME_LIB) $(LIB_OBJS)

$(TEST): $(TEST_LIBS) $(TEST_OBJS) $(NAME_LIB)
	$(GXX) -L$(TEST_LIB_LIB_DIR) $(TEST_OBJS) $(NAME_LIB) $(LINKER_FLAGS) -no-pie -o $(TEST)

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

test/%.o: test/%.cpp
	$(GXX) -I$(TEST_LIB_INCL_DIR) -c $< -o $@

clean:
	@rm -fr $(OBJS)
	@rm -fr $(TEST_OBJS)

fclean: clean
	@rm -fr $(NAME)
	@rm -fr $(ASAN)
	@rm -fr $(TEST)
	@rm -fr $(NAME_LIB)

re:
	@$(MAKE) fclean
	@$(MAKE) all
