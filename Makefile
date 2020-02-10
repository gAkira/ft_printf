# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galves-d <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/04 02:08:26 by galves-d          #+#    #+#              #
#    Updated: 2020/02/09 21:30:07 by galves-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

CC			=	gcc
C_FLAGS		=	-Wall -Wextra -Werror

INC			=	.

LIB_DIR		=	./libft/
LIB			=	ft

SRCS_DIR	=	.
SRCS		=	$(SRCS_DIR)/ft_printf.c				\
				$(SRCS_DIR)/ft_new_fmt.c			\
				$(SRCS_DIR)/ft_del_fmt.c			\
				$(SRCS_DIR)/ft_build_output.c		\
				$(SRCS_DIR)/ft_realloc_strchar.c	\
				$(SRCS_DIR)/ft_new_id.c				\
				$(SRCS_DIR)/ft_del_id.c				\
				$(SRCS_DIR)/ft_is_present.c			\
				$(SRCS_DIR)/ft_get_flag.c			\
				$(SRCS_DIR)/ft_get_width.c			\
				$(SRCS_DIR)/ft_get_precision.c		\
				$(SRCS_DIR)/ft_get_type.c			\
				$(SRCS_DIR)/ft_filter_id.c

OBJS_DIR	=	.
OBJS		=	$(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rcs $@ $^
	ranlib $@

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c $(LIB_DIR)/lib$(LIB).a
	$(CC) $(C_FLAGS) -I$(INC) -c $< -o $@

$(LIB_DIR)/lib$(LIB).a:
	$(MAKE) -C $(LIB_DIR) all
	$(MAKE) -C $(LIB_DIR) bonus

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIB_DIR) clean
	
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all

teste: $(NAME) $(LIB_DIR)/lib$(LIB).a
	$(CC) main.c -o output -L. -lftprintf -L$(LIB_DIR) -l$(LIB)


.PHONY: all clean fclean re
