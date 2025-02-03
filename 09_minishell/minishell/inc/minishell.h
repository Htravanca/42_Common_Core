/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 11:59:44 by jalves-v          #+#    #+#             */
/*   Updated: 2025/01/30 17:14:39 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <sys/wait.h>

extern volatile sig_atomic_t	signal_status;

typedef enum e_type
{
	SIMPLE = 0,
	PIPE = 1,
	REDIR_IN = 2,
	REDIR_OUT = 3,
	REDIR_OUT_APPND = 4,
	HERE_DOC = 5,
	HERE_DOC_DONE = 6,
	ERROR = 7
}								t_type;

typedef enum e_sigs
{
	PARENT = 0,
	CHILD = 1,
	HEREDOC = 2,
	PARENT_WAIT = 3
}								t_sigs;

typedef struct s_io
{
	int							fd_in;
	int							fd_out;
	int							saved_stdin;
	int							saved_stdout;
}								t_io;

typedef struct s_redir
{
	char						*filename;
	t_type						type;
	struct s_redir				*next;
}								t_redir;

typedef struct s_tokens
{
	char						**token;
	int							is_builtin;
	t_type						type;
	int							here_doc;
	t_redir						*redir;
	t_io						io;
	int							fd[2];
	pid_t						pid;
	int							heredoc_fd[2];
	struct s_tokens				*next;
}								t_tokens;

typedef struct s_envc
{
	char						*var;
	char						*value;
	int							visible;
	struct s_envc				*next;
}								t_envc;

typedef struct s_shell
{
	t_tokens					*tokens;
	char						**arr_2d;
	int							command_status;
	t_envc						*env;
	char						**env_arr;
}								t_shell;

/* parsing/parsing.c */
void							parse_input(char *cmd);

/* parsing/parsing2.c */
void							populate_lst(char **arr_split);
char							*add_char(char *str, char c);
int								get_type(char *tok);
int								closed_quotes(char *cmd);
int								check_input_aux(char *replaced);

/* parsing/aux_parsing/aux_parsing.c */
int								is_whitespace(char c);

/* parsing/aux_parsing/free_and_exit.c */
void							free_lst(void);
void							ft_free(void);
void							free_redir(t_redir **redir);
void							parsing_error(char *parsed);
void							ft_free_err(char **arr, char *err);

/* parsing/redir.c */
// char *parse_redir(char *cmd, char *replaced, int idx);
char							*parse_redir(char *cmd, char **replaced);
void							populate_redir(char **arr, t_tokens *lsttokens,
									int type);

/* parsing/parse_quotes.c */
// int get_len_quotes(char *cmd, char q);
char							*parse_quotes(char *replaced, char **cmd);

/* parsing/parse_quotes.c */
void							free_arr2(char **arr);

/* expander/expand_variable.c */
void							expand_tokens(void);

/* expander/expand_aux.c */
char							*ft_get_env(char *var);
int								in_single_quotes(char *str);
char							*trim_spaces(char *result, char **final,
									int *i);
char							*parse_status(void);

/* expander/expand_aux2.c */
char							**recreate_tokens(int i, int count, char **tok,
									char *exp);
int								check_ws(char *exp);
void							check_list(void);
int								special_char(char c);

/* signals/signal_handler.c */
void							handle_sig(t_sigs mode);

/* parsing/check_list.c */
void							check_list(void);

/* lexer/lexer.c.c */
bool							check_syntax(char *cmd);

/* lexer/lexer.c.c */
bool							validate_cmd(char *cmd_line, int len,
									bool char_found, bool quotes);
bool							whitespaces(char *cmd_line);
int								is_special_char(char c);

/**** +++++++++ */

/* parsing/aux_parsing/ft_lst.c */
void							ft_tokensadd_back(t_tokens **tokens,
									t_tokens *node);
void							ft_tokensadd_front(t_tokens **tokens,
									t_tokens *node);
t_tokens						*ft_tokenslast(t_tokens *tokens);
t_tokens						*ft_lsttoken(char **args);
t_shell							*get_shell(void);

/* expander/aux_expander/ft_strncpy.c */
char							*ft_strncpy(char *dest, char *src, int n);

/* parsing/split_aux.c */
int								count_tokens(char **arr_split);
int								check_builtin(char *tokens);

/* parsing/aux_parsing/ft_lst2.c */
t_redir							*lst_redir(void);
void							ft_lstadd_back_redir(t_redir **lst,
									t_redir *new);

/* lexer/remove_quotes.c.c */
void							check_quotes_tokens(void);
void							check_quotes_redir(t_tokens *tokens);

/********/

/********/

// NEW ENV
void							ft_lstadd_back_env(t_envc **env_new, char *env);
t_envc							*ft_env_cpy(char **env, t_envc *env_new);

// NEW ENV2
void							ft_lstclear_env(t_envc **env_new);
void							print_env_list(t_envc *env);

// ******   BUILTINS   ******
// CD
void							ft_change_pwd(t_envc *env, int out);
int								ft_cd(char **args, int out);
int								ft_go_home(int out);

// ECHO
int								ft_echo(char **args, int out);

// env
int								ft_env(t_envc *env, int out);

// EXPORT
int								ft_export(char **args, t_envc **env, int out);
char							**ft_sep_args(char *args);
void							ft_free_sep(char **arg_sep);
void							ft_print_env_sorted(t_envc *head, int out);
int								ft_print_errmsg(int out, char *arg);

// PWD
int								ft_pwd(int out);

// UNSET
int								ft_unset(char **args, t_envc **env);

// EXIT
void							ft_exit(t_tokens *tokens, int in, int out);
void							ft_finish(t_tokens *tokens, int in, int out);
void							ft_exit3(t_tokens *tokens, int in, int out);

// RUN CMD BUILTIN
void							ft_close_savedstd(t_tokens *tokens, int in,
									int out);
int								check_builtins(t_tokens *tokens, int in,
									int out);

// ENV TO ARRAY
void							ft_free_arr(char **arr);
char							**ft_convert_array(t_envc *head);

// RUN CMD FILES
void							ft_handle_errorfiles(t_tokens *tokens, int in,
									int out);
void							ft_close_redir(t_tokens *tokens);
int								ft_file_error(t_tokens *tokens, int in,
									int out);

// RUN CMD HEREDOC
void							ft_here_doc(t_tokens *current);

// RUN CMD HEREDOC 2
void							ft_close_herepipe(int heredoc[2]);
void							ft_close_allpipes(t_tokens *tokens);

// PATH
char							*ft_path(char **cmdsarr, char **envp,
									char *path);

// RUN CMD REDIR
int								ft_setup_redir(t_tokens *tokens);

// RUN CMD UTILS
void							wait_all(t_tokens *current);
void							ft_close_rest(t_tokens *tokens);
void							ft_close(int fd);
int								ft_handle_error(int val, const char *msg,
									int ret_val);
void							print_path_error(char *s);

// RUN CMD
void							ft_runcmd(void);

// RUN CMD 2
void							ft_redirect(int in, int out);
void							ft_free_bf_exit(void);
void							ft_close_error(int in, int out,
									t_tokens *tokens);
void							ft_execute(t_tokens *tokens, int in, int out);

#endif
