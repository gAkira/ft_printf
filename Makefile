# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galves-d <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/04 02:08:26 by galves-d          #+#    #+#              #
#    Updated: 2020/02/27 11:22:30 by galves-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

CC			=	gcc
C_FLAGS		=	-Wall -Wextra -Werror

INC			=	.

LIB_DIR		=	./libft
LIB			=	$(LIB_DIR)/libft.a

SRCS_DIR	=	.
SRCS		=	$(SRCS_DIR)/ft_printf.c				\
				$(SRCS_DIR)/ft_free.c				\
				$(SRCS_DIR)/ft_new_fmt.c			\
				$(SRCS_DIR)/ft_del_fmt.c			\
				$(SRCS_DIR)/ft_build_output.c		\
				$(SRCS_DIR)/ft_concat_char.c		\
				$(SRCS_DIR)/ft_concat_str.c			\
				$(SRCS_DIR)/ft_new_id.c				\
				$(SRCS_DIR)/ft_del_id.c				\
				$(SRCS_DIR)/ft_is_present.c			\
				$(SRCS_DIR)/ft_has_flag.c			\
				$(SRCS_DIR)/ft_get_flag.c			\
				$(SRCS_DIR)/ft_get_width.c			\
				$(SRCS_DIR)/ft_get_precision.c		\
				$(SRCS_DIR)/ft_get_type.c			\
				$(SRCS_DIR)/ft_filter_id.c			\
				$(SRCS_DIR)/ft_process_arg.c		\
				$(SRCS_DIR)/ft_process_c.c			\
				$(SRCS_DIR)/ft_process_s.c			\
				$(SRCS_DIR)/ft_process_pc.c

OBJS_DIR	=	.
OBJS		=	$(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

all:	$(NAME)

$(NAME):	$(OBJS)	$(LIB)
	cp $(LIB) $(OBJS_DIR)
	mv $(subst $(LIB_DIR), $(OBJS_DIR), $(LIB)) $(NAME)
	ar rcs $@ $(OBJS)
	ranlib $@

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c
	$(CC) $(C_FLAGS) -I$(INC) -I$(LIB_DIR) -c $< -o $@

$(LIB):
	$(MAKE) -C $(LIB_DIR) all
	$(MAKE) -C $(LIB_DIR) bonus

clean:
	$(MAKE) -C $(LIB_DIR) clean
	$(RM) $(OBJS)
	
fclean: clean
	$(MAKE) -C $(LIB_DIR) fclean
	$(RM) $(NAME) $(LIB)

re: fclean all

t:	all
	$(CC) $(C_FLAGS) -I. libftprintf.a -I. teste.c -o output
	./output

d:
	@$(CC) $(C_FLAGS) main.c -o output
	@./output


.PHONY: all clean fclean re
