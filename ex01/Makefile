.PHONY : all re fclean clean

NAME			= Borderlands_01

MAKEFLAGS		+= -j $$(nproc)

CC				= c++
CFLAGS			= -std=c++98 -Wall -Wextra -Werror
DEPS			= -MMD -MP

OBJ_DIR			= .build/
INCLUDE_DIR		= inc/
INCLUDES 		= -I $(INCLUDE_DIR)

SRCS			=	src/main.cpp	\
					src/ClapTrap.cpp \
					src/ScavTrap.cpp

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
	rm -rf $(NAME) compile_commands.json .cache

compile_commands.json: fclean
	@if command -v bear >/dev/null 2>&1; then \
		bear -- $(MAKE) --no-print-directory; \
	else \
		echo '[' > $@; \
		$(foreach src,$(SRCS), echo '  {"directory": "'$$(pwd)'", "command": "$(CC) $(CFLAGS) $(INCLUDES) -c $(src)", "file": "$(src)"},' >> $@;) \
		sed -i '$$ s/,$$//' $@; \
		echo ']' >> $@; \
		$(MAKE) --no-print-directory; \
	fi
