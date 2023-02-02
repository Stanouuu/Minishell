# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/28 12:52:13 by gfranque          #+#    #+#              #
#    Updated: 2023/01/30 18:04:57 by sbarrage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = 	main.c\
		bultins/echo.c bultins/cd.c bultins/pwd.c 

INCLUDES = -I ./include/

LIBFTINC = -I ./libft/

LIBFT = ./libft/libft.a

SRC_DIR = source

OBJ_DIR = objet

SRCS = $(SRC:%=$(SRC_DIR)/%)

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

GCC = gcc

FLAGS = -Wall -Wextra -Werror -g3

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
	$(COLORCYAN)
	$(GCC) $(FLAGS) $(INCLUDES) $(LIBFTINC) -c $< -o $@
	$(UNCOLOR)
	
$(NAME):	$(OBJS)
	@echo "$(BOLDCYAN) Minishell $(RESET)"
	$(COLORGREEN)
	make -C ./libft
	$(UNCOLOR)
	$(COLORCYAN)
	$(GCC) $(FLAGS) -o $(NAME) $(INCLUDES) $(LIBFTINC) $(OBJS) $(LIBFT) $(MLX) $(LIBRARY)
	$(UNCOLOR)
	@echo "$(BOLDCYAN) Compilation completed $(RESET)"

clean:
	$(COLORYELLOW)
	$(RM) $(OBJ_DIR)
	$(RM) $(OBJBONUS_DIR)
	$(UNCOLOR)
	@echo "$(BACKYELLOW)$(WHITE) Clean done $(RESET)"

fclean:	clean
	$(COLORYELLOW)
	@make fclean -C ./libft
	$(UNCOLOR)
	$(COLORYELLOW)
	$(RM) $(NAME) $(NAMEBONUS)
	$(UNCOLOR)
	@echo "$(BACKYELLOW)$(WHITE) Fclean done $(RESET)"

re: fclean all

m: all clean

.PHONY: all clean fclean re m bonus