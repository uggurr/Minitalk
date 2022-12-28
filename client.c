#include "minitalk.h"

void	handle_sigint(pid_t pid, char *sign)
{
	int		bit;

	while (*sign)
	{
		bit = 8;
		while (bit--)
		{
			if ((*sign >> bit) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
		sign++;
	}
}

int	main(int ag, char **av)
{
	pid_t	pid;

	pid = ft_atoi(av[1]);
	if (ag != 3)
		return (0);
	handle_sigint(pid, av[2]);
}
