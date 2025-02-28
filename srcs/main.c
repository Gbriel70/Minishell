/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:09:47 by gabastos          #+#    #+#             */
/*   Updated: 2025/02/24 12:10:02 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void init(t_data *data, char **envp)
{
	data->tokens = NULL;
	data->envp = copy_envp(envp);
	data->exit_error = 0;
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_data	data;

	if (argc != 1 || argv[1])
		handle_erros("Usage: ./minishell", 0, NULL);
	init(&data, envp);
	while (1)
	{
		line = readline(GREEN"☯️💰🤡$MINI$HELL_DE_VILÃO$🤡💰☯️ $ "RESET);
		if (!line)
			break ;
		if (!parser(&data, line) && !syntax_checker(&data))
		{
			//expand(&data);
			//executer(&data);
		}
		//clear(data);
		free(line);
	}
	return (0);
}
