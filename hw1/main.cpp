#include "test.hpp"
#include "allocator.hpp"

int main(int argc, char **argv) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	if (argc == 2)
		if ((!(strcmp(argv[1],"test")))) {
			std::cout << "\nTests for allocator! :\n";
			test();
			return (0);
		}
	std::string str;
	std::cout << "\nIf you want to run tests enter 'test' or not just enter 'run':  ";
	std::cin >> str;
	if (str == "test") {
		std::cout << "Tests for allocator! :\n";
		test();
	}
	if (str == "run") {
		Allocator alloc;
		std::string s;
		size_t size;
 		while (std::cin >> s) {
 			if (s == "makeAllocator") {
 				std::cin >> size;
 				alloc.makeAllocator(size);
				alloc.check();
 			}
 			if (s == "alloc") {
 				size = 0;
 				std::cin >> size;
 				if (alloc.alloc(size) == NULL)
				std::cout << "------------- ERROR!!! --------------  " << size << "\n";
				alloc.check();
 			}
 			if (s == "reset") {
 				alloc.reset();
 				}
 		}
	}
	return (0);
}