g++ -c User.cpp
g++ -c Student.cpp
g++ -c Teacher.cpp
g++ -c UserAuthentication.cpp
g++ -c VirtualClassroom.cpp
g++ -c main.cpp

g++ -o main main.o VirtualClassroom.o UserAuthentication.o User.o Student.o Teacher.o

./main
