picture:picture.c
	gcc picture.c -o picture

run:picture
	./picture

clean:
	rm picture
	rm image.ppm
