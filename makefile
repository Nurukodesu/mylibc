ARCH := $(shell uname -m)

SRC = src
INC := header
BUILD := build
TEST := test
COMMON_SRC := src/string src/unistd src/errno src/stdio src/debug src/malloc src/ctype src/stdlib
ARCH_INC := $(INC)/arch/$(ARCH)/
ARCH_SRC := $(SRC)/arch/$(ARCH)/

LIB_NAME := $(BUILD)/libc.a

CC := clang
AS := nasm
AR := ar

CSRCS  := $(shell find $(COMMON_SRC) $(ARCH_SRC) -maxdepth 2 -name "*.c")
ASSRCS  := $(shell find $(COMMON_SRC) $(ARCH_SRC) -maxdepth 2 -name "*.asm")
OBJS := $(patsubst $(SRC)/%.c, $(BUILD)/%.o, $(CSRCS)) $(patsubst $(SRC)/%.asm, $(BUILD)/%.o, $(ASSRCS))
DEPS := $(OBJS:.o=.d)

CFLAGS := -I$(ARCH_INC)
ASFLAGS := -I$(ARCH_INC) -I$(INC) -felf64 -F dwarf
LDFLAGS := -nostdlib  --static
ARFLAGS := rcs

$(LIB_NAME): $(OBJS)
	@mkdir -p $(dir $@)
	$(AR) rcs $@ $^

$(BUILD)/main: $(TEST)/main.c $(LIB_NAME)
	@mkdir -p $(dir $@)
	$(CC) @compile_flags.txt $(CFLAGS) $(LDFLAGS) $< $(LIB_NAME) -o $@	

$(BUILD)/%.o: $(SRC)/%.asm
	@mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) $< -o $@ -MD $(@:.o=.d)

$(BUILD)/%.o: $(SRC)/%.c
	@mkdir -p $(dir $@)
	$(CC) @compile_flags.txt -c $(CFLAGS) $< -o $@

-include $(DEPS)

lib: $(LIB_NAME)

clean:
	@rm -r ${BUILD}/*

debug: ${BUILD}/main
	${BUILD}/main

all: lib debug

.PHONY: clean run lib all