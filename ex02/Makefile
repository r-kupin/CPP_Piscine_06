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

NAME = IdentifyRealType

SRCS = src/A.cpp  src/Base.cpp  src/B.cpp  src/C.cpp  src/main.cpp

OBJS = $(SRCS:.cpp=.o)

CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all