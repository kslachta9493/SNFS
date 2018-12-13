COMPILER = gcc
FILESYSTEM_FILES = serverSNFS.c

build: $(FILESYSTEM_FILES)
		$(COMPILER) $(FILESYSTEM_FILES) -o server -g `pkg-config fuse --cflags --libs`

clean:
	rm client
