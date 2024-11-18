export SHARED_LIB_NAME = libcommon.so
export STATIC_LIB_NAME = libcommon.a

SRC := $(wildcard *.c)
OBJECT := $(patsubst %.c, %.o, $(SRC)) 

all: $(SHARED_LIB_NAME) $(STATIC_LIB_NAME)

$(SHARED_LIB_NAME): $(SRC)
	$(CC) -fPIC -shared $^ -o $@

$(STATIC_LIB_NAME): $(OBJECT)
	$(AR) rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf *.a *.so *.o

.PHONY: 
	clean all

