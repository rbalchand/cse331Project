CC := gcc
SRCD := src
INCD := include

ALL_SRCF := $(shell find $(SRCD) -type f -name *.c)
ALL_OBJF := $(patsubst $(SRCD)/%,$(BLDD)/%,$(ALL_SRCF:.c=.o))


INC := -I $(INCD)

CFLAGS := -Wall -Werror -Wno-unused-variable -Wno-unused-function
COLORF := -DCOLOR
DFLAGS := -g -DDEBUG
PRINT_STAMENTS := -DERROR -DSUCCESS -DWARN -DINFO

EXEC := parseFolder

.PHOINE: clean all

all: setup $(EXEC)

debug: CFLAGS += $(DFLAGS) $(PRINT_STAMENTS) $(COLORF)
debug: all

setup:
	mkdir -p bin build
$(EXEC): $(ALL_OBJF)
	$(CC) $^ -o parseFolder

$(BLDD)/%.o: $(SRCD)/%.c
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<


clean: rm -f parseFolder

