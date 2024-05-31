# COLORS #
#
GREEN 	= @echo "\033[0;32m"
BLUE 	= @echo "\033[0;34m"
PURPLE 	= @echo "\033[0;35m"
CYAN 	= @echo "\033[0;36m"
RESET 	= "\033[1;0m"

# VARIABLES #
#
NAME 	= libasm.a
CC 		= gcc
FLAGS   = -g3 -fsanitize=address

# PATHS #
#
SRC_PATH = srcs
BONUS_PATH = srcs_bonus
OBJ_PATH = objects
TEST_PATH = test
# SOURCES #
#
SRC = 	ft_read.s \
		ft_strlen.s \
		ft_write.s \
		ft_strcpy.s \
		ft_strcmp.s \
		ft_strdup.s

SRC_BONUS = ft_list_size.s

SRCS	= $(addprefix $(SRC_PATH)/, $(SRC))
OBJS	= $(addprefix $(OBJ_PATH)/, $(SRC:%.s=%.o))

SRCS_BONUS = $(addprefix $(BONUS_PATH)/, $(SRC_BONUS))
OBJS_BONUS = $(addprefix $(OBJ_PATH)/, $(SRC_BONUS:%.s=%.o))

all: $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.s | $(OBJ_PATH)
	nasm -f elf64 $< -o $@

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

bonus: $(OBJS_BONUS)
	ar rc $(NAME) $(OBJS_BONUS)
	ranlib $(NAME)

$(OBJ_PATH)/%.o: $(BONUS_PATH)/%.s | $(OBJ_PATH)
	nasm -f elf64 $< -o $@

test: all
	gcc -no-pie $(FLAGS) test/ft_strlen.c $(NAME) -lc -o ft_strlen
	gcc -no-pie $(FLAGS) test/ft_strcpy.c $(NAME) -lc -o ft_strcpy
	gcc -no-pie $(FLAGS) test/ft_strcmp.c $(NAME) -lc -o ft_strcmp
	gcc -no-pie $(FLAGS) test/ft_strdup.c $(NAME) -lc -o ft_strdup
	gcc -no-pie $(FLAGS) test/ft_write.c $(NAME) -lc -o ft_write

clean:
	rm -rf $(NAME)

fclean:
	rm -rf $(NAME) $(OBJ_PATH)

re: fclean all

.phony: all clean fclean re