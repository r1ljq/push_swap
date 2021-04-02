/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <erlajoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 11:54:25 by erlajoua          #+#    #+#             */
/*   Updated: 2021/04/02 08:49:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"
#include "../headers/get_next_line.h"

int		exec_ope(char *line, t_list **a, t_list **b)
{
	if (ft_strcmp(line, "sa") == 0)
		sa(a, 1);
	else if (ft_strcmp(line, "sb") == 0)
		sb(b, 1);
	else if (ft_strcmp(line, "ss") == 0)
		ss(a, b, 1);
	else if (ft_strcmp(line, "pa") == 0)
		pa(a, b, 1);
	else if (ft_strcmp(line, "pb") == 0)
		pb(a, b, 1);
	else if (ft_strcmp(line, "ra") == 0)
		ra(a, 1);
	else if (ft_strcmp(line, "rb") == 0)
		rb(b, 1);
	else if (ft_strcmp(line, "rr") == 0)
		rr(a, b, 1);
	else if (ft_strcmp(line, "rra") == 0)
		rra(a, 1);
	else if (ft_strcmp(line, "rrb") == 0)
		rrb(b, 1);
	else if (ft_strcmp(line, "rrr") == 0)
		rrr(a, b, 1);
	else
		return (0);
	return (1);
}

int		get_operations(t_list **a, t_list **b)
{
	char *line;

	while (get_next_line(0, &line, 0))
	{
		if (!(exec_ope(line, a, b)))
		{
			lst_clear(a);
			lst_clear(b);
			get_next_line(666, NULL, 1);
			write(STDERR_FILENO, "Error\n", 6);
			free(line);
			return (0);
		}
		free(line);
	}
	free(line);
	return (1);
}

int		is_sort(t_list **a)
{
	t_list *tmp;

	tmp = *a;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_list *a;
	t_list *b;

	b = NULL;
	a = NULL;
	if (ac <= 1)
		return (0);
	if (!(get_list_a(&a, ac, av)))
		return (0);
	if (!(get_operations(&a, &b)))
		return (0);
	if (is_sort(&a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	lst_clear(&a);
	lst_clear(&b);
	return (0);
}
