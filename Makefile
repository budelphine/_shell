# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/12 10:41:19 by budelphi          #+#    #+#              #
#    Updated: 2021/03/23 18:02:46 by budelphi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell

INC		=	.
HEADER	= 	ft_parser.h \
			minishell.h \

SRCS	=	main.c \
			minishell.c \
			command/ft_cd.c \
			command/ft_echo.c \
			command/ft_env.c \
			command/ft_exit.c \
			command/ft_export.c \
			command/ft_pwd.c \
			command/ft_unset.c \
			command/utils.c \
			command/utils_part2.c \
			other_command/ft_command.c \
			other_command/ft_cmd.c \
			other_command/ft_conveyor.c \
			other_command/ft_redirection.c \
			other_command/ft_rj_cmd.c \
			other_command/ft_signal.c \
			key/ft_get_key_value.c \
			key/ft_key_index.c \
			key/ft_key_len.c \
			parser/ft_parser.c \
			parser/ft_parse_param.c \
			parser/ft_parse_cmd.c \
			parser/ft_parse_info.c \
			parser_cmd/ft_add_pipe.c \
			parser_cmd/ft_add_redirect.c \
			parser_utils/ft_add_normal_param.c \
			parser_utils/ft_add_double_quote.c \
			parser_utils/ft_add_quote.c \
			parser_utils/ft_add_param.c \
			parser_utils/ft_parse_normal.c \
			parser_utils/ft_parse_define.c \
			parser_utils/ft_parse_slash.c \
			struct/ft_new.c \
			struct/ft_init_flag.c \
			struct/ft_clear.c \
			utils/ft_create_genv.c \
			utils/ft_error.c \
			utils/ft_move.c \
			utils/ft_parse_utils.c \
			utils/ft_syntax_error.c \
			utils/ft_print_syntax_error.c \
			termcap/ft_switch_canon.c \
			termcap/ft_hist_key.c \
			termcap/ft_get_line.c 

OBJ		=	$(SRCS:.c=.o)

# DEFINE BASE FUNCTION - GCC, FLAGS, RM

CC		=	gcc
FLAGS	=	-g

RM		=	rm -f

# INIT LIBFT LIB

LIB_FT		=	./libft -lft
ADD_LIBS	=	-L$(LIB_FT)

# LIBFT SOURCE TO DEPENDENCIES

LIBFTLIB	=	libft/libft.a
LIBFT_HEAD	=	libft/libft.h

LIBFT_SRCS	=	libft/ft_atoi.c \
				libft/ft_bzero.c \
				libft/ft_calloc.c \
				libft/ft_isalnum.c \
				libft/ft_isalpha.c \
				libft/ft_isascii.c \
				libft/ft_isdigit.c \
				libft/ft_isprint.c \
				libft/ft_itoa.c \
				libft/ft_memccpy.c \
				libft/ft_memchr.c \
				libft/ft_memcmp.c \
				libft/ft_memcpy.c \
				libft/ft_memmove.c \
				libft/ft_memset.c \
				libft/ft_putchar_fd.c \
				libft/ft_putendl_fd.c \
				libft/ft_putnbr_fd.c \
				libft/ft_putstr_fd.c \
				libft/ft_split.c \
				libft/ft_strchr.c \
				libft/ft_strdup.c \
				libft/ft_strjoin.c \
				libft/ft_strlcat.c \
				libft/ft_strlcpy.c \
				libft/ft_strlen.c \
				libft/ft_strmapi.c \
				libft/ft_strncmp.c \
				libft/ft_strnstr.c \
				libft/ft_strrchr.c \
				libft/ft_strtrim.c \
				libft/ft_substr.c \
				libft/ft_tolower.c \
				libft/ft_toupper.c \
				libft/ft_putstr.c \
				libft/ft_strdel.c \
				libft/ft_lstnew.c \
				libft/ft_lstadd_front.c \
				libft/ft_lstsize.c \
				libft/ft_lstlast.c \
				libft/ft_lstadd_back.c \
				libft/ft_lstdelone.c \
				libft/ft_lstclear.c \
				libft/ft_lstiter.c \
				libft/ft_lstmap.c

OBJS_LIBFT		= $(LIBFT_SRCS:.c=.o)

MAKE_LIBFT	=	make -C ./libft

# * MAIN RULE - all

all:		
			$(MAKE) $(NAME) -j 4

$(NAME):	$(OBJ) $(HEADER) $(LIBFTLIB) 
			$(CC) $(FLAGS) $(OBJ) $(ADD_LIBS) -I. -ltermcap -o $(NAME)

.c.o:
			$(CC) $(FLAGS) -c $< -o ${<:.c=.o}

# DEPENDENCIES TO LIBFT

$(LIBFTLIB):	$(OBJS_LIBFT) $(LIBFT_HEAD)
				$(MAKE_LIBFT)

# * OTHER RULE - clean, fclean, re

CLEAN_LIBFT		=	make clean -C ./libft
FCLEAN_LIBFT	=	make fclean -C ./libft

clean:
			$(RM) $(OBJ)
			$(RM) $(INC)/*.gch
			$(CLEAN_LIBFT)

fclean:		clean
			$(FCLEAN_LIBFT)
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re