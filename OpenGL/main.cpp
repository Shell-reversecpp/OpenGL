#include "Game.h"

int main(int argc, char **argv)
{

    Game& game = Game::GetInstance();

    // Запуск игрового цикла
    int result = game.Execute();

    // Проверка результата выполнения
    if (result != 0) {
        std::cerr << "Game execution failed" << std::endl;
    }


    return result;

}
