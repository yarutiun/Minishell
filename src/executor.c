/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:07:07 by yarutiun          #+#    #+#             */
/*   Updated: 2023/03/23 16:16:17 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

int	child_proccess_managing_outfds(int out_fd, int pipe_fd[])
{
	int	check;

	if (out_fd == -1 || out_fd == -2)
	{
		dup2(pipe_fd[1], STDOUT_FILENO);
		// if (check < 0)
		// 	return (print_error_message("dup2", NULL));
		return (pipe_fd[1]);
	}
	if (out_fd != STDOUT_FILENO)
		dup2(out_fd, STDOUT_FILENO);
	// if (check < 0)
	// 	return (print_error_message("dup2", NULL));
	// close(pipe_fd[1]);
	// if (check < 0)
	// 	return (print_error_message("close", NULL));
	return (out_fd);
}

void	child_process_prep(t_pipe_group *data, int in_fd, int out_fd, int pipe_fd[])
{
	int		in;
	int		out;
	char	*x_p;

	ft_putstr_fd("child start", 1);
	if (in_fd != STDIN_FILENO)
		dup2(in_fd, STDIN_FILENO);
	// if (in < 0)
	// 	exit(-1);
	out = child_proccess_managing_outfds(out_fd, pipe_fd);
	// if (out < 0)
	// 	exit(-1);
	x_p = get_working_path(data->cmd, shell_h->envp);
	ft_putstr_fd("child after", 1);
	execve(x_p, data->argv, shell_h->envp);
	// print_error_message("execve", data->command[data->i].cmd_flags[0]);
	close(in_fd);
	close(out);
	exit(-1);
}

int	fork_and_execute(t_pipe_group *data, int in_fd, int out_fd, char *x_p)
{
	int	pipe_fd[2];
	int	pid;

	// if (pipe(pipe_fd) == -1)
	// 	return (print_error_message("pipe", NULL));
	// handle_child_signals();
	pipe(pipe_fd);
	ft_putstr_fd("fork start", 1);
	pid = fork();
	// if (pid == -1)
	// 	return (print_error_message("fork", NULL));
	if (pid == 0)
		child_process_prep(data, in_fd, out_fd, pipe_fd);
	waitpid(pid, &(shell_h->error), 0);
	// handle_sigs_interactive();
	if ((shell_h->error) > 255)
		(shell_h->error) /= 256;
	close(pipe_fd[1]);
	if (in_fd > 2)
		close(in_fd);
	if (out_fd > 2)
		close(out_fd);
	return (pipe_fd[0]);
}

int	command_exec_prep(t_pipe_group *data, t_pipe_group *prev, int in_fd, int out_fd)
{
	char	*x_p;

	if (data->output != -1)
		out_fd = data->output;
	else if (shell_h->last == data->pipe_index)
		out_fd = STDOUT_FILENO;
	if (data->input != -1)
		in_fd = data->input;
	else if (prev && prev->output != -1)
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
	prev = NULL;
	while (data)
	{
		pipe_fd = command_exec_prep(data, prev, pipe_fd, -1);
		prev = data;
		data = data->next;
	}
	if (pipe_fd > 2)
		close(pipe_fd);
	return (0);
}
