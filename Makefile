C = gcc # C compiler
CFLAGS = -I$(lib_dir) -Os
AS = nasm
ASFLAGS= -f elf64
AR = ar
AR_FLAGS = cvq
RM = rm

LIB_BIN_DIR = bin
TEST_BIN_DIR = test_bin

lib_name = math
lib_file=lib$(lib_name)
lib_dir = lib
lib_source = mads.c
asm_source = mads_asm.asm
lib_objs = $(lib_source:.c=.o)
asm_lib_objs = $(asm_source:.asm=.o)
test_dir = tests
test_source = mads_test.c
test_objs = $(test_source:.c=)

default: lib_static

lib_static: $(lib_objs) $(asm_lib_objs)
	$(AR) $(AR_FLAGS) $(LIB_BIN_DIR)/$(lib_file).a $(LIB_BIN_DIR)/$(lib_objs) $(LIB_BIN_DIR)/$(asm_lib_objs)

tests: lib_static $(test_objs)


$(lib_objs): %.o: $(lib_dir)/%.c
	mkdir -p $(LIB_BIN_DIR)
	$(CC) -c $(CFLAGS) $< -o $(LIB_BIN_DIR)/$@

$(asm_lib_objs): %.o: $(lib_dir)/%.asm
	mkdir -p $(LIB_BIN_DIR)
	$(AS) $(ASFLAGS) $< -o $(LIB_BIN_DIR)/$@

$(test_objs): %.o: $(test_dir)/%.c
	mkdir -p $(TEST_BIN_DIR)
	$(CC) $(CFLAGS)  $(test_dir)/$@.c -L$(LIB_BIN_DIR) -l$(lib_name) -o $(TEST_BIN_DIR)/$@

.PHONY: lib_static tests clean

clean:
	$(RM) -rf $(LIB_BIN_DIR)
	$(RM) -rf $(TEST_BIN_DIR)
