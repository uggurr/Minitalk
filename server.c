#include "minitalk.h"

void	handle(int sig)
{
	static int		bit;
	static int		y;

	y = y << 1;
	if (sig == SIGUSR1)
		y |= 1;
	bit++;
	if (bit == 8)
	{
		write(1, &y, 1);
		bit = 0;
		y = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("%d\n", pid);
	signal(SIGUSR1, handle);
	signal(SIGUSR2, handle);
	while (1)
		pause();
}
