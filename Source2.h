#pragma once
#include <fstream>

class Printable
{
public:
    virtual ~Printable() = default;

    virtual std::string print() const = 0;
};

class Data : public Printable {
public:
    Data(std::string data)
        : data_(std::move(data)) {}
protected:
    std::string data_;
};

class DataText : public Data
{
public:
    DataText(std::string data)
        : Data(std::move(data)) {}
    std::string print() const override
    {
        return data_;
    }
};

class DataHTML : public Data
{
public:
    DataHTML(std::string data)
        : Data(std::move(data)) {}
    std::string print() const override
    {
        return "<html>" + data_ + "<html/>";
    }
};

class DataJSON :  public Data
{
public:
    DataJSON(std::string data)
        : Data(std::move(data)) {}
    std::string print() const override
    {
        return "{ \"data\": \"" + data_ + "\"}";
    }
};

void saveTo(std::ofstream& file, const Printable& printable) {
    file << printable.print();
}