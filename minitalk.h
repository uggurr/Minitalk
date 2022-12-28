#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"

int		ft_atoi(const char *str);
void	handle(int sig);
void	handle_sigint(pid_t pid, char *sign);

#endif
