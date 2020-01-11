TAR=run
SRC=*.c
INCLUDE_DIR=../include/
CFLAGS=-g -I $(INCLUDE_DIR) 
CLEAN=$(TAR) *.o

$(TAR): *.o
	@gcc *.o -o $(TAR)
	@echo "Build successfully!"

*.o: $(SRC)
	@gcc -c $(SRC) $(CFLAGS)

.PHONY: clean
clean:
	@rm -rf $(CLEAN)
