all:
	gcc -o mapcol mapcol.c read_stdin.c read_file.c sorts.c toolkit.c coloring.c

clean:
	rm mapcol


