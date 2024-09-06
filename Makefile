# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmouhib <bmouhib@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/05 15:10:41 by bmouhib           #+#    #+#              #
#    Updated: 2024/09/05 19:52:39 by bmouhib          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------------------------------------------------------------------- #
#                                  VARIABLES                                   #
# ---------------------------------------------------------------------------- #

NAME := push_swap

# --------------------------------- PATHNAMES -------------------------------- #

SRC_ALGO	:=	algo/
SRC_OP		:=	operations/
SRC_STACK	:=	stack/
SRC_UTILS	:=	utils/

# --------------------------------- SOURCES ---------------------------------- #

SRC				:=	push_swap.c

# ----------------------------------- ALGO ----------------------------------- #

SRC				+=	$(SRC_ALGO)index.c
SRC				+=	$(SRC_ALGO)sort_algo.c
SRC				+=	$(SRC_ALGO)sort.c

# -------------------------------- OPERATIONS -------------------------------- #

SRC				+=	$(SRC_OP)push.c
SRC				+=	$(SRC_OP)reverse_rotate.c
SRC				+=	$(SRC_OP)rotate.c
SRC				+=	$(SRC_OP)small_sorts.c
SRC				+=	$(SRC_OP)swap.c

# ----------------------------------- STACK ---------------------------------- #

SRC				+=	$(SRC_STACK)add_stack.c
SRC				+=	$(SRC_STACK)init_stack.c
SRC				+=	$(SRC_STACK)utils_stack.c

# ----------------------------------- UTILS ---------------------------------- #

SRC				+=	$(SRC_UTILS)cleaners.c
SRC				+=	$(SRC_UTILS)print_stack.c
SRC				+=	$(SRC_UTILS)sort_check.c
SRC				+=	$(SRC_UTILS)word_count.c

# --------------------------------- COMMANDS --------------------------------- #

CC				:=	gcc
RM				:=	rm -rf
AR				:=	ar -rc
MKDIR			:=	mkdir -p

# ----------------------------------- FLAGS ---------------------------------- #

CFLAGS			:=	-Wall
CFLAGS			+=	-Wextra
CFLAGS			+=	-Werror
CFLAGS			+=	-g3

LIBFT_FLAGS		+=	-L$(LIBFT_DIR)
LIBFT_FLAGS		+=	-lft

MAKE_NO_PRINT	:=	--no-print-directory
MAKE_FLAGS		:=	$(MAKE_NO_PRINT)
MAKE_FLAGS		+=	-C

# ----------------------------------- FILES ---------------------------------- #

INCLUDES		:=	includes/

LIBFT_DIR		:=	libft/
LIBFT_NAME		:=	libft.a

LIBFT			:=	$(LIBFT_DIR)$(LIBFT_NAME)

SRCS_DIR		:=	srcs/
SRCS			:=	$(addprefix $(SRCS_DIR), $(SRC))

OBJS_DIR		:=	objs/
OBJS			:=	$(addprefix $(OBJS_DIR), $(SRC:.c=.o))

DEPS			:=	$(OBJS:.o=.d)

# ---------------------------------------------------------------------------- #
#                                   VISUALS                                    #
# ---------------------------------------------------------------------------- #

# ---------------------------------- STYLES ---------------------------------- #

RED				:=	"\033[0;31m\033[1m"
GREEN			:=	"\033[0;32m\033[1m"
BLUE			:=	"\033[0;34m\033[1m"
PURPLE			:=	"\033[0;35m\033[1m"
YELLOW			:=	"\033[1;33m\033[1m"
WHITE			:=	"\033[0;37m\033[1m"
NO_STYLE		:=	"\033[0m"

# ----------------------------------- ECHO ----------------------------------- #

ECHO			:=	echo

DELETION		:=	$(RED)Deletion$(NO_STYLE) of
CREATION		:=	$(GREEN)Creation$(NO_STYLE) of
TO_UPPER		:=	tr '[:lower:]' '[:upper:]'
TRUNC_A			:=	tr -d '.a'
PROJECT			:=	$(shell $(ECHO) $(NAME) | $(TRUNC_A) | $(TO_UPPER))
OBJ_FILES		:=	$(BLUE)object files$(NO_STYLE)
DEPS_FILES		:=	$(BLUE)dependencies files$(NO_STYLE)
AND				:=	and
COMPLETE		:=	complete
BONUS_FILES		:=	bonus object files
TO_UPPER		:=	tr '[:lower:]' '[:upper:]'
TRUNC_A			:=	tr -d '.a'
PROJECT			:=	$(shell $(ECHO) $(NAME) | $(TRUNC_A) | $(TO_UPPER))
PROJECT_NAME	:=	$(WHITE)$(PROJECT)$(NO_STYLE)
NAME_FILE		:=	$(BLUE)$(NAME)$(NO_STYLE)

COMP_OBJS		:=	$(ECHO) $(CREATION) $(PROJECT_NAME) $(OBJ_FILES) $(AND) $(DEPS_FILES) $(COMPLETE)
COMP_NAME		:=	$(ECHO) $(CREATION) $(PROJECT_NAME) $(NAME_FILE) $(COMPLETE)
COMP_CLEAN		:=	$(ECHO) $(DELETION) $(PROJECT_NAME) $(OBJ_FILES) $(AND) $(DEPS_FILES) $(COMPLETE)
COMP_FCLEAN		:=	$(ECHO) $(DELETION) $(PROJECT_NAME) $(NAME_FILE) $(COMPLETE)

define HELP_MSG
Usage: make [TARGET]
		all         - Create the archive file(s)
		clean       - Remove object file(s)
		fclean      - Remove object file(s) and archive file(s)
		re          - Recreate the archive file(s)
		bonus       - Build the bonus part of the program
		help        - Display this help message
endef
export HELP_MSG

HELP			:=	@$(ECHO) "$$HELP_MSG"

# ---------------------------------------------------------------------------- #
#                                    RULES                                     #
# ---------------------------------------------------------------------------- #

$(OBJS_DIR)%.o:		$(SRCS_DIR)%.c
					@$(MKDIR) $(dir $@)
					@$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

all:				$(NAME) Makefile

$(NAME): 			$(LIBFT) $(OBJS)
					@$(COMP_OBJS)
					@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT_FLAGS)
					@$(COMP_NAME)

$(LIBFT):
					@$(MAKE) $(MAKE_FLAGS) $(LIBFT_DIR)

clean:
					@$(MAKE) $(MAKE_FLAGS) $(LIBFT_DIR) clean
					@$(RM) $(OBJS_DIR)
					@$(COMP_CLEAN)

fclean:				clean
					@$(MAKE) $(MAKE_FLAGS) $(LIBFT_DIR) fclean
					@$(RM) $(NAME)
					@$(COMP_FCLEAN)

re:					fclean all

bonus:				all

help:
					$(HELP)

-include			$(DEPS)

.PHONY:				all clean fclean re bonus norm

