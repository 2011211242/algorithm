cxxflags = -std=c++11 \
		   -g

src = $(shell find ./ -name "*.cpp")
a.out: $(src)
	g++ $(cxxflags) $^ -o $@

make clean:
	rm -rf solution
