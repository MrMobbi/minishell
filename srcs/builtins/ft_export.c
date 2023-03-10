/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 00:39:00 by thomas            #+#    #+#             */
/*   Updated: 2023/03/13 15:55:42 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_all_exported_vars(char **env);

void ft_export(t_minishell *ms, char **option)
{
	char	*key;
	char	*value;

	option++; // skip the command name
	if (*option == NULL)
		ft_print_all_exported_vars(ms->env);
	while (*option)
	{
		if (strchr(*option, '=') != NULL)
		{
			key = ft_strdup(*option);
			if (!key)
				continue;
			key[ft_strlen(*option) - ft_strlen(ft_strchr(*option, '='))] = '\0';
			value = ft_strchr(*option, '=') + 1;
			printf("key : %s\n", key);
			printf("value : %s\n", value);
			ft_setenv(ms, key, value, 1);
			// if (new_env != NULL)
			// {
			// 	ft_free_env(ms->env);
			// 	ms->env = new_env;
			// }
			free(key);
			// else
			// 	ft_putstr_fd("export: not a valid identifier: \n", 2);
		}
		else // only add it
		{
			// char *new_key;
			ft_setenv(ms, *option, "", 1);
			// ft_unsetenv(ms->env, )
			// if the key is not already in the env, add the key with setenv
			// int i = 0;
			// while (ms->env[i] && ft_strncmp(*option, ft_strlen(ms->env[i])))

		}
		// else
		// {
		// 	// ft_putstr_fd("export: not a valid identifier: \n", 2); // what if there is no '=' ?
		// }
		option++;
	}
}

char **sort_strings(char **arr, int n) {
	int i, j;
	char *temp;


	for (i = 0; i < n-1; i++) {
		for (j = 0; j < n-i-1; j++) {
			if (strcmp(arr[j], arr[j+1]) > 0) {
				temp = arr[j];
				arr[j] = arr[j+1];
				// sorted_arr[j] = arr[j+1];
				arr[j+1] = temp;
				// sorted_arr[j+1] = temp;
			}
		}
	}
	return (arr);
}

void print_sorted(char **arr, int n) {
	int i;
	int k;
	char	**sorted_arr;
	char	**copy_arr;

	copy_arr = malloc(sizeof(*arr) * (n + 1));
	k = -1;
	while (arr[++k])
		copy_arr[k] = ft_strdup(arr[k]);
	copy_arr[k] = NULL;

	sorted_arr = sort_strings(copy_arr, n);

	for (i = 0; i < n; i++) {
		printf("declare -x ");
		printf("%s\n", sorted_arr[i]);
	}

	ft_free_env(copy_arr);
}
void	ft_print_all_exported_vars(char **env)
{
	int		env_size;
	printf("lets go\n");
	env_size = 0;
	while (env[env_size])
		env_size++;
	print_sorted(env, env_size);
}
