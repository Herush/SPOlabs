#include <iostream>
#include <string>
#include <prometheus/exposer.h>
#include <prometheus/registry.h>

int main() {
    // auto registry = std::make_shared<prometheus::Registry>();
    // auto& counter = prometheus::BuildCounter()
    // .Name("requests_total")
    // .Help("Total requests")
    // .Register(*registry)
    // .Add({});
    
    std::cout << "Enter string: " << std::endl;
    std::string str1;
    std::getline(std::cin, str1);
    char symbol;
    int counter = 0;

    for (int i = 0; i < size(str1) + 1; i++) {
        symbol = str1[i];
        if ((symbol == ' ' || symbol == ',' || symbol == '.' || i == size(str1)) && ( i != 0) && (str1[i-1] != ' ' && str1[i-1] != ',' && str1[i-1] != '.')) {
            counter++;
        }
    }

    std::cout << "words count: " << counter << std::endl;
    return 0;
}
