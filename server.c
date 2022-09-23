#include "minitalk.h"

void	ft_print_message(int sig, siginfo_t *info, void *context){
	static pid_t				client_pid = 0;
	static unsigned char		c;
	static int					bit;

	(void)context;
	if (info->si_pid)
		client_pid = info->si_pid;
	c |= (sig == SIGUSR2);
	if (++bit == 8)
	{
		bit = 0;
		if (!c)
		{
			kill(client_pid, SIGUSR2);
			client_pid = 0;
			return ;
		}
		ft_putchar_fd(c, 1);
		c = 0;
		kill (client_pid, SIGUSR1);
	}
	else
		c <<= 1;
}

int	main(void){
	struct sigaction	server_action;

	server_action.sa_flags = SA_SIGINFO;
	server_action.sa_sigaction = ft_print_message;
	sigaction(SIGUSR1, &server_action, NULL);
	sigaction(SIGUSR2, &server_action, NULL);
	ft_printf("PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
