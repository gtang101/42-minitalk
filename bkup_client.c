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

void	ft_client_handler(int sig){
	if (sig == SIGUSR1){
		ft_printf("Message Sent\n");
		exit(EXIT_SUCCESS);
	}
}

void	ft_send_message(int pid, unsigned char c){
	int	arr[8];
	int	i;

	i = 7;
	while (c > 0)
	{
		if (c % 2 == 1)
			arr[i] = 1;
		else
			arr[i] = 0;
			c = c / 2;
			i--;
	}
	while (i >= 0)
		arr[i] = 0, i--;
	i = 0;
	while (i < 8)
	{
		if (arr[i] == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i++;
		usleep(300);
	}
}

int	main(int ac, char **av){
	struct sigaction	client_action;
	int					i;

	i = 0;
	client_action.sa_handler = ft_client_handler;
	if (ac != 3)
	{
		ft_printf("Please follow this format: ./client <PID> <Message>\n");
		exit(EXIT_FAILURE);
	}
	sigaction(SIGUSR1, &client_action, NULL);
	while (av[2][i]){
		ft_send_message(ft_atoi(av[1]), av[2][i]);
		i++;
	}
	ft_send_message(ft_atoi(av[1]), av[2][i]);
	while (1)
		pause();
	return (0);
}
