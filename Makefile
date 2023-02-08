# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/28 12:52:13 by gfranque          #+#    #+#              #
#    Updated: 2023/02/06 16:24:33 by sbarrage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = ./main.c ./bultins/echo.c ./bultins/cd.c ./bultins/pwd.c ./parsing/parsing_one.c

PRINTF = ./source/Printf/libftprintf.a

INCLUDES = -I ./include/

LIBFTINC = -I ./source/Libft/

PRINTFINC = -I ./source/Printf

LIBFT = ./source/Libft/libft.a

SRC_DIR = source

OBJ_DIR = objet

MORE_DIR = $(OBJ_DIR)/bultins $(OBJ_DIR)/parsing

SRCS = $(SRC:%=$(SRC_DIR)/%)

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

GCC = gcc

FLAGS = -Wall -Wextra -Werror -g3

READLINE = -lreadline

RM = rm -rf

MKDIR = mkdir -p

###############
### COLORS	###
###############

COLORGREEN = @echo -n "\033[92m"

COLORCYAN = @echo -n "\033[36m"

COLORYELLOW = @echo -n "\033[33m"

UNCOLOR = @echo -n "\033[0m"

RESET = \033[0m

WHITE = \033[37m

ORANGE = \033[41m

BLACK = \033[100m

BACKCYAN = \033[46m

BACKYELLOW = \033[43m

BOLDCYAN = \033[1;34m

BOLDBLUE = \033[1;36m

###############
###	RULES	###
###############

all:	$(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(MKDIR) $(OBJ_DIR)
	@$(MKDIR) $(MORE_DIR)
	$(COLORCYAN)
	$(GCC) $(FLAGS) $(LIBFTINC) $(PRINTFINC) $(INCLUDES) -c $< -o $@
	$(UNCOLOR)
	
$(NAME):	$(OBJS)
	@echo "$(BOLDCYAN) Minishell $(RESET)"
	$(COLORGREEN)
	make -C ./source/Libft
	make -C ./source/Printf
	$(UNCOLOR)
	$(COLORCYAN)
	$(GCC) $(FLAGS) -o $(NAME) $(LIBFTINC) $(PRINTFINC) $(INCLUDES) $(OBJS) $(LIBFT) $(PRINTF) $(READLINE)
	$(UNCOLOR)
	@echo "$(BOLDCYAN) Compilation completed $(RESET)"

clean:
	$(COLORYELLOW)
	$(RM) $(OBJ_DIR)
	$(UNCOLOR)
	@echo "$(BACKYELLOW)$(WHITE) Clean done $(RESET)"

fclean:	clean
	$(COLORYELLOW)
	@make fclean -C ./source/Libft
	@make fclean -C ./source/Printf
	$(UNCOLOR)
	$(COLORYELLOW)
	$(RM) $(NAME) $(NAMEBONUS)
	$(UNCOLOR)
	@echo "$(BACKYELLOW)$(WHITE) Fclean done $(RESET)"

re: fclean all

m: all clean

.PHONY: all clean fclean re m bonus