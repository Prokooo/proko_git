/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siligh <siligh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:41:05 by siligh            #+#    #+#             */
/*   Updated: 2024/10/08 18:22:41 by siligh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_last(t_list *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_list	*find_smallest(t_list *a)
{
	t_list	*smallest;
	int		i;

	if (a == NULL)
		return (NULL);
	smallest = NULL;
	i = INT_MAX;
	while (a)
	{
		if (i > a->nb)
		{
			smallest = a;
			i = a->nb;
		}
		a = a->next;
	}
	return (smallest);
}

t_list	*find_biggest(t_list *a)
{
	t_list	*biggest;
	int		i;

	if (a == NULL)
		return (NULL);
	biggest = NULL;
	i = INT_MIN;
	while (a)
	{
		if (i < a->nb)
		{
			biggest = a;
			i = a->nb;
		}
		a = a->next;
	}
	return (biggest);
}

int	count_node(t_list *stack)
{
	int	count;

	if (stack == NULL)
		return (0);
	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

bool	in_order(t_list *stack)
{
	if (stack == NULL)
		return (true);
	while (stack->next)
	{
		if (stack->nb > stack->next->nb)
			return (false);
		stack = stack->next;
	}
	return (true);
}
