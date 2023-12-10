/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_client.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aawgku-o <aawgku-o@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:11:21 by aawgku-o          #+#    #+#             */
/*   Updated: 2023/12/10 17:56:39 by aawgku-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_minitalk.h"

static void	ft_bonus(int signal)
{
	if (signal == SIGUSR1)
		printf("\033[0;35mMessage Sent!\n");
	else
		printf("\033[0;35mMessage Sent!\n");
}

void	ft_signal(int pid, char *str)
{
	int				i;
	unsigned char	c;

	while (*str)
	{
		i = 7;
		c = *str++;
		while (i >= 0)
		{
			if ((c >> i) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(200);
			i--;
		}
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc == 3)
	{
		pid = atoi(argv[1]);
		signal(SIGUSR1, ft_bonus);
		signal(SIGUSR2, ft_bonus);
		ft_signal(pid, argv[2]);
		ft_signal(pid, "\n");
	}
	else
	{
		printf("\033[31mError: wrong format.\n");
		printf("\033[34mTry: ./client_bonus [PID] [MESSAGE]\n");
		return (1);
	}
	return (0);
}
