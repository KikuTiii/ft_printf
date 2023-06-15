NAME = libftprintf.a
CC = gcc
BUILD = ./lixo/
CFLAGS = -Wall -Wextra -Werror
VPATH = ./utils/ ./Format/
SRC =	calloc.c itoa_base.c strdup.c \
		strlen.c putnbr_fd.c putchar_fd.c \
		ft_format_character.c ft_format_decimal.c \
		ft_format_lowHex.c ft_format_percent.c ft_format_pointer.c \
		ft_format_string.c ft_format_unsigned.c ft_format_upperHex.c \
		ft_printf.c putstr_fd.c \

OBJ = $(addprefix $(BUILD), $(SRC:.c=.o))

all: $(NAME)

$(NAME) : $(OBJ)
		@ar -rcs $(NAME) $(OBJ)
$(BUILD)%.o:%.c
		@test -d $(BUILD) || mkdir $(BUILD)
		$(CC) $(CFLAGS) -c $< -o $@
clean:
		rm -rf $(OBJ)
fclean: clean
		rm -f *.a
re: fclean all
.PHONY: all clean fclean re