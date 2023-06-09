﻿#include "SecondaryFunction.h"
#include "decorator.hpp"

/*
Задание 1
В программу рендеринга HTML из лекции (раздел про паттерн
 «Декоратор») добавьте новые классы для декорирования текста.

class Paragraph: ...
auto text_block = new Paragraph(new Text());
text_block->render("Hello world");
>>> <p>Hello world</p>

class Reversed: ...
auto text_block = new Reversed(new Text());
text_block->render("Hello world");
>>> dlrow olleH

class Link: ...
auto text_block = new Link(new Text());
text_block->render("netology.ru", "Hello world");
>>> <a href=netology.ru>Hello world</a>

Обратите внимание
- Сигнатура метода Link::render() не совпадает с сигнатурой оригинального метода.
- Для разворота строки используйте функцию std::reverse cppreference.
*/

int main(int argc, char** argv)
{
	printHeader(L"Домашнее задание к занятию «Структурные шаблоны: Proxy, Decorator, Adapter»");

	auto text_block = new BoldText(new ItalicText(new Text()));
    text_block->render(L"Привет, Мир!");
	std::wcout << "\n\n";

	auto text_parag = new Paragraph(new Text());
	text_parag->render(L"Новый параграф");
	std::wcout << "\n\n";

	auto text_reverse = new Reversed(new Text());
	text_reverse->render(L"Задом на перёд");
	std::wcout << "\n\n";

	auto text_link = new Link(new Text());
	text_link->render(L"netology.ru", L"Hello world");
	std::wcout << "\n\n";

	return 0;
}
