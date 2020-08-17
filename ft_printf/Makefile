# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galves-d <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/04 02:08:26 by galves-d          #+#    #+#              #
#    Updated: 2020/03/06 15:43:38 by galves-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

CC			=	gcc
C_FLAGS		=	-Wall -Wextra -Werror

INC			=	.

LIB_DIR		=	./libft
LIB			=	$(LIB_DIR)/libft.a

SRCS_DIR	=	./src
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
				$(SRCS_DIR)/ft_process_p.c			\
				$(SRCS_DIR)/ft_process_d.c			\
				$(SRCS_DIR)/ft_process_i.c			\
				$(SRCS_DIR)/ft_process_u.c			\
				$(SRCS_DIR)/ft_process_x.c			\
				$(SRCS_DIR)/ft_process_xu.c			\
				$(SRCS_DIR)/ft_process_pc.c

OBJS_DIR	=	./obj
OBJS		=	$(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

TEST_DIR	=	./test

all:	$(NAME)

$(NAME):	$(OBJS)	$(LIB)
	cp $(LIB) $(OBJS_DIR)
	mv $(subst $(LIB_DIR), $(OBJS_DIR), $(LIB)) $(NAME)
	ar rcs $@ $(OBJS)
	ranlib $@

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(C_FLAGS) -I$(INC) -I$(LIB_DIR) -c $< -o $@

$(LIB):
	$(MAKE) -C $(LIB_DIR) all

clean:
	$(MAKE) -C $(LIB_DIR) clean
	$(RM) -r $(OBJS_DIR)
	
fclean: clean
	$(MAKE) -C $(LIB_DIR) fclean
	$(RM) $(NAME) $(LIB)

re: fclean all

v:	all
	$(CC) $(C_FLAGS) -I. libftprintf.a -I. $(TEST_DIR)/teste.c -o output
	valgrind --leak-check=full ./output
	@$(RM) ./output

l:	all
	$(CC) $(C_FLAGS) -I. libftprintf.a -I. $(TEST_DIR)/teste.c -o output
	lldb ./output
	@$(RM) ./output

t:	all
	$(CC) $(C_FLAGS) -I. libftprintf.a -I. $(TEST_DIR)/teste.c -o output
	./output
	@$(RM) ./output

d:
	@$(CC) $(C_FLAGS) $(TEST_DIR)/main.c -o output
	@./output
	@$(RM) ./output


.PHONY: all clean fclean re
