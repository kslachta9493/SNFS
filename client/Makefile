COMPILER = gcc
FILESYSTEM_FILES = clientSNFS.c

build: $(FILESYSTEM_FILES)
		$(COMPILER) $(FILESYSTEM_FILES) -o client `pkg-config fuse --cflags --libs`

clean:
	rm client
