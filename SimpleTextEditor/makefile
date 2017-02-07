#Jacob Pawlak
#November 29th, 2016
#Program 3 Extra
#CS216
#File: makefile

#the list of objects to be made
OBJECTS = mainExtra.o Term.o Autocomplete.o
HEADERS = Term.h Autocomplete.h
#above are all the header files for this project 

Lab12: $(OBJECTS)
	g++ -std=c++11 -o CS216PA3Extra $^
#compile the objects (with std=c++11) into the executable CS216PA3Extra

%.o: %.cpp $(HEADERS)
	g++ -c $< -o $@

#to remove all the object files and the executable
clean:
	rm -i *.o
	rm CS216PA3Extra
