/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siligh <siligh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:58:42 by siligh            #+#    #+#             */
/*   Updated: 2024/10/08 18:37:21 by siligh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_av(char **av)
{
	int	i;

	i = -1;
	while (av[i])
		free(av[i++]);
	free(av - 1);
	return ;
}

void	free_list(t_list **a)
{
	t_list	*current;
	t_list	*temp;

	if (a == NULL)
		return ;
	current = *a;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*a = NULL;
	return ;
}

int	free_init(t_list **a, char **av, bool two_ac)
{
	free_list(a);
	if (two_ac)
		free_av(av);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
