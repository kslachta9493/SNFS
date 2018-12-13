COMPILER = gcc
FILESYSTEM_FILES = serverSNFS.c

build: $(FILESYSTEM_FILES)
		$(COMPILER) $(FILESYSTEM_FILES) -o server `pkg-config fuse --cflags --libs`

clean:
	rm client
