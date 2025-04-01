/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabastos <gabastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 09:25:47 by gabastos          #+#    #+#             */
/*   Updated: 2025/03/10 09:25:48 by gabastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_exit(t_data *ms, char **cmd)
{
	int exit_code;

	ft_putstr_fd("exit\n", STDOUT_FILENO);
	if (!cmd[1])
	{
		gc_exit();
		exit(ms->exit_error);
	}
	else if (cmd[1] && cmd[2])
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", STDERR_FILENO);
		ms->exit_error = 1;
		return ;
	}
	else if (ft_isalnum(cmd[1] == 0))
	{
		ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
		gc_exit();
		exit(255);
	}
	exit_code = ft_atoi(cmd[1]);
	ms->exit_error = exit_code;
	gc_exit();
	exit(exit_code & 255);
}
