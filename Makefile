CC := clang
CFLAGS := $(shell cat compile_flags.txt)
SRC := src
CODE := $(SRC)/dev.c
BIN := build
TARGET := $(BIN)/dev.out
LD_LIBRARY_PATH := $(LD_LIBRARY_PATH):libpcap

.PHONY: all
all: run

.PHONY: b build
.SILENT: build
b: build
build:
	$(MAKE) -B --no-print-directory $(TARGET)

$(TARGET): $(CODE)
	@ mkdir -p $(BIN)
	$(CC) $(CFLAGS) $< -o $@

.PHONY: r run
r: run
run: $(TARGET)
	LD_LIBRARY_PATH=$(LD_LIBRARY_PATH) ./$(TARGET)

.PHONY: c clean
c: clean
clean:
	rm -rfv $(BIN)
