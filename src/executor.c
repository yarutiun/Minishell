/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:07:07 by yarutiun          #+#    #+#             */
/*   Updated: 2023/03/22 19:33:41 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

int	command_exec_prep(t_pipe_group *data, t_pipe_group *prev, int in_fd, int out_fd)
{
	char	*x_p;

	if (data->output != -1)
		out_fd = data->output;
	if (data->input != -1)
		in_fd = data->input;
	if (prev->output != -1)
		in_fd = STDIN_FILENO;
	x_p = get_working_path(data->cmd, shell_h->envp);
	if (!x_p)
	{
		// ft_put_error();
		return (STDIN_FILENO);
	}
	return(fork_and_execute(data, in_fd, out_fd, x_p));
	// if (data->command[i].input[0])
	// 	in_fd = prep_input_fd(data, i, in_fd);
	// if (in_fd < 0)
	// 	return (cleanup_command(0, 0, 0));
	// if (data->command[i].input[0] == NULL && i < 1)
	// 	in_fd = -2;
	// if (data->command[i].output[0])
	// 	out_fd = prep_output_fd(data, i, STDOUT_FILENO);
	// if (out_fd < 0)
	// 	return (cleanup_command(1, in_fd, 0));
	// if (data->command[i].output[0] == NULL && i < (data->command_amt - 1))
	// 	out_fd = -2;
	// if (data->command[i].cmd_flags[0] == NULL)
	// 	return (cleanup_command(2, in_fd, out_fd));
	// if (find_exeption_command(data->command[i].cmd_flags[0]) != NULL)
	// 	return (fork_for_exeption_command(data, in_fd, out_fd));
	// x_p = find_executable_path(data->command[i].cmd_flags[0], data->env, data);
	// if (x_p == NULL)
	// 	return (cleanup_command(2, in_fd, out_fd));
	// if (data->command[i].cmd_flags[0] != x_p)
	// 	free(data->command[i].cmd_flags[0]);
	// data->command[i].cmd_flags[0] = x_p;
	// return (fork_and_execute(data, in_fd, out_fd));
}

int	executor(t_pipe_group *data)
{
	int				pipe_fd;
	t_pipe_group	*prev;

	pipe_fd = STDIN_FILENO;
	while (data)
	{
		pipe_fd = command_exec_prep(data, prev, pipe_fd, STDOUT_FILENO);
		prev = data;
		data = data->next;
	}
	if (pipe_fd > 2)
		close(pipe_fd);
	return (0);
}
