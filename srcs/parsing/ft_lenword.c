
#include "minishell.h"

int	ft_lenword_redirection(char *str, char c)
{
	int	len;

	len = 0;
	while (str[len] != '\0' && str[len] == c)
		len++;
	return (len);
}

int	ft_lenword_quote(char *str, char c)
{
	int	len;

	len = 0;
	if (str[len] == c)
		len++;
	while (str[len] != '\0' && str[len] != c)
		len++;
	if (str[len] == c)
		len++;
	return (len);
}

int	ft_lenword_space(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		if (str[len] == ' ' || str[len] == '\t')
			len++;
		else
			break ;
	}
	return (len);
}

int	ft_lenword(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		if (str[len] == ' ' || str[len] == '\'' || str[len] == '"')
			break ;
		else if (str[len] == '<' || str[len] == '>' || str[len] == '|')
			break ;
		len++;
	}
	return (len);
}
