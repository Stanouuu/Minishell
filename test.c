#include "exec.h"

/*
	Notes :

	ouverture des fichiers dans le fork
	un seul pipe necessaire
	la liste chainee pour la structure principale sera obligatoire pour eviter un parsing en plus pour juste connaitre le nombre de pipe

	structure :

	tableau de pipes
	tableau des fichiers a ouvrir (ajouter devant le nom la redirection ?)
	(liste de chainee des fichiers a ouvrir avec le numero de la commande dans l'ordre d'ouverture et si ils sont les in ou out files de la commande)
*/

int	main(int ac, char **av, char **envp)
{
	if (ac < 2)
		return (0);
	
}

char	**access(t_data data)//vraiment access pour la fonction ?? revoir la construction
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH", 4) == TRUE)
			path = ft_split(envp[i] + 4, ':');//revoir la protection (s'en servir avec access ?)
		i++;
	}//remettre path dans tous les maillons ? peut etre donner l'adresse lors de la creation d'un maillon. peut etre le faire des le debut
	return (ft_split("./", ' '));
}

int	command_summoning(t_data data)
{
	int	id;

	id = fork();
	if (id == -1)
		return (0);
	if (id == 0)
	{
		data->fd = ft_file(data->file);
		if (data->fd[0] == -1 || data->fd[1] == -1)
			return (0);
		dup2(data->fd[0], 0);//prevoir le cas ou redirection il y a et pipe qui suit
		dup2(data->fd[1], 1);//faire access juste avant !!!
		execve(data->command[0], data->command, data->envp);
		ft_close(data);//ferme tous les fd ouverts pour la commande ou pour la section ourverte entre les pipes
		exit(data->status);
	}
	return (data->status); //pas forcement utile
}