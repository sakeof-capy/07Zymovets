#include "Screen.h"

//***************************************************
//�������������� ���� ��� ������ � ��������� �������.
//Developed by Ruslan Zymovets (IPZ, group 1)
//on March 22
//Version 1.0
//***************************************************

const size_t Screen::maxHeight = 30;
const size_t Screen::maxWidth = 90;
const char Screen::_filler = '.';
const char Screen::thick_delim = '#';
const char Screen::thin_delim = '-';

Screen::Screen(const size_t h, const size_t w, const char* c)
	: _height(h > maxHeight ? maxHeight : h), 
	  _width (w > maxWidth  ? maxWidth  : w), 
	  _wContent(new char[h * w + 1]), 
	  _cursor(0)
{
	int i = 0;

	if (c)
	{
		for (; c[i] && i < _height * _width; ++i)
		{
			//if (!c[i]) break;
			_wContent[i] = c[i];
		}
	}

	for (; i < _height * _width; ++i)
	{
		_wContent[i] = _filler;
	}

	_wContent[_width * _height] = '\0';

	return;
}

Screen::~Screen()
{
	delete[] _wContent;
	_wContent = nullptr;
	return;
}