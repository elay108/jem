#
# Compiler Flags
#
CC	= gcc
CFLAGS 	= -Wall -Werror -Wextra

#
# Project Files
#
SRCS	= cat.c
OBJS	= $(SRCS:.c=.o)

#
# Debug Build Settings
#
DBGDIR	= ../debug
DBGOBJS	= $(addprefix $(DBGDIR)/, $(OBJS))
DBGCFLAGS = -g -O0 -DDEBUG

#
# Release Build Settings
#
RELDIR	= ../release
RELOBJS	= $(addprefix $(RELDIR)/, $(OBJS))
RELCFLAGS = -O3 -DNDEBUG

.PHONY: all clean debug prep release make

# Default build
all: prep release

#
# Debug rules
#
debug: $(DBGOBJS)

$(DBGDIR)/%.o: %.c
	$(CC) -c $(CFLAGS) $(DBGCFLAGS) -o $@ $<

#
# Release rules
#
release: $(RELOBJS)

$(RELDIR)/%.o: %.c
	$(CC) -c $(CFLAGS) $(RELCFLAGS) -o $@ $<

#
# Other rules
#
prep:
	@mkdir -p $(DBGDIR) $(RELDIR)

remake: clean all

clean:
	rm -f $(RELEXE) $(RELOBJS) $(DBGEXE) $(DBGOBJS)
