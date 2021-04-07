#ifndef		TEST_HPP
#define		TEST_HPP

#include	"TokenParser.hpp"
#include	<cassert>
#include	<vector>
#include	<iostream>
#include	<cassert>

template <typename T>
void assertVector(const std::vector<T> &generated, const std::vector<T> &expected);
void test_nullptr_callback();
void test_one_symbol();
void test_empty_string();
void test_overflow();
void test_with_no_start();
void test_with_only_digit_tokens();
void test_with_only_string_tokens();
void test_string_tabs();
void test_all();
void test_without_callback();
void test_two_same_callbacks();

#endif