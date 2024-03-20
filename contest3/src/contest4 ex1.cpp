/*
githubstrongpassword
Как пушить и коммитить

1. git add .  (Добавляет все файлы в коммит)
2. git commit -m ‘Your message’ (делает коммит с сообщением)
3. git push (загружает коммит/файлы на гит)
___

1. git fetch (проверяет изменение репы на гите от который мы будем пуллить)
2. git pull (загружает обновление с репы) 

Сохранить код command S
Новые темы в квадратике сбоку
Чтобы не было ошибки в файле CMake менять на названия файла и всех остальных


Прописывать в файле settings.json чтобы был clang-format
{
    "files.associations": {
        "vector": "cpp"
    },
    "clang-format.executable": "/opt/homebrew/bin/clang-format",
    "clang-format.fallbackStyle": "Microsoft"
}
кнопки для clang-format - option+shift+F


Рассмотрим последовательность целых чисел длины n. По ней с шагом 1 двигается «окно» длины k,
то есть сначала в «окне» видны первые k чисел, на следующем шаге в «окне» уже будут находиться k чисел,
начиная со второго, и так далее до конца последовательности.
Требуется для каждого положения «окна» определить минимум в нём.

Формат ввода
В первой строке входных данных содержатся два натуральных числа n и k
(n ≤  150000, k ≤ 10000, k ≤  n) – длины последовательности и «окна», соответственно.
На следующей строке находятся n чисел – сама последовательность.

Формат вывода
Выходые данные должны содержать n - k + 1 строк – минимумы для каждого положения «окна».
*/
#include <iostream>
#include <queue>
#include <set>
#include <sstream>
#include <vector>

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::cin.ignore();
    std::string numbers;
    std::getline(std::cin, numbers);
    std::istringstream s(numbers);
    std::vector<int> results;
    std::multiset<int> m;

    for (int i = 0; i < n; i++)
    {
        int a;
        s >> a;
        results.push_back(a);
        m.insert(a);
        if (i >= k - 1)
        {
            std::cout << *m.begin() << "\n";
            auto delate = m.find(results[i - k + 1]);
            m.erase(delate);
        }
    }

    return 0;
}
