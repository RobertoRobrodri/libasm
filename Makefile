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
TEST_BONUS_PATH = test_bonus
# SOURCES #
#
SRC = 	ft_read.s \
		ft_strlen.s \
		ft_write.s \
		ft_strcpy.s \
		ft_strcmp.s \
		ft_strdup.s

SRC_BONUS = ft_list_size.s \
			ft_list_push_front.s

SRCS	= $(addprefix $(SRC_PATH)/, $(SRC))
OBJS	= $(addprefix $(OBJ_PATH)/, $(SRC:%.s=%.o))

SRCS_BONUS = $(addprefix $(BONUS_PATH)/, $(SRC_BONUS))
OBJS_BONUS = $(addprefix $(OBJ_PATH)/, $(SRC_BONUS:%.s=%.o))

TEST_SRC   	   = $(addprefix $(TEST_PATH)/, $(SRC:%.s=%.c))
TEST_SRC_BONUS = $(addprefix $(TEST_BONUS_PATH)/, $(SRC_BONUS:%.s=%.c))
TEST_BIN   	   = $(TEST_SRC:%.c=%_test)
TEST_BONUS     = $(TEST_SRC_BONUS:%.c=%_test)

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

test: $(NAME) $(TEST_BIN)

$(TEST_BIN): %_test : %.c
	$(CC) -no-pie $(FLAGS) $< $(NAME) -lc -o $@
	@echo "Compiled $@ successfully."

bonust: bonus $(TEST_BONUS)

$(TEST_BONUS): %_test : %.c
	$(CC) -no-pie $(FLAGS) $< $(NAME) -lc -o $@
	@echo "Compiled $@ successfully."

clean:
	rm -rf $(NAME)

fclean:
	rm -rf $(NAME) $(OBJ_PATH) $(TEST_BIN) $(TEST_BONUS)

re: fclean all

.phony: all clean fclean re