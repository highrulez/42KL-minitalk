/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aawgku-o <aawgku-o@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:27:15 by aawgku-o          #+#    #+#             */
/*   Updated: 2023/12/10 17:49:40 by aawgku-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_bitrary(int x)
{
	static int	bit = 7;
	static int	set = 0;

	set += (x << bit);
	if (bit == 0)
	{
		ft_printf("%c", set);
		bit = 7;
		set = 0;
	}
	else
		bit--;
}

void	ft_sig_control(int x)
{
	if (x == SIGUSR1)
		ft_bitrary(1);
	else
		ft_bitrary(0);
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("\n");
	ft_printf("\033[0;35mWelcome To Highrulez's Dummy Server!\n\n");
	ft_printf("\033[0;36mYour Process Identifier # is: \033[0;33m%u\n\n", pid);
	ft_printf("\033[0;37mMessage Received:\n", pid);
	
	signal(SIGUSR1, ft_sig_control);
	signal(SIGUSR2, ft_sig_control);
	while (1)
	{
		pause();
	}
}
