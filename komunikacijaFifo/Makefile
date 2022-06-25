CC = "g++"
PROJECT =  main2	 
SRC = module.cpp target.cpp main2.cpp

LIBS = `pkg-config opencv4 --cflags --libs`
																		
$(PROJECT) : $(SRC)
	$(CC) -g $(SRC) -lsystemc -fno-omit-frame-pointer -o $(PROJECT) $(LIBS)

profiling: 
	valgrind --tool=callgrind ./$(PROJECT)
clean:
	rm -f *.o all $(PROJECT) callgrind.*

