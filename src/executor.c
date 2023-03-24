/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:07:07 by yarutiun          #+#    #+#             */
/*   Updated: 2023/03/24 18:10:27 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

int	child_proccess_managing_outfds(int out_fd, int pipe_fd[])
{
	int	check;

	if (out_fd == -1 || out_fd == -2)
	{
		dup2(pipe_fd[1], STDOUT_FILENO);
		return (pipe_fd[1]);
	}
	if (out_fd != STDOUT_FILENO)
		dup2(out_fd, STDOUT_FILENO);
	return (out_fd);
}
int	exec_builtin_child(t_pipe_group *pipes)
{
	int err;

	if (ft_strcmp(pipes->argv[0], "pwd") == 0)
		err = (ft_pwd());
	else if (ft_strcmp(pipes->argv[0], "env") == 0)
		err = (ft_env());
	else if (ft_strcmp(pipes->argv[0], "echo") == 0)
		err = (b_echo(pipes->argv));
	else
		return (-1);
	shell_h->error = err;
	return (0);
}

int	exec_builtin_parent(t_pipe_group *pipes)
{
	int	err;

	if (ft_strcmp(pipes->argv[0], "unset") == 0)
		err = b_unset(&pipes->argv[1]);
	else if (ft_strcmp(pipes->argv[0], "export") == 0)
		err = b_export(pipes->argv);
	else if (ft_strcmp(pipes->argv[0], "cd") == 0)
		err = b_cd(pipes->argv[1]);
	else if (ft_strcmp(pipes->argv[0], "exit") == 0)
		err =  b_exit(pipes->argv);
	else
		return (-1);
	shell_h->error = err;
	return (0);
}

void	child_process_prep(t_pipe_group *data, int in_fd, int out_fd, int pipe_fd[])
{
	int		in;
	int		out;
	char	*x_p;

	child_sig();
	if (in_fd != STDIN_FILENO)
		dup2(in_fd, STDIN_FILENO);
	out = child_proccess_managing_outfds(out_fd, pipe_fd);
	if(exec_builtin_child(data) != -1)
		exit(0);
	x_p = get_working_path(data->cmd, shell_h->envp);
	execve(x_p, data->argv, shell_h->envp);
	throw_error_exec("minishell: couldn't run process\n");
	close(in_fd);
	close(out);
	exit(-1);
}

int	fork_and_execute(t_pipe_group *data, int in_fd, int out_fd)
{
	int	pipe_fd[2];
	int	pid;

	pipe(pipe_fd);
	pid = fork();
	if (pid == 0)
		child_process_prep(data, in_fd, out_fd, pipe_fd);
	waitpid(pid, &(shell_h->error), 0);
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
		throw_error_exec("minishell: command not found\n");
		return (STDIN_FILENO);
	}
	free(x_p);
	return(fork_and_execute(data, in_fd, out_fd));
}

int	executor(t_pipe_group *data)
{
	int				pipe_fd;
	t_pipe_group	*prev;

	pipe_fd = STDIN_FILENO;
	prev = NULL;
	while (data)
	{
		if(shell_h->last == 0 && exec_builtin_parent(data) != -1)
		{
			data = data->next;
			continue;
		}
		pipe_fd = command_exec_prep(data, prev, pipe_fd, -1);
		prev = data;
		data = data->next;
	}
	if (pipe_fd > 2)
		close(pipe_fd);
	return (0);
}
