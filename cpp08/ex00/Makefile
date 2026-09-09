NAME = easyfind
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

SRC_PATH = src/
OBJ_PATH = obj/

# Source files
SRC = main.cpp
SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ = $(SRC:.cpp=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))

# Colors
GREEN = \033[0;32m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $@
	@echo "$(GREEN)$(NAME) successfully compiled!$(RESET)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	@mkdir -p $(OBJ_PATH)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "$(GREEN)Compiling$(RESET) $(notdir $<)"

clean:
	@$(RM) $(OBJS)
	@$(RM) -rf $(OBJ_PATH)
	@echo "$(GREEN)Object files removed!$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(GREEN)$(NAME) removed!$(RESET)"

re: fclean all

.PHONY: all clean fclean re