NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror
SRCS = ft_split.c \
		ft_split_utils.c \
		list_check.c \
		free_init.c \
		list_utils.c \
		swap.c \
		rotate.c \
		reverse.c \
		push.c \
		mediane_utils.c \
		push_algo_utils.c \
		push_swap.c
OBJS = ${SRCS:.c=.o}
HEADER = push_swap.h

GREEN = \033[1;32m
RED = \033[1;31m
YELLOW = \033[1;33m
ORANGE = \033[38;5;214m
PURPLE = \033[1;35m
BOLD := \033[1m
RESET = \033[0m 

SUCCESS = [ ✔ ]
ERROR = [ ✗ ]
CLEAN = [ ♻ ]
REMOVE = [ 🗑 ]
REDO = [ 🗘 ]

all: ${NAME}

${NAME}: ${OBJS}
	@${CC} ${OBJS} -o ${NAME}
	@echo "${GREEN} ============ ${SUCCESS} ${NAME} compiled successfully! ================ ${RESET}"

%.o: %.c ${HEADER}
	@${CC} ${FLAGS} -c $< -o $@ || (echo "\n${RED} ============ ${ERROR} Compilation failed ! ==================== ${NC}\n"; exit 1)
	@echo "${GREEN} ============ ${SUCCESS} Successful compilation ! ================ ${RESET}"

clean:
	@rm -rf ${OBJS} ${OBJS_BONUS}
	@echo "${YELLOW} ============ ${CLEAN} Successful binary cleaning ! ============ ${RESET}"

fclean: clean
	@rm -rf ${NAME}
	@echo "${BOLD}${ORANGE} ============ ${REMOVE} Deleted executable ! ==================== ${RESET}"

re: fclean all
	@echo "${PURPLE} ============ ${REDO} Redo completed ! ======================== ${RESET}"

.PHONY: all clean fclean re
