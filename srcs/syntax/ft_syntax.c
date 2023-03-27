/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:09:27 by mjulliat          #+#    #+#             */
/*   Updated: 2023/03/27 14:37:38 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_syntax(t_minishell *ms)
{
	t_list_token	*start;
	int				code_error;

	code_error = 0;
	start = ms->token;
	code_error = ft_check_syntax(ms->token);
	if (code_error != 0)
	{
		ms->syntax = 1;
		ms->token = start;
		ft_display_error_syntax(code_error);
		return (1);
	}
	ms->syntax = 0;
	ms->token = start;
	return (0);
}

int	ft_check_syntax(t_list_token *syntax)
{
	while (syntax != NULL)
	{
		if (ft_quote_closed(syntax->word) == 1)
			return (1);
		else if (ft_redirection_check(syntax) == 1)
			return (2);
		else if (ft_pipe_check(syntax) == 1)
			return (3);
		syntax = syntax->next;
	}
	return (0);
}

int	ft_redirection_check(t_list_token *syntax)
{
	if (syntax->next != NULL)
	{
		if (syntax->type == E_REDIRECTION && syntax->next->type != E_STRING)
			return (1);
	}
	if (syntax->type == E_REDIRECTION && syntax->next == NULL)
		return (1);
	return (0);
}

void	ft_display_error_syntax(int code_error)
{
	if (code_error == 1)
		printf("minishell: syntax error quote not closed\n");
	else if (code_error == 2)
		printf("minishell: syntax error near unexpected token `<' or `>'\n");
	else if (code_error == 3)
		printf("minishell: syntax error near unexpected token `|'\n");
}
