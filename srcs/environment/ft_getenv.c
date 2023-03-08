/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 21:22:03 by thomas            #+#    #+#             */
/*   Updated: 2023/03/07 22:33:46 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(char **env, char *key)
{
	size_t	i;
	size_t	key_end_index;

	i = 0;
	while (env[i])
	{
		key_end_index = 0;
		while (env[i][key_end_index] != '=')
			key_end_index++;
		if (ft_strncmp(env[i], key, key_end_index) == 0)
			return (env[i] + key_end_index + 1);
		i++;
	}

	return (NULL);
}