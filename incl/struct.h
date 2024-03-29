/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:41:49 by thomas            #+#    #+#             */
/*   Updated: 2023/04/11 18:09:03 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

// global variable
extern int				g_last_exit_status;

//		### All Data ###

typedef struct s_minishell {
	char				**env;
	int					fd_pipe[2];
	int					fd_tmp_pipe;
	int					syntax;
	struct s_list_token	*token;
	struct s_list_cmd	*cmd;
}						t_minishell;

//		### Chain List Token ###

typedef struct s_list_token {
	char				*word;
	int					type;
	int					red;
	int					quote;
	struct s_list_token	*next;
	struct s_list_token	*previous;
}						t_list_token;

typedef t_list_token	t_tok;

//		### Chain List Var_env ####

typedef struct s_list_venv {
	char				*word;
	struct s_list_venv	*next;
	struct s_list_venv	*previous;
}						t_list_venv;

typedef t_list_venv		t_venv;

//		### Chain List Cmd ###

typedef struct s_list_cmd {
	char				*cmd;
	char				**option;
	int					fd_read;
	int					fd_write;
	struct s_list_cmd	*next;
}						t_list_cmd;

typedef t_list_cmd		t_lcmd;

typedef struct s_cmd {
	char				*cmd;
	char				**option;
	int					read;
	int					write;
}						t_cmd;

#endif
