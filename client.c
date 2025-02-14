/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbou-dou <hbou-dou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:37:32 by moaziz            #+#    #+#             */
/*   Updated: 2025/02/14 13:58:34 by hbou-dou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_char(int pid, unsigned char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		i--;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac != 3)
	{
		ft_putstr("Usage: ./client <server_PID> <message>\n");
		return (0);
	}
	pid = ft_atoi(av[1]);
	if (pid == -1)
	{
		ft_putstr("Invalid PID, must be numeric only :)\n");
		return (1);
	}
	if (kill(pid, 0) == -1)
	{
		ft_putstr("Error: No such process with the given PID\n");
		return (1);
	}
	while (av[2][i])
		send_char(pid, (unsigned char)av[2][i++]);
	send_char(pid, '\0');
	return (0);
}
