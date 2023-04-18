#include <string>
#include <iostream>

class Text
{
public:
    virtual void render(const std::string& data) const
	{
        std::cout << data;
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
    void render(const std::string& data)  const
	{
        std::cout << "<i>";
        text_->render(data);
        std::cout << "</i>";
    }
};

class BoldText : public DecoratedText
{
public:
    explicit BoldText(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const
	{
        std::cout << "<b>";
        text_->render(data);
        std::cout << "</b>";
    }
};
