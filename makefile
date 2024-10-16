build:
	rm -f ./a.out
	g++ -std=c++17 -g -Wall main.cpp
	git add .
	git commit -m "commited changes"