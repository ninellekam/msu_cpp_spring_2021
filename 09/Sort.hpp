#ifndef		SORT_HPP
#define		SORT_HPP

#include	<algorithm>
#include	<exception>
#include	<fstream>
#include	<functional>
#include	<iostream>
#include	<mutex>
#include	<thread>
#include	<queue>
#include	<string>
#include	<vector>

#pragma		once

void		Sort_tmp(std::mutex& mut, std::ifstream& input, std::ofstream& tmp, size_t buf_size);
void		Sort(const std::string& input_path, const std::string& output_path);

#endif