#include "minitalk.h"
/*
int	check_pid(char *str){
	if (ft_strlen(str) > 4)
		return (0);
	while (str){
		if (!ft_isdigit(str))
			return (0);
		str++;
	}
	return (1);
}*/

static void	ft_client_action(int sig){
	static int	count;

	if (sig == SIGUSR1)
		++count;
	else
	{
		ft_printf("Received [%d] characters\n", count);
		exit(EXIT_SUCCESS);
	}
}

void	ft_send_message(int pid, char *str){
	static int	bit;
	char		c;
	while (*str){
		bit = 8;
		c = *str++;
		while (bit--){
			if (c >> bit & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
	}
	bit = 8;
	while(bit--){
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int ac, char **av){
	struct sigaction	client_action;
	
	client_action.sa_handler = ft_client_action;
	if (ac != 3)
	{
		ft_printf("Please follow this format: ./client <PID> <Message>\n");
		exit(EXIT_FAILURE);
	}
	sigaction(SIGUSR1, &client_action, NULL);
	sigaction(SIGUSR2, &client_action, NULL);
	ft_send_message(ft_atoi(av[1]), av[2]);
	while (1)
		pause();
	return (0);
}
