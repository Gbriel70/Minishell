#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*line;

	(void)argv;
	(void)envp;
	if (argc != 1)
		handle_erros("Usage: ./minishell", 0);
	while (1)
	{
		line = readline(GREEN"☯️💰🤡$MINI$HELL_DE_VILÃO$🤡💰☯️ $"RESET);
		if (!line)
			break ;
	}
	return (0);
}
