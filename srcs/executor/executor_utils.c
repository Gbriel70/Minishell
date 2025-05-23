/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 09:34:06 by gabastos          #+#    #+#             */
/*   Updated: 2025/03/11 13:51:12 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	close_all_fds(int **fds, int pipe_count)
{
	int	i;

	if (!fds)
		return ;
	i = -1;
	while (++i < pipe_count)
	{
		close(fds[i][0]);
		close(fds[i][1]);
	}
}

void	advance_to_next_cmd(t_exec *ex)
{
	while (ex->tmp && ex->tmp->type != PIPE)
		ex->tmp = ex->tmp->next;
	if (ex->tmp && ex->tmp->type == PIPE)
		ex->tmp = ex->tmp->next;
}

static void	create_pipes(t_exec *ex)
{
	int	i;
	int	pipe_count;

	pipe_count = ex->nbr_process - 1;
	if (pipe_count <= 0)
		return ;
	ex->fds = gc_malloc(sizeof(int *) * pipe_count);
	if (!ex->fds)
		return ;
	gc_add(ex->fds);
	i = 0;
	while (i < pipe_count)
	{
		ex->fds[i] = gc_malloc(sizeof(int) * 2);
		if (!ex->fds[i])
			return ;
		gc_add(ex->fds[i]);
		if (!ex->fds[i] || pipe(ex->fds[i]) == -1)
			return ;
		i++;
	}
}

static int	count_process(t_token *tokens)
{
	t_token	*tmp;
	int		count;

	count = 1;
	tmp = tokens;
	while (tmp)
	{
		if (tmp->type == PIPE)
			count++;
		tmp = tmp->next;
	}
	return (count);
}

t_exec	init_executor(t_data *data)
{
	t_exec	ex;

	ex.nbr_process = count_process(data->tokens);
	ex.pid = NULL;
	ex.fds = NULL;
	ex.status = 0;
	ex.tmp = data->tokens;
	create_pipes(&ex);
	return (ex);
}
