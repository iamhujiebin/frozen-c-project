# 生成cgo的静态文件.a
#target:number.o
#	ar rcs libnumber.a number.o
#number.o:number.c
#	gcc -c -o number.o number.c
#
# 生成动态cgo库.so
target: number.c
	gcc -shared -o libnumber.so number.c
clean:
	rm -rf number.o
