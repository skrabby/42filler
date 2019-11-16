# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skrabby <skrabby@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/05 11:23:44 by skrabby           #+#    #+#              #
#    Updated: 2019/11/15 10:55:31 by skrabby          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = skrabby.filler

LIBFT = libft.a

FILLER_SRCS = main.c \
			parse_data.c \
			heatmap.c \
			map_handler.c \
			piece_handler.c \
			solver.c \
			algorithms.c \

LIB_SRCS = ft_memset.c \
	   ft_bzero.c \
	   ft_memcpy.c \
	   ft_memccpy.c \
	   ft_memmove.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_strlen.c \
	   ft_strdup.c \
	   ft_strcpy.c \
	   ft_strncpy.c \
	   ft_strcat.c \
	   ft_strncat.c \
	   ft_strlcat.c \
	   ft_strchr.c \
	   ft_strrchr.c \
	   ft_strstr.c \
	   ft_strnstr.c \
	   ft_strcmp.c \
	   ft_strncmp.c \
	   ft_atoi.c \
	   ft_isalpha.c \
	   ft_isdigit.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_memalloc.c \
	   ft_memdel.c \
	   ft_strnew.c \
	   ft_strdel.c \
	   ft_strclr.c \
	   ft_striter.c \
	   ft_striteri.c \
	   ft_strmap.c \
	   ft_strmapi.c \
	   ft_strequ.c \
	   ft_strnequ.c \
	   ft_strsub.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_strsplit.c \
	   ft_putchar.c \
	   ft_putstr.c \
	   ft_putnbr.c \
	   ft_itoa.c \
	   ft_putendl.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_lstnew.c \
	   ft_lstdel.c \
	   ft_lstdelone.c \
	   ft_lstadd.c \
	   ft_lstiter.c \
	   ft_lstmap.c \
	   ft_strndup.c \
	   ft_strreverse.c \
	   ft_lstcount.c \
	   ft_lstaddlast.c \
	   ft_lstreverse.c \
	   ft_module.c \
	   ft_nblen.c \
	   ft_strempty_symb.c \
	   ft_negativezero.c \
	   ft_putstr_null.c \
	   ft_strupr.c \
	   get_next_line.c \

OBJ = ${LIB_SRCS:.c=.o}
LIB_HEADER = libft.h
FILLER_HEADER = filler.h
LIBFT_DIR = ./libft/
FILLER_SRCS_DIR = ./srcs/
FILLER_HEADER_DIR = ./includes/

all: $(LIBFT) $(NAME)
 
$(LIBFT):
	@gcc -Wall -Wextra -Werror -c $(addprefix $(LIBFT_DIR), $(LIB_SRCS)) \
	-I $(addprefix $(LIBFT_DIR), $(LIB_HEADER))
	@ar rc $(LIBFT) $(OBJ)
	@ranlib $(LIBFT)
	@tput setaf 2; tput bold; echo "..DONE Compiling LIBFT! :]"

$(NAME): $(addprefix $(FILLER_SRCS_DIR), $(FILLER_SRCS)) $(addprefix $(LIBFT_DIR), $(LIB_SRCS)) \
		 $(addprefix $(FILLER_HEADER_DIR), $(FILLER_HEADER))
	@gcc -Wall -Wextra -Werror -o $(NAME) $(addprefix $(FILLER_SRCS_DIR), $(FILLER_SRCS)) \
	-I $(addprefix $(FILLER_HEADER_DIR), $(FILLER_HEADER)) $(LIBFT)
	@tput setaf 2; tput bold; echo "..DONE Compiling Skrabby's Filler! :]"

visual: $(LIBFT) $(NAME)
	@cd visualizer && make
	@tput setaf 4; tput bold; echo "..DONE Compiling Filler's Visiualizer! :]"
	
%.o: $(LIBFT_DIR)/%.c
	@gcc -Wall -Wextra -Werror -c $<

clean:
	@rm -f $(OBJ)
	@rm -f $(LIBFT)
	@tput setaf 5; tput bold; echo "..DONE Clean! :]"

fclean: clean
	@rm -f $(NAME)
	@tput setaf 6; tput bold; echo "..DONE Fclean! :]"

re: fclean all

.PHONY: all clean fclean re visual
