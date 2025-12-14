# Mini-projekt: testowanie kodu w C (GCC/Linux)
# Targety:
#   make test      -> uruchom testy jednostkowe
#   make asan      -> testy z AddressSanitizer (wykrywanie błędów pamięci)
#   make valgrind  -> testy pod Valgrind Memcheck (wycieki/invalid read/write)
#   make coverage  -> raport pokrycia (gcov/lcov -> HTML)
#   make clean     -> sprzątanie artefaktów
#
# Wymagania:
#   - gcc
#   - valgrind (dla make valgrind)
#   - lcov + genhtml (dla make coverage)
#
# Uwaga: Projekt jest celowo prosty i "C99-friendly". Coverage używa gcc --coverage.

SHELL := /bin/bash

CC      := gcc
CSTD    := -std=c11
WARN    := -Wall -Wextra -Wpedantic -Wshadow -Wconversion -Wstrict-prototypes
OPTDBG  := -O0 -g3

INCLUDES := -Iinclude

BUILD_DIR := build
REPORT_DIR := reports
COV_DIR := $(REPORT_DIR)/coverage

SRC_DIR := src
TEST_DIR := test

LIB_SRCS := $(SRC_DIR)/str_utils.c $(SRC_DIR)/math_utils.c
LIB_OBJS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(LIB_SRCS))

TEST_SRCS := $(TEST_DIR)/test_main.c $(TEST_DIR)/test_str_utils.c $(TEST_DIR)/test_math_utils.c
TEST_OBJS := $(patsubst $(TEST_DIR)/%.c,$(BUILD_DIR)/test_%.o,$(TEST_SRCS))

TEST_BIN := $(BUILD_DIR)/test_runner

# Common flags
CFLAGS  := $(CSTD) $(WARN) $(OPTDBG) $(INCLUDES)
LDFLAGS :=

# ASan flags
ASAN_FLAGS := -fsanitize=address -fno-omit-frame-pointer

# Coverage flags
COV_CFLAGS := --coverage
COV_LDFLAGS := --coverage

.PHONY: all test asan valgrind coverage clean help

all: test

help:
	@sed -n '1,80p' Makefile

# ---------------------------
# Build rules
# ---------------------------
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/test_%.o: $(TEST_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_BIN): $(LIB_OBJS) $(TEST_OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

# ---------------------------
# Targets
# ---------------------------
test: $(TEST_BIN)
	@echo "== Running unit tests =="
	@$(TEST_BIN)

asan:
	@echo "== Building + running with AddressSanitizer =="
	@$(MAKE) clean >/dev/null
	@$(MAKE) CFLAGS="$(CFLAGS) $(ASAN_FLAGS)" LDFLAGS="$(LDFLAGS) $(ASAN_FLAGS)" test

valgrind: $(TEST_BIN)
	@command -v valgrind >/dev/null || (echo "Valgrind not installed." && exit 1)
	@echo "== Running under Valgrind Memcheck =="
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=42 $(TEST_BIN)

coverage:
	@command -v lcov >/dev/null || (echo "lcov not installed." && exit 1)
	@command -v genhtml >/dev/null || (echo "genhtml not installed." && exit 1)
	@echo "== Building + running with coverage flags =="
	@$(MAKE) clean >/dev/null
	@$(MAKE) CFLAGS="$(CFLAGS) $(COV_CFLAGS)" LDFLAGS="$(LDFLAGS) $(COV_LDFLAGS)" test
	@mkdir -p $(COV_DIR)
	@echo "== Capturing coverage =="
	@lcov --capture --directory . --output-file $(COV_DIR)/coverage.info >/dev/null
	@echo "== Filtering system paths =="
	@lcov --remove $(COV_DIR)/coverage.info '/usr/*' --output-file $(COV_DIR)/coverage.info >/dev/null
	@echo "== Generating HTML report =="
	@genhtml $(COV_DIR)/coverage.info --output-directory $(COV_DIR) >/dev/null
	@echo "Coverage report: $(COV_DIR)/index.html"

clean:
	@rm -rf $(BUILD_DIR) $(REPORT_DIR)
	@mkdir -p $(BUILD_DIR) $(REPORT_DIR)
	@echo "Cleaned."
