# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfranque <gfranque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/28 12:52:13 by gfranque          #+#    #+#              #
#    Updated: 2023/05/15 17:44:14 by gfranque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = ./main.c ./bultins/echo.c ./bultins/cd.c ./bultins/pwd.c ./parsing/controll.c\
		./bultins/env.c ./bultins/unset.c ./bultins/export.c ./bultins/export_utils.c\
		./exec/command.c ./exec/redirection.c error.c ./exec/check_command.c\
		./exec/check_command_utils.c ./exec/fork.c ./exec/fork_2.c ./exec/fork_3.c\
		./Parsing/datahandling.c ./Parsing/dataprocessing.c ./Parsing/dataprocessing2.c\
		./Parsing/textprocessing.c ./Parsing/charstuff.c ./Parsing/lexing1.c\
		./Parsing/lexing2.c ./Parsing/lexing3.c ./Parsing/tokenhandling.c\
		./Parsing/parsing1.c ./Parsing/parsing2.c ./Parsing/parsing3.c\
		./Parsing/parseur.c ./Parsing/parseurredir.c ./redirection/here_doc.c\
		./Parsing/expandprocessing.c ./exec/commandclose.c ./bultins/exit.c\

PRINTF = ./source/Printf/libftprintf.a

INCLUDES = -I ./include/

LIBFTINC = -I ./source/Libft/

LIBFT = ./source/Libft/libft.a

SRC_DIR = source

OBJ_DIR = objet

MORE_DIR = $(OBJ_DIR)/bultins $(OBJ_DIR)/parsing $(OBJ_DIR)/exec $(OBJ_DIR)/Parsing $(OBJ_DIR)/redirection $(OBJ_DIR)/gnl

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

BACKGREEN = \033[42m

BOLDCYAN = \033[1;36m

BOLDBLUE = \033[1;34m

###############
###	RULES	###
###############

all:	$(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(MKDIR) $(OBJ_DIR)
	@$(MKDIR) $(MORE_DIR)
	$(COLORCYAN)
	$(GCC) $(FLAGS) $(LIBFTINC) $(INCLUDES) -c $< -o $@
	$(UNCOLOR)

$(NAME):	$(OBJS)
	@echo "$(BOLDCYAN) Minishell $(RESET)"
	$(COLORGREEN)
	make -C ./source/Libft
	$(UNCOLOR)
	$(COLORCYAN)
	$(GCC) $(FLAGS) -o $(NAME) $(LIBFTINC) $(INCLUDES) $(OBJS) $(LIBFT) $(READLINE)
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
	$(UNCOLOR)
	$(COLORYELLOW)
	$(RM) $(NAME) $(NAMEBONUS)
	$(UNCOLOR)
	@echo "$(BACKYELLOW)$(WHITE) Fclean done $(RESET)"

re: fclean all

m: all clean

.PHONY: all clean fclean re m bonus
