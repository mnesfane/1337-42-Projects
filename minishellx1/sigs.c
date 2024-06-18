/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssama <youssama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:26:17 by youssama          #+#    #+#             */
/*   Updated: 2022/07/07 03:47:33 by youssama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_sig_list(t_data *data)
{
	char	**sys_siglist;

	sys_siglist = data->siglist;
	memset(sys_siglist, 0, NSIG * sizeof(char));
	sys_siglist[SIGHUP] = "Hangup";
	sys_siglist[SIGQUIT] = "Quit";
	sys_siglist[SIGILL] = "Illegal instruction";
	sys_siglist[SIGTRAP] = "BPT trace/trap";
	sys_siglist[SIGABRT] = "ABORT instruction";
	sys_siglist[SIGFPE] = "Floating point exception";
	sys_siglist[SIGKILL] = "Killed";
	sys_siglist[SIGBUS] = "Bus error";
	sys_siglist[SIGSEGV] = "Segmentation fault";
	sys_siglist[SIGSYS] = "Bad system call";
	sys_siglist[SIGTERM] = "Terminated";
	sys_siglist[SIGURG] = "Urgent IO condition";
	sys_siglist[SIGSTOP] = "Stopped (signal)";
	sys_siglist[SIGTSTP] = "Stopped";
	sys_siglist[SIGTTIN] = "Stopped (tty input)";
	sys_siglist[SIGTTOU] = "Stopped (tty output)";
	sys_siglist[SIGIO] = "I/O ready";
	sys_siglist[SIGXCPU] = "CPU limit";
	sys_siglist[SIGXFSZ] = "File limit";
	sys_siglist[SIGUSR1] = "User defined signal 1";
	sys_siglist[SIGUSR2] = "User defined signal 2";
}

void	mask_sig(struct sigaction *sa)
{
	sigemptyset(&sa->sa_mask);
	sigaddset(&sa->sa_mask, SIGINT);
	sigaddset(&sa->sa_mask, SIGQUIT);
}

void	catch_sig(struct sigaction *sa)
{
	sigaction(SIGINT, sa, NULL);
	sigaction(SIGQUIT, sa, NULL);
}

void	signals_handler(int sig, siginfo_t *siginfo, void *ptr)
{
	(void) ptr;
	(void) siginfo;
	if (sig == SIGINT)
	{
		if (g_data.shell_state != SH_READING)
			return ;
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_data.exit_status = 1;
	}
}

void	init_sigaction(t_data *data)
{
	struct sigaction	sa;

	init_sig_list(data);
	memset(&sa, 0, sizeof(sa));
	sa.sa_sigaction = &signals_handler;
	sa.sa_flags = 0;
	rl_catch_signals = 0;
	data->exit_status = 0;
	mask_sig(&sa);
	catch_sig(&sa);
}
