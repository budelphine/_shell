/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 19:08:35 by budelphi          #+#    #+#             */
/*   Updated: 2021/03/23 20:16:32 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

# include <term.h>
# include <termcap.h>
# include <termios.h>

/*
** DEFINE && GLOBAL
*/

# define S_PROMT "\e[4;96m21shell$\e[m "

/*
** SYNTAX && GLOBAL ERROR MESSAGE
*/

# define E_MLC  "21shell: Malloc error..."
# define E_ARGC "21shell: Wrong number of arguments..."
# define E_RSET "21shell: syntax error near unexpected token `"
# define E_RSEN "21shell: syntax error near unexpected token `newline'"

/*
** ERROR
*/

# define E_FD 2
# define N_FD 1
# define E_CODE 1
# define N_CODE 0

/*
** CONTROL SEQUENCES
*/

# define S_ALL   "\\\'\"$|><; "
# define S_ALLNS "\\\'\"$|><;"
# define S_NNRM  "\'\"|><; "
# define S_NRM   "\\\'\"$; "
# define S_SLH   "\\\'\"$"
# define S_QTE   "\'\""
# define S_PSM   "\\\"$"
# define S_CMD   "|><;"
# define S_SPIP  "|;"
# define S_RED   "><"
# define S_RRED  ">>"
# define S_SCMD  "|><; "
# define S_PRR   "|><;"
# define S_SRED  ">< "
# define S_NSLH  "\\\"$`"

# define M_DQTE  "\\\""

/*
** ONE CHAR
*/

# define S_SLASH "\\"
# define S_DQTE  "\""
# define S_OQTE  "\'"
# define S_PIPE  "|"
# define S_DEF   "$"
# define S_SPC   " "

# define S_ENDP  "><|; "
# define S_ENDC  " ;/"
# define S_ENDCQ " ;/\""

/*
** COMMAND
*/

# define C_ECHO "echo"
# define C_EXIT "exit"

/*
** STRUCT
*/

typedef struct		s_flag
{
	int				cmd;
	int				end;
	int				semi;
	int				pipe;
	int				all_red;
	int				rev_red;
	int				dir_red;
	int				rew_red;
	int				count_param;
	int				*red_i;
	char			*name;
	char			**param;
	char			**file;
	struct s_flag	*next_pipe;
}					t_flag;

typedef struct		s_hist
{
	struct termios	term;
	char			*term_name;
	int				byte_readed;
	char			buf[200];
	char			**hist;
	char			*del_tmp;
	int				cur_hist;
	int				max_hist;
}					t_hist;

/*
** MAIN
*/

void				ft_minishell(void);
void				ft_command(t_flag **head);
t_flag				*ft_parser(char **format);

/*
** PARSER
*/

void				ft_parse_param(char **format, t_flag *flag);
void				ft_parse_info(char **format, t_flag *flag);
int					ft_is_parse_error(char *copy_format, t_flag *head, \
					t_flag *cur_flag);
t_flag				*ft_parse_cmd(char **format, t_flag *flag);

/*
** KEY UTILS
*/

int					ft_key_len(char *my_key);
int					ft_key_index(char *my_key);
char				*ft_get_key_value(int key_index);

/*
** TERMCAP
*/

int					ft_promt(void);
int					ft_putchar(int ch);

int					ft_get_line(char **format);

void				ft_switch_canon_on(t_hist *tmp);
void				ft_switch_canon_off(t_hist *tmp);
void				ft_backspace(char **hist, int *cur_hist);
void				ft_print(char **hist, char buf[], int byte_readed, \
					int *cur_hist);
void				ft_hist_prev(char **hist, int *cur_hist, int *max_hist);
void				ft_hist_next(char **hist, int *cur_hist, int *max_hist);

/*
** PARSER UTILS
*/

char				*ft_add_quote(char **format);
char				*ft_add_double_quote(char **format);
char				*ft_add_normal_param(char **format);
char				**ft_add_param(char **old_arr, char *new_param, \
					int len_arr);

char				*ft_parse_define(char **format);
char				*ft_parse_slash(char **format, int flag);
char				*ft_parse_normal(char **format, char *set);

/*
** PARSER CMD
*/

t_flag				*ft_add_redirect(char **format, t_flag *flag);
t_flag				*ft_add_pipe(t_flag *flag);

/*
** STRUCT UTILS
*/

t_flag				*ft_flag_new(void);
t_flag				ft_init_flag(void);

t_flag				*ft_flag_last(t_flag *cur_flag);
t_flag				*ft_lst_last(t_flag *cur_flag);
t_flag				*ft_lst_prev(t_flag *head, t_flag *cur_flag);

void				ft_clear_leaks(t_flag **head, t_flag **flag);
void				ft_lst_clear(t_flag **lst, void (*del)(char **, int));
void				ft_lst_delone(t_flag **cur_flag, void (*del)(char **, int));
void				ft_lst_dellast(t_flag **head, void (*del)(char **, int));

/*
** MAIN UTILS
*/

void				*ft_remove_pptr(char **arr);
void				ft_remove_arr(char **arr, int i_cur);
char				*ft_add_str_space(char **format, char *new_param, \
					t_flag *flag);

int					ft_is_symbol(char *set, char ch);
int					ft_move_format(char *set, char **format);
void				ft_move_normal(char **format);
void				ft_move_oqte(char **format);
void				ft_move_dqte(char **format);
void				ft_move_cmd(char **format);

/*
** SYNTAX ERROR
*/

char				*ft_choose_token(char *format);
int					ft_syntax_error(char *format);
int					ft_check_new_line(char *line);
int					ft_print_syntax_error(char **token);

/*
** OTHER UTILS
*/

/*
** void				ft_print_command(t_flag *flag);
*/

int					ft_create_genv(char **env);
void				ft_error(char *error, int exit_code, int fd);

#endif
