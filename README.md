## KDZ 2 - Рациональные числа и дерево выражений

Проект содержит библиотеку ratexpr, реализующую:

1) Класс Fraction для работы с рациональными числами.

2) Иерархию классов Expression для вычисления и вывода арифметических выражений.

## Требования

CMake 3.10 и выше, стандарт C++17

## Сборка

Debug:

cmake -S . -B build-debug -DCMAKE_BUILD_TYPE=Debug
cmake --build build-debug -j

Release:

cmake -S . -B build-release -DCMAKE_BUILD_TYPE=Release
cmake --build build-release -j

## Запуск

Release:

./build-release/apps/demo_fraction
./build-release/apps/demo_expression

Debug:

./build-debug/apps/demo_fraction
./build-debug/apps/demo_expression

demo_fraction - арифметические операции с рациональными числами.
demo_expression — создание и вычисление выражений.

Ответы на вопросы находятся в report/report.md