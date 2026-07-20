# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gd-hallu <gd-hallu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/09 16:43:32 by gd-hallu          #+#    #+#              #
#    Updated: 2026/06/30 21:19:00 by gd-hallu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------------- MAKE VAR ------------------- #
MAKEFLAGS			+= --no-print-directory

# ------------------ PROJECT NAME ----------------- #
NAME			:= libft.a

# ------------------- CONSTANTS ------------------- #
CC					:= cc
AR					:= ar rcs
RMRF				:= rm -rf
RMF					:= rm -f
MKDIR				:= mkdir -p
CC_VERSION			:= $(shell $(CC) --version)

# --------------- MAIN DIRECTORIES ---------------- #
HDR					:= include
OBJ					:= obj
SRC					:= src
ASM					:= asm

# ---------------- SUB_DIRECTORIES ---------------- #
STDLIB				:= stdlib
MATH				:= math
CRYPTO				:= crypto
STRINGS				:= strings
IO					:= io
FT_PRINTF			:= ft_printf
MEMORY				:= mem
SORT				:= sort
DS					:= ds
STDLIB_MALLOC		:= malloc
ALLOCATOR			:= allocator
DS_LINKEDLIST		:= linked_list
DS_HASHTABLE		:= hashtable
STRING				:= string
STACK				:= stack
STR_BUILDER			:= string_builder
GNL					:= gnl


# ------------------- COMPILER -------------------- #
ifeq ($(findstring clang,$(CC_VERSION)),clang)
    COMPILER := clang
else
ifeq ($(findstring GCC,$(CC_VERSION)),GCC)
    COMPILER := gcc
else
    $(error Unsupported compiler. Use clang or gcc)
endif
endif

# ---------------------- MODE -------------------- #
MODE				?= release

# --------------------- FLAGS --------------------- #
ifeq ($(MODE),release)
	W_FLAGS			:= -Wall -Werror -Wextra
else
	ifeq ($(COMPILER),clang)
		W_FLAGS			:= 	-Wall -Werror -Wextra -Wvla -Wpedantic -pedantic-errors -Wmisleading-indentation \
						-Wsign-conversion -Wshadow -Wnull-dereference -fshort-enums
	else ifeq ($(COMPILER),gcc)
		W_FLAGS			:= 	-Wall -Werror -Wextra -Wvla -Wpedantic -pedantic-errors -Wmisleading-indentation \
						-Wsign-conversion -Wstrict-aliasing=3 -Wduplicated-cond -Wstringop-overflow -Wshadow\
						-Wnull-dereference -Warray-bounds -Wrestrict -Wconversion
	endif
endif

# -------------------- C_FLAGS -------------------- #
ifeq ($(MODE),debug)
	C_FLAGS := -g -O1 -std=c99
else ifeq ($(MODE),debug_memory)
	C_FLAGS := -g -O1 -std=c99 -fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer
else ifeq ($(MODE),debug_thread)
	C_FLAGS := -g -O1 -std=c99 -fsanitize=thread -fno-omit-frame-pointer
else ifeq ($(MODE),release)
	C_FLAGS := -O3 -march=native -std=c99
endif

# --------------------- FILES --------------------- #

SOURCES		:= $(SRC)/$(STDLIB)/ft_atoi.c    \
$(SRC)/$(STRINGS)/ft_isalpha.c \
$(SRC)/$(MEMORY)/ft_memcmp.c  \
$(SRC)/$(STRINGS)/ft_strdup.c  \
$(SRC)/$(STRINGS)/ft_strnstr.c \
$(SRC)/$(MEMORY)/ft_bzero.c   \
$(SRC)/$(STRINGS)/ft_isascii.c \
$(SRC)/$(MEMORY)/ft_memcpy.c  \
$(SRC)/$(STRINGS)/ft_strlcat.c \
$(SRC)/$(STRINGS)/ft_strchr.c \
$(SRC)/$(STRINGS)/ft_strrchr.c \
$(SRC)/$(STDLIB)/$(STDLIB_MALLOC)/ft_calloc.c  \
$(SRC)/$(STRINGS)/ft_isdigit.c \
$(SRC)/$(MEMORY)/ft_memmove.c \
$(SRC)/$(STRINGS)/ft_strlcpy.c \
$(SRC)/$(STRINGS)/ft_tolower.c \
$(SRC)/$(STRINGS)/ft_isprint.c \
$(SRC)/$(MEMORY)/ft_memset.c  \
$(SRC)/$(STRINGS)/ft_strlen.c  \
$(SRC)/$(STRINGS)/ft_toupper.c \
$(SRC)/$(MEMORY)/ft_memchr.c  \
$(SRC)/$(STRINGS)/ft_strncmp.c \
$(SRC)/$(STRINGS)/ft_strcmp.c \
$(SRC)/$(STRINGS)/ft_strjoin.c \
$(SRC)/$(STRINGS)/ft_substr.c  \
$(SRC)/$(STRINGS)/ft_strtrim.c \
$(SRC)/$(STRINGS)/ft_split.c   \
$(SRC)/$(STDLIB)/ft_itoa.c    \
$(SRC)/$(STRINGS)/ft_isalnum.c \
$(SRC)/$(STRINGS)/ft_strmapi.c \
$(SRC)/$(STRINGS)/ft_striteri.c\
$(SRC)/$(IO)/ft_putchar_fd.c \
$(SRC)/$(IO)/ft_putstr_fd.c  \
$(SRC)/$(IO)/ft_putendl_fd.c \
$(SRC)/$(IO)/ft_putnbr_fd.c \
$(SRC)/$(IO)/$(GNL)/gnl.c \
$(SRC)/$(IO)/$(GNL)/gnl_utils.c \
$(SRC)/$(DS)/$(DS_LINKEDLIST)/ft_lstnew.c \
$(SRC)/$(DS)/$(DS_LINKEDLIST)/ft_lstadd_front.c \
$(SRC)/$(DS)/$(DS_LINKEDLIST)/ft_lstsize.c \
$(SRC)/$(DS)/$(DS_LINKEDLIST)/ft_lstclear.c \
$(SRC)/$(DS)/$(DS_LINKEDLIST)/ft_lstadd_back.c \
$(SRC)/$(DS)/$(DS_LINKEDLIST)/ft_lstdelone.c \
$(SRC)/$(DS)/$(DS_LINKEDLIST)/ft_lstiter.c \
$(SRC)/$(DS)/$(DS_LINKEDLIST)/ft_lstlast.c \
$(SRC)/$(DS)/$(DS_LINKEDLIST)/ft_lstmap.c \
$(SRC)/$(DS)/$(DS_HASHTABLE)/get_pointer.c \
$(SRC)/$(DS)/$(DS_HASHTABLE)/init_hash_table.c \
$(SRC)/$(DS)/$(DS_HASHTABLE)/delete_entry.c \
$(SRC)/$(DS)/$(DS_HASHTABLE)/set_new_value.c \
$(SRC)/$(DS)/$(DS_HASHTABLE)/free_hash_table.c \
$(SRC)/$(CRYPTO)/joaat_hash.c \
$(SRC)/$(IO)/$(FT_PRINTF)/ft_parsing_format.c \
$(SRC)/$(IO)/$(FT_PRINTF)/ft_printf.c \
$(SRC)/$(IO)/$(FT_PRINTF)/ft_printf_utils.c \
$(SRC)/$(IO)/$(FT_PRINTF)/handle_char.c \
$(SRC)/$(IO)/$(FT_PRINTF)/handle_hexas_utils.c \
$(SRC)/$(IO)/$(FT_PRINTF)/handle_int.c \
$(SRC)/$(IO)/$(FT_PRINTF)/handle_lower_hexas.c \
$(SRC)/$(IO)/$(FT_PRINTF)/handle_percent.c \
$(SRC)/$(IO)/$(FT_PRINTF)/handle_pointer.c \
$(SRC)/$(IO)/$(FT_PRINTF)/handle_pointer_utils.c \
$(SRC)/$(IO)/$(FT_PRINTF)/handle_string.c \
$(SRC)/$(IO)/$(FT_PRINTF)/handle_unsigned_int.c \
$(SRC)/$(IO)/$(FT_PRINTF)/handle_upper_hexas.c \
$(SRC)/$(IO)/$(FT_PRINTF)/putchar_fd.c \
$(SRC)/$(IO)/$(FT_PRINTF)/putstr_fd.c \
$(SRC)/$(STDLIB)/$(STDLIB_MALLOC)/$(STACK)/init_stack_allocator.c \
$(SRC)/$(STDLIB)/$(STDLIB_MALLOC)/$(STACK)/stack_alloc.c \
$(SRC)/$(STDLIB)/$(STDLIB_MALLOC)/$(STACK)/stack_dealloc.c \
$(SRC)/$(STRING)/$(STR_BUILDER)/init_sb.c \
$(SRC)/$(STRING)/$(STR_BUILDER)/append_sb.c \
$(SRC)/$(STRING)/$(STR_BUILDER)/append_ch_sb.c \
$(SRC)/$(STRING)/$(STR_BUILDER)/clear_sb.c \
$(SRC)/$(STRING)/$(STR_BUILDER)/free_sb.c \


# -------------------- OBJECTS -------------------- #
OBJECTS 			:= $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SOURCES))

# ---------------- COMPILATION RULES -------------- #
all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

$(OBJ)/%.o: $(SRC)/%.c
	@$(MKDIR) $(dir $@)
	$(CC) $(W_FLAGS) $(C_FLAGS) -I$(HDR) -c $< -o $@
# ------------------ CLEAN UP RULES --------------- #
clean:
	$(RMRF) $(OBJ)

fclean: clean
	$(RMF) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
