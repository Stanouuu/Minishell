Make to compile

./minishell to execute

valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=ignore_readline_leaks.supp -s ./minishell to execute and check for leaks
