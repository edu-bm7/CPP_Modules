CXX = c++

# If c++ isn't clang, use clang++ as CXX compiler
ifeq ($(shell c++ --version 2>&1 | grep -c "clang"),0)
    CXX = clang++
endif

NAME = btc
OBJS_DIR := objects
SRC_DIR := .
INCLUDE_DIR := .
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = $(addprefix $(SRC_DIR)/, main.cpp\
	   							BitcoinExchange.cpp\
								IsSpace.cpp)
OBJS = $(patsubst $(SRC_DIR)%.cpp, $(OBJS_DIR)%.o, $(SRCS))

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@
	@echo -----------------------
	@echo Binary created
	@echo _______________________

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $? -o $@

.PHONY: all clean fclean re

all: $(NAME)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)
	rm -rf .cache
	rm -f compile_commands.json

re: fclean all
