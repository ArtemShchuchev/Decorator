#include <string>
#include <iostream>
#include <algorithm>

class Text
{
public:
    virtual void render(const std::wstring& data) const
	{
        std::wcout << data;
    }
};


class DecoratedText : public Text
{
public:
    explicit DecoratedText(Text* text) : text_(text) {}
    Text* text_;
};

class ItalicText : public DecoratedText
{
public:
    explicit ItalicText(Text* text) : DecoratedText(text) {}
    void render(const std::wstring& data)  const
	{
        std::wcout << "<i>";
        text_->render(data);
        std::wcout << "</i>";
    }
};

class BoldText : public DecoratedText
{
public:
    explicit BoldText(Text* text) : DecoratedText(text) {}
    void render(const std::wstring& data) const
	{
        std::wcout << "<b>";
        text_->render(data);
        std::wcout << "</b>";
    }
};

class Paragraph : public DecoratedText
{
public:
    explicit Paragraph(Text* text) : DecoratedText(text) {}
    void render(const std::wstring& data) const
    {
        std::wcout << "<p>";
        text_->render(data);
        std::wcout << "</p>";
    }
};

class Reversed : public DecoratedText
{
public:
    explicit Reversed(Text* text) : DecoratedText(text) {}
    void render(std::wstring_view data) const
    {
        std::wstring d(data);
        std::reverse(d.begin(), d.end());
        text_->render(d);
    }
};

class Link : public DecoratedText
{
public:
    explicit Link(Text* text) : DecoratedText(text) {}
    void render(std::wstring_view refer, std::wstring_view discr) const
    {
        std::wstring data(L"<a href=");
        data += refer;
        data += '>';
        data += discr;
        data += L"</a>";
        text_->render(data);
    }
};
