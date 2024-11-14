# Компиляторы
CC=g++
CC_FLAGS=-Wall

# Цели
TARGET=main

# Директории
SRC_DIR=src
BIN_DIR=bin

# Исходные коды
SOURCES=$(SRC_DIR)/*.cpp

DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = cp -f -R
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
TAR           = tar -cf
COMPRESS      = gzip -9f
LIBS_DIRS     = -I./include/
LIBS 		  = $(LIBS_DIRS) -lcurses
# LIBS = -lncurses
SED           = sed
STRIP         = strip

.PHONY: clean build
all: clean build run

build: $(SOURCE)
	$(CC) $(CC_FLAGS) $(SOURCES) -o $(BIN_DIR)/$(TARGET) $(LIBS) 

run:
	./$(BIN_DIR)/$(TARGET)

clean:
	$(DEL_FILE) bin/*