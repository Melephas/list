LIBRARY = liblist.so

#################################
# === Configuration section === #
#################################

# Source and compilation directories
SOURCE_DIR = src
OBJECT_DIR = obj

# Installation directories
INSTALL_DIR = /usr/lib
HEADER_DIR = /usr/include

# Compilation dependencies
#LIBS = -lpthreads
#LIB_PATHS = -L/usr/local/lib

# Compiler and compiler configurations
CC = clang
COMPILE_FLAGS = -Wall -Werror -fpic -I $(SOURCE_DIR)
LINK_FLAGS = -shared

# Additional programs needed for various steps
INSTALL = install
INSTALL_FLAGS = -vC

########################################
# === End of configuration section === #
########################################

# Target generation
SOURCES = $(wildcard $(SOURCE_DIR)/*.c)
OBJECTS = $(patsubst $(SOURCE_DIR)/%.c, $(OBJECT_DIR)/%.o, $(SOURCES))
HEADERS = $(wildcard $(SOURCE_DIR)/*.h)
INSTALL_HEADERS = $(patsubst $(SOURCE_DIR)/%, $(HEADER_DIR)/%, $(HEADERS))

.PHONY: all
all: $(LIBRARY)

$(LIBRARY): $(OBJECTS) $(OBJECT_DIR)
	$(CC) $(LINK_FLAGS) $(OBJECTS) -o $@

$(OBJECT_DIR)/%.o: $(SOURCE_DIR)/%.c $(OBJECT_DIR)
	$(CC) $(COMPILE_FLAGS) -c $< -o $@

$(OBJECT_DIR):
	mkdir -p $@

.PHONY: clean
clean:
	$(RM) -r $(OBJECT_DIR)
	$(RM) $(LIBRARY)

.PHONY: install
install: $(LIBRARY)
	$(INSTALL) $(INSTALL_FLAGS) $(LIBRARY) $(INSTALL_DIR)
	$(INSTALL) $(INSTALL_FLAGS) -m644 $(HEADERS) $(HEADER_DIR)
	ldconfig

.PHONY: uninstall
uninstall:
	$(RM) $(INSTALL_DIR)/$(LIBRARY)
	$(RM) $(INSTALL_HEADERS)
	ldconfig

