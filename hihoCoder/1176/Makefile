cxxflags = -std=c++11 \
		   -g

target=a.out

src = $(shell find ./ -name "*.cpp")
$(target): $(src)
	g++ $(cxxflags) $^ -o $@

make clean:
	rm -rf $(target)
