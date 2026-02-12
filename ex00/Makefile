# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/06 15:21:03 by vpoka             #+#    #+#              #
#    Updated: 2026/02/10 20:40:38 by vpoka            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-----VARIABLES-----#

NAME := convert

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98
DPFLAGS := -MP -MD
DBFLAGS := -g -DDEBUG

INCLUDE := -Iinclude -Iinclude/helpers
COMP := $(CXX) $(CXXFLAGS) $(INCLUDE)

S := src
SRCS :=	$(addprefix $(S)/, \
		ScalarConverter.cpp \
		main.cpp)

B := build
OBJS := $(SRCS:$(S)/%.cpp=$(B)/%.o)
DEPS := $(OBJS:%.o=%.d)

#-----COLORS-----#

GREEN = \033[1;32m
RED = \033[1;31m
BLUE = \033[1;34m
YELLOW = \033[1;33m
CYAN = \033[1;36m
RESET = \033[0m

#-----PRINTING TOOLS-----#

# Usage: $(call print_target, target_name)
define print_target
	@printf "🛠️  $(BLUE)Compiling target: $(CYAN)$(1)$(RESET)\n"
endef

# Usage: $(call print_compile, file_name)
define print_compile
	@printf "🔧 $(YELLOW)Compiling: $(RESET)$(1)\n"
endef

# Usage: $(call print_clean, message)
define print_clean
	@printf "🧹 $(RED)$(1)$(RESET)\n"
endef

# Usage: $(call print_success, message)
define print_success
	@printf "✨ $(GREEN)$(1)$(RESET)\n"
endef

# Usage: $(call print_debug, message)
define print_debug
	@printf "🐞 $(CYAN)$(1)$(RESET)\n"
endef

#-----RULES-----#

all: $(NAME)

$(NAME): $(OBJS)
	$(call print_target, $(NAME))
	@$(COMP) $(OBJS) -o $(NAME)
	$(call print_success, $(NAME) ready!)

$(B)/%.o: $(S)/%.cpp
	@mkdir -p $(@D)
	$(call print_compile, $<)
	@$(COMP) $(DPFLAGS) -c $< -o $@

clean:
	@rm -rf $(B)
	$(call print_clean, Removed build directory)

fclean: clean
	@rm -f $(NAME)
	$(call print_clean, Removed executable)

re: fclean all

debug: fclean
	$(call print_debug, Compiling with debug flags...)
	@make --no-print-directory all CXXFLAGS="$(CXXFLAGS) $(DBFLAGS)"

run: re
	@printf "🚀 $(BLUE)Running $(NAME)...$(RESET)\n"
	@printf "$(CYAN)--------------------------------$(RESET)\n"
	@printf "\n$(GREEN)---------- valid input ----------$(RESET)\n"
	@./$(NAME) a 4 -4 +4 42 4.2 -4.2 +4.2 4.2f 42f +4.2f -4.2f nan nanf +inff -inf +inf 000 00.00 00.00f  123. 123.f
	@printf "\n$(GREEN)---------- invalid input ----------$(RESET)\n"
	@./$(NAME) -+4 --4 ++4 --inf ++inff asbcsdasd 1234ff '    ' '  123' '123   ' 124..532 123.34. 123.45.67 ''

.PHONY: all clean fclean re run debug

-include $(DEPS)
