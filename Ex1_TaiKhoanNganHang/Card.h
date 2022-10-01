#pragma once
#include <vector>
#include <iostream>
#include <string>
using namespace std;
class Card
{	// Mỗi thẻ có các thông tin về số thẻ, ngày 
	// phát hành và tài khoản thẻ liên kết đến
	long number; // số thẻ
	string day; // ngày phát hành
public:
	Card();
	~Card();
	Card(long _number, string _day);
};