CC = c++
NAME = account
OBJS_DIR := objects
SRC_DIR := .
INCLUDE_DIR := .
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3

SRCS = $(addprefix $(SRC_DIR)/, Account.cpp\
					tests.cpp)

OBJS = $(patsubst $(SRC_DIR)%.cpp, $(OBJS_DIR)%.o, $(SRCS))

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@
	@echo -----------------------
	@echo Binary created
	@echo _______________________

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $? -o $@

.PHONY: all clean fclean re

all: $(NAME)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
