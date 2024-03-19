/*
             "Сапёр"
Вы должны разминировать поле. На каждой клетке, не занятой миной, написано,
сколько мин расположено в клетках вокруг неё.
Один студент решил написать класс для своей реализации этой игры.
Класс должен уметь создавать прямоугольное поле заданных размеров, ставить "мину"
в указанную клетку (индексы клеток начинаются с нуля), а также записывать в каждую
свободную клетку количество мин вокруг неё. Кроме того, должен быть оператор <<,
который печатает поле (а вместо мин печатает "звездочки").
*/
#include <iostream>
#include <vector>

class Minesweeper {
private:
    size_t M, N;
    std::vector<std::vector<int>> Table;

public:
    Minesweeper(size_t m, size_t n) : M(m), N(n) {
        Table.resize(M, std::vector<int>(N, 0));
    }

    size_t Rows() const {
        return M;
    }

    size_t Columns() const {
        return N;
    }

    void SetMine(size_t i, size_t j) {
        Table[i][j] = -1;
    }

    int operator()(size_t i, size_t j) const {
        return Table[i][j];
    }

    void CheckForMinesAround() {
        for (size_t i = 0; i != M; ++i)
            for (size_t j = 0; j != N; ++j)
                if (Table[i][j] != -1) // Check if the cell is not a mine
                    CheckForMinesAround(i, j);
    }

    friend std::ostream& operator<<(std::ostream& out, const Minesweeper& ms);

private:
    void CheckForMinesAround(size_t i, size_t j) {
        int counter = 0;
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (dx == 0 && dy == 0) // Skip the current cell
                    continue;
                if (0 <= i + dx && i + dx < M &&
                    0 <= j + dy && j + dy < N &&
                    Table[i + dx][j + dy] == -1) {
                    ++counter;
                }
            }
        }
        Table[i][j] = counter;
    }
};

std::ostream& operator<<(std::ostream& out, const Minesweeper& ms) {
    for (size_t i = 0; i != ms.Rows(); ++i) {
        for (size_t j = 0; j != ms.Columns(); ++j) {
            if (ms(i, j) == -1)
                out << '*';
            else
                out << ms(i, j);
        }
        out << "\n";
    }
    return out;
}
