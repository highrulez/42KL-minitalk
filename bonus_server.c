/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_server.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aawgku-o <aawgku-o@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:11:29 by aawgku-o          #+#    #+#             */
/*   Updated: 2023/12/10 17:45:08 by aawgku-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_minitalk.h"

void	ft_bitrary(int x, siginfo_t *info)
{
	static int	bit = 7;
	static int	set = 0;

	set += (x << bit);
	if (bit == 0)
	{
		write(1, &set, 1);
		bit = 7;
		set = 0;
		kill(info->si_pid, SIGUSR2);
	}
	else
		bit--;
}

void	ft_sig_control(int x, siginfo_t *info, void *context)
{
	if (x == SIGUSR1)
		ft_bitrary(1, info);
	else
	{
		ft_bitrary(0, info);
		(void)context;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sig;

	pid = getpid();
	ft_printf("\n");
	ft_printf("\033[0;35mWelcome To Highrulez's Dummy Server!\n\n");
	ft_printf("\033[0;36mYour Process Identifier # is: \033[0;33m%u\n\n", pid);
	ft_printf("\033[0;37mMessage Received:\n", pid);
	sig.sa_sigaction = ft_sig_control;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
