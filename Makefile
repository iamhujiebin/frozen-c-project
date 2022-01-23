# MakeFile
# target : require(optional)
# 	command

out: main.c my.c
	gcc main.c my.c -o out

clean:
	rm -rf out

run:
	./out
