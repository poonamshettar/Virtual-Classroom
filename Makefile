all : main

main : main.o VirtualClassroom.o UserAuthentication.o User.o Student.o Teacher.o Course.o
	echo "Linking files"
	g++ *.o -o main
	chmod +x main
	
User.o: User.cpp
	echo "Compiling User file"
	gcc -c User.cpp
	
Course.o: Course.cpp
	echo "Compiling Course file"
	gcc -c Course.cpp

Student.o: Student.cpp
	echo "Compiling Student file"
	gcc -c Student.cpp
	
Teacher.o: Teacher.cpp
	echo "Compiling Teacher file"
	gcc -c Teacher.cpp

UserAuthentication.o: UserAuthentication.cpp
	echo "Compiling UserAuthentication file"
	gcc -c UserAuthentication.cpp

VirtualClassroom.o: VirtualClassroom.cpp
	echo "Compiling main file"
	gcc -c VirtualClassroom.cpp

main.o: main.cpp
	echo "Compiling main file"
	gcc -c main.cpp
clean:
	echo "removing all object files"
	rm  *.o main
