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

NAME = ScalarConversion
NAME_LIB = ScalarConversionLib
TEST = ScalarConversionTest

SRCS = src/CharHandler.cpp  src/InputEvaluator.cpp  src/main.cpp  src/NumberHandler.cpp  src/ScalarConversion.cpp
LIB_SRCS = src/CharHandler.cpp  src/InputEvaluator.cpp src/NumberHandler.cpp  src/ScalarConversion.cpp
TEST_SRCS = test/char_test.cpp  test/correct_input.cpp  test/int_test.cpp  test/ratio_test.cpp  test/wrong_input.cpp test/test_main.cpp

OBJS = $(SRCS:.cpp=.o)
LIB_OBJS = $(LIB_SRCS:.cpp=.o)
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

CXX = clang++
GXX = g++
LIB_CXX = ar rvs

CXXFLAGS = -Wall -Wextra -Werror
GXXFLAGS = -lgtest -lgtest_main -pthread

all: $(NAME)

test: $(TEST)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(NAME_LIB): $(LIB_OBJS)
	$(LIB_CXX) $(NAME_LIB) $(LIB_OBJS)

$(TEST): $(TEST_OBJS) $(NAME_LIB)
	$(GXX) $(GXXFLAGS) $(TEST_OBJS) $(NAME_LIB)  -o $(TEST)

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

test/%.o: test/%.cpp
	$(GXX) $(GXXFLAGS) -c $< -o $@

clean:
	@rm -fr $(OBJS)
	@rm -fr $(TEST_OBJS)

fclean: clean
	@rm -fr $(NAME)
	@rm -fr $(TEST)
	@rm -fr $(NAME_LIB)

re:
	@$(MAKE) fclean
	@$(MAKE) all
