#include "allocator.hpp"

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::string s;
	size_t size;
	std::cin >> s;
	Allocator alloc;
	while (std::cin >> s) {
		if (s == "makeAllocator") {
			std::cin >> size;
			alloc.makeAllocator(size);
		}
		if (s == "alloc") {
			std::cin >> size;
			std::cout << "alloc result " << alloc.alloc(size) << "\n";
		}
		if (s == "reset") {
			alloc.reset();
		}
	}
	std::cout << "Exit!";
	return (0);
}