all: compile link

compile:
	g++ -I ../src/include -c ../src/*.cpp ../src/input/*.cpp
link:
	g++ *.o -o ../out/main -L ../src/lib -l sfml-graphics -l sfml-window -l sfml-network -l sfml-audio -l sfml-system

run:
	./main.exe