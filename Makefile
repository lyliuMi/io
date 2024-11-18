app = main
export CFLAGS = -g -Wall -Wextra
LIB_DIR = common
LDFLAGS = -L $(LIB_DIR) -Wl,-R $(LIB_DIR) -Wl,-Bstatic -l$(LIB_DIR) -Wl,-Bdynamic
# LDFLAGS = -L $(LIB_DIR) -Wl,-R $(LIB_DIR) -l$(LIB_DIR)

SUB_DIR = common

SRC := $(wildcard *.c)
OBJECT := $(patsubst %.c, %.o, $(SRC)) 

default: $(SUB_DIR) target 

$(SUB_DIR):
#$(MAKE) -C $(SUB_DIR)
	@for dir in $(SUB_DIR); do \
		$(MAKE) -C $$dir; \
	done 

target: $(app)

$(app): $(OBJECT)
	$(CC) $^ -o $@ $(LDFLAGS) 

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

.PHONY: common target clean
clean:
	@echo "clean all"
	@for dir in $(SUB_DIR); do \
		$(MAKE) -C $$dir clean; \
	done 
	rm -rf *.o $(app) 2024*