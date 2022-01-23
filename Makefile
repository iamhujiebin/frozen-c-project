# MakeFile
# target : require(optional)
# 	command

out: main.c my.c encrypt.c scale.c
	gcc main.c my.c encrypt.c scale.c -o out

clean:
	rm -rf out encode.txt decode.txt

run:
	./out
