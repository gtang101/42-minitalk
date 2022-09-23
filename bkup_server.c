#include "minitalk.h"

void	ft_print_message(int sig, siginfo_t *info, void *context){
	static pid_t	client_pid = 0;
	static int		c;
	static int		byte;

	(void)context;
	if (info->si_pid)
		client_pid = info->si_pid;
	if (sig == SIGUSR1)
		c += 1 << (7 - byte);
	byte++;
	if (byte == 8){
		if (c == 0)
			kill(client_pid, SIGUSR1);
		ft_putchar_fd(c, 1);
		byte = 0;
		c = 0;
	}
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
