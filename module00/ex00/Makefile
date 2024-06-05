CC = c++
NAME = megaphone
OBJS_DIR := objects
SRC_DIR := .
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = $(addprefix $(SRC_DIR)/, megaphone.cpp)
OBJS = $(patsubst $(SRC_DIR)%.cpp, $(OBJS_DIR)%.o, $(SRCS))

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@
	@echo -----------------------
	@echo Binary created
	@echo _______________________

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $? -o $@

.PHONY: all clean fclean re

all: $(NAME)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
