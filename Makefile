caoquanbei: main.cpp myframe.cpp myframe.h
	g++ -std=c++0x `wx-config --libs` `wx-config --cxxflags` main.cpp myframe.cpp -o $@
