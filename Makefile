#
# Compiler Flags
#
CC	= gcc
CFLAGS 	= -Wall -Werror -Wextra

#
# Project Files
#
SRCS	= main.c
OBJS	= $(SRCS:.c=.o)
EXE	= jem

#
# Subsystems
#
SUBSYSTEMS	= cat
SUBSYSTEMSOBJS = $(addsuffix .o, $(SUBSYSTEMS))

#
# Debug Build Settings
#
DBGDIR	= debug
DBGEXE	= $(DBGDIR)/$(EXE)
DBGOBJS	= $(addprefix $(DBGDIR)/, $(OBJS)) $(addprefix $(DBGDIR)/, $(SUBSYSTEMSOBJS))
DBGCFLAGS = -g -O0 -DDEBUG

#
# Release Build Settings
#
RELDIR	= release
RELEXE	= $(RELDIR)/$(EXE)
RELOBJS	= $(addprefix $(RELDIR)/, $(OBJS)) $(addprefix $(RELDIR)/, $(SUBSYSTEMSOBJS))
RELCFLAGS = -O3 -DNDEBUG

.PHONY: all clean debug prep release make

# Default build
all: prep release

#
# Debug rules
#
debug: $(DBGEXE)

$(DBGEXE): $(DBGOBJS)
	$(CC) $(CFLAGS) $(DBGCFLAGS) -o $(DBGEXE) $^

$(DBGDIR)/%.o: %.c
	$(CC) -c $(CFLAGS) $(DBGCFLAGS) -o $@ $<

$(DBGDIR)/$(SUBSYSTEMSOBJS):
	+$(MAKE) -C $(SUBSYSTEMS) debug

#
# Release rules
#
release: $(RELEXE)

$(RELEXE): $(RELOBJS)
	$(CC) $(CFLAGS) $(RELCFLAGS) -o $(RELEXE) $^

$(RELDIR)/%.o: %.c
	$(CC) -c $(CFLAGS) $(RELCFLAGS) -o $@ $<

$(RELDIR)/$(SUBSYSTEMSOBJS):
	+$(MAKE) -C $(SUBSYSTEMS) release

#
# Other rules
#
prep:
	@mkdir -p $(DBGDIR) $(RELDIR)

remake: clean all

clean:
	rm -f $(RELEXE) $(RELOBJS) $(DBGEXE) $(DBGOBJS)
