#include "test.hpp"

void TestReverse() {
	size_t FileCount = 8192000;
	std::ofstream OutFile;
	uint64_t t;
	std::ifstream InFile;

	OutFile.open("bin.dat", std::ios::binary);
	assert(OutFile.is_open() == true);

	for (uint64_t i = FileCount; i > 0; i--)
		OutFile.write((char*)&i, sizeof(uint64_t));

	OutFile.close();
	bool catching = false;

	try {
		Sort("bin.dat", "out.dat");

		InFile.open("out.dat", std::ios::binary);

		for (uint64_t i = 1; i <= FileCount; ++i) {
			InFile.read((char*)&t, sizeof(uint64_t));
			assert(t == i);
		}
		InFile.close();
	}
	catch (const std::exception& err) {
		std::cout << err.what();
		catching = true;
	}
	catch (...) {
		catching = true;
	}

	assert(catching == false);
}

void TestSorted() {
	size_t FileCount = 8192000;
	std::ofstream OutFile;
	uint64_t t;
	std::ifstream InFile;

	OutFile.open("bin.dat", std::ios::binary);
	assert(OutFile.is_open() == true);

	for (uint64_t i = 0; i < FileCount; i++)
		OutFile.write((char*)&i, sizeof(uint64_t));

	OutFile.close();
	bool catching = false;

	try {
		Sort("bin.dat", "out.dat");

		InFile.open("out.dat", std::ios::binary);
		for (uint64_t i = 0; i < FileCount; ++i) {
			InFile.read((char*)&t, sizeof(uint64_t));
			assert(t == i);
		}
		InFile.close();
	}
	catch (const std::exception& err) {
		std::cout << err.what();
		catching = true;
	}
	catch (...) {
		catching = true;
	}

	assert(catching == false);

	std::remove("bin.dat");
	std::remove("out.dat");
	std::remove("tmp.bin");
}

int main() {
	TestReverse();
	std::cout << "TestReverse is OK!\n";
	TestSorted();
	std::cout << "TestReverse is OK!\n";
}