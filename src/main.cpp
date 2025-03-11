#include <iostream>
#include <string>
#include <prometheus/exposer.h>
#include <prometheus/registry.h>
#include <prometheus/counter.h>

int main() {
// Создаем экспортер метрик на порту 8080
    prometheus::Exposer exposer{"0.0.0.0:8080"};

    // Создаем реестр для метрик
    auto registry = std::make_shared<prometheus::Registry>();

    // Создаем счетчик
    auto& counter_family = prometheus::BuildCounter()
        .Name("requests_total")
        .Help("Total number of requests")
        .Register(*registry);

    auto& counter = counter_family.Add({});

    // Экспортируем метрики
    exposer.RegisterCollectable(registry);

    // Увеличиваем счетчик каждую секунду
    while (true) {
        counter.Increment();
        std::cout << "Counter: " << counter.Value() << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    //--------------------------------------
    
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
