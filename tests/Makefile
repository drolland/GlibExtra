## -*- Makefile -*-
##
## User: drolland
## Time: 7 déc. 2016 17:59:15
## Makefile created by Oracle Developer Studio.
##
## This file is generated automatically.
##


#### Compiler and tool definitions shared by all build targets #####
CC = gcc
CFLAGS=`pkg-config --cflags --libs glib-2.0` 

SRC= $(wildcard *.c)
TEST= $(SRC:.c=.test)
	
all:	$(TEST)
	@gtester *.test -o report.xml

%.test : %.c libglibextra.a
	@$(CC) $^ -o $@ $(CFLAGS)
	
clean:
	@rm -rf test*.test
	

.PHONY: clean 



	


