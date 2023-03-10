/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 00:39:31 by thomas            #+#    #+#             */
/*   Updated: 2023/03/11 00:40:34 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unset(char **env, char **option)
{
	option++; // skip the command name
	while (*option)
	{
		if (strchr(*option, '-') != NULL || ft_unsetenv(env, *option) == -1)
		{
			ft_putstr_fd("unset: not a valid identifier: \n", 2);
		}
		option++;
	}
}
