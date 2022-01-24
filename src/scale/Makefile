# 打包静态库 .a
target:scale.o
	ar rcs libscale.a scale.o
scale.o:scale.c
	gcc -c -o scale.o scale.c
clean:
	rm -rf scale.o