NAME := ex02
CXX := c++
CXXFLAGS := -Wall -Werror -Wextra -std=c++98 -pedantic
FILE := main.cpp \
		Bureaucrat.cpp \
		AForm.cpp \
		ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp \
		PresidentialPardonForm.cpp
OBJDIR := obj

OBJ := $(addprefix $(OBJDIR)/, $(FILE:.cpp=.o))

FORBIDDEN_KEYWORDS := "printf|alloc|free|friend|using namespace"
CHECK_FILES := *.cpp *.hpp

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -I. -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf *_shrubbery
	rm -rf $(NAME)

re: fclean all

run:re
	clear
	valgrind --leak-check=full --show-leak-kinds=all -q ./$(NAME)

check:
	@echo "Checking for forbidden keywords..."
	@if grep -E $(FORBIDDEN_KEYWORDS) $(CHECK_FILES) | grep -v "Makefile"; then \
		echo "❌ \033[31mForbidden keywords found!\033[0m"; \
		exit 1; \
	else \
		echo "✅ \033[32mNo forbidden keywords found.\033[0m"; \
	fi

.PHONY: re clean fclean all run check