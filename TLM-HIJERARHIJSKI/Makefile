CC = "g++"
PROJECT =  main	 
SRC = hard.cpp dma.cpp main.cpp vp.cpp

LIBS = `pkg-config opencv4 --cflags --libs`
																		
$(PROJECT) : $(SRC)
	$(CC) -g $(SRC) -lsystemc -fno-omit-frame-pointer -o $(PROJECT) $(LIBS)

profiling: 
	valgrind --tool=callgrind ./$(PROJECT)
clean:
	rm -f *.o all $(PROJECT) callgrind.*

