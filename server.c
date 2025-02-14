/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbou-dou <hbou-dou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:37:49 by moaziz            #+#    #+#             */
/*   Updated: 2025/02/14 13:59:18 by hbou-dou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	signal_handler(int signum)
{
	static int				i = 0;
	static unsigned char	c;

	if (signum == SIGUSR1)
		c |= 1;
	else if (signum == SIGUSR2)
		c |= 0;
	i++;
	if (i == 8)
	{
		if (c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		i = 0;
		c = 0;
	}
	else
		c <<= 1;
}

static void	shutdown_handler(int signum)
{
	if (signum == SIGINT)
	{
		ft_putstr("\nServer is shutting down...\n");
		exit(0);
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putstr("Your Server PID: ");
	ft_putnbr(pid);
	ft_putstr("\nServer is active... Awaiting incoming messages.\n");
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	signal(SIGINT, shutdown_handler);
	while (1)
		pause();
	return (0);
}
