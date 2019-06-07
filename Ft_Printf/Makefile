NAME := ft_printf
DNAM := d_$(NAME)
ANAM := a_$(NAME)

CC ?= clang
CFLAGS := -Wall -Wextra -Werror
DFLAGS := -Wall -Wextra -g
AFLAGS := $(DFLAGS) -fsanitize=address

LIBDIR := libft
INCDIR := include
OBJDIR := .obj
DBGDIR := .dbg
ASNDIR := .asn
SRCDIR := src

INCFLAGS := -I$(INCDIR) -I$(LIBDIR)/$(INCDIR)
LIBFLAGS := -L$(LIBDIR) -lft
DEBGLIBS := $(LIBDIR)/d_libft.a
ASANLIBS := $(LIBDIR)/a_libft.a
FRAMWRKS :=


SRC :=	

OBJ := $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
DBG := $(addprefix $(DBGDIR)/, $(SRC:.c=.o))
ASN := $(addprefix $(ASNDIR)/, $(SRC:.c=.o))

NRM := $(shell which norminette)

#make -C libft all
#make -C libft clean
#make -C libft dclean
#make -sC libft debug
#make -C libft dclean
#make -sC libft asan
#make -sC libft fclean
NORME := $(addsuffix *.h,$(INCDIR)/) $(addsuffix *.c,$(SRCDIR)/)

.PHONY: all
all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ)
	@$(CC) $(INCFLAGS) -o $(NAME) $(OBJ)
	@echo "Compiled $(NAME)"

$(addprefix $(OBJDIR)/, %.o): $(addprefix $(SRCDIR)/, %.c)
	$(CC) $(INCFLAGS) $(CFLAGS) -c -o $@ $<

$(OBJDIR):
	mkdir -p $(OBJDIR)

.PHONY: clean
clean:
	rm -Rf $(OBJDIR)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all

.PHONY: f
f: asan

.PHONY: d
d: aclean

.PHONY: asan
asan: $(ASNDIR) $(ASN)
	$(CC) $(AFLAGS) $(INCFLAGS) -o $(ANAM) $(ASN)

$(addprefix $(ASNDIR)/, %.o): $(addprefix $(SRCDIR)/, %.c)
	$(CC) $(AFLAGS) $(INCFLAGS) -c -o $@ $<

$(ASNDIR):
	mkdir -p $(ASNDIR)

.PHONY: aclean
aclean:
	rm -rf $(ANAM) $(ANAM).dSYM

.PHONY: j
j: debug

.PHONY: k
k: dclean

.PHONY: debug
debug: $(DBGDIR) $(DBG)
	$(CC) $(DFLAGS) $(INCFLAGS) -o $(DNAM) $(addprefix $(SRCDIR)/, $(SRC))

$(addprefix $(DBGDIR)/, %.o): $(addprefix $(SRCDIR)/, %.c)
	$(CC) $(DFLAGS) $(INCFLAGS) -c -o $@ $<

$(DBGDIR):
	mkdir -p $(DBGDIR)

.PHONY: dclean
dclean:
	rm -rf $(DNAM) $(DNAM).dSYM

.PHONY: tags
tags:
	ctags $(addsuffix *.h,$(INCDIR)/) $(addsuffix *.c,$(SRCDIR)/)

.PHONY: norme
norme:
	$(NRM) $(NORME)

.PHONY: codesize
codesize:
	@printf "Lines of code: "
	@cat $(NORME) | grep -Ev '(^\/\*|^\*\*|^\*\/$$|^$$|\*\/)' | wc -l | cut -d' ' -f7
