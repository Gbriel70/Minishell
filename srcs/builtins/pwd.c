/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabastos <gabastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 09:25:58 by gabastos          #+#    #+#             */
/*   Updated: 2025/03/10 09:25:59 by gabastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_pwd(t_data *ms, char **cmd, char **envp)
{
	char	*pwd;
    char	cwd[PATH_MAX];

    (void)envp;
    if (cmd && cmd[1])
    {
        ft_putstr_fd("minishell: pwd: too many arguments\n", STDERR_FILENO);
        ms->error = 42;
        return;
    }
    if (getcwd(cwd, PATH_MAX))
    {
        ft_putstr_fd(cwd, STDOUT_FILENO);
        ft_putstr_fd("\n", STDOUT_FILENO);
        ms->error = 0;
        return;
    }
    pwd = get_env_value("PWD", envp);
    if (pwd)
    {
        ft_putstr_fd(pwd, STDOUT_FILENO);
        ft_putstr_fd("\n", STDOUT_FILENO);
        ms->error = 0;
        return;
    }
    ft_putstr_fd("minishell: pwd: error retrieving current directory\n", STDERR_FILENO);
    ms->error = 1;
}
