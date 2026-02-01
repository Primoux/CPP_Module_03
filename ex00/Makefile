.PHONY : all re fclean clean

NAME			= Borderlands_00

MAKEFLAGS		+= -j $$(nproc)

CC				= c++
CFLAGS			= -std=c++98 -Wall -Wextra -Werror
DEPS			= -MMD -MP

OBJ_DIR			= .build/
INCLUDE_DIR		= inc/
INCLUDES 		= -I $(INCLUDE_DIR)

SRCS			=	src/main.cpp	\
					src/ClapTrap.cpp

OBJS			= $(patsubst %.cpp,$(OBJ_DIR)%.o,$(SRCS))
DEPENDENCIES	= $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o: %.cpp
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) $(DEPS) -c $< -o $@

-include $(DEPENDENCIES)

re: fclean
	$(MAKE) --no-print-directory

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME) .cache
