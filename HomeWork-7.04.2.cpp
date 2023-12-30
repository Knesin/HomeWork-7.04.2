#include <iostream>
#include <fstream>
#include <vector>
#include "Source2.h"

int main()
{
    std::ofstream f("test.txt");
//=============
    //DataText test_text("Test text string");
    //DataHTML test_HTML("Test HTML string");
    //DataJSON test_JSON("Test JSON string");

    //saveTo(f, test_HTML);
    //saveTo(f, test_JSON);
    //saveTo(f, test_text);

//============
    //Data* data[2];
    //data[0] = new DataText("Test text string");
    //data[1] = new DataHTML("Test HTML string");
    std::vector<Data*> data = {
        new DataText("Test text string"),
        new DataHTML("Test HTML string"),
        new DataJSON("Test JSON string")
    };

    for (const auto &da : data) {
        saveTo(f, *da);
    }
    for (Data* da : data) {
        delete da;
    }
    std::cout << "Complit...";
}