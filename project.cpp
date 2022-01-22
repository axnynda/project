#include <iostream>
using namespace std;
int board[1000][1000];
int result = 0; // Количество решений


// Функция tryQueen() - проверяет нет ли уже установленных ферзей по вертикали, горизонтали и диагоналям
bool tryQueen(int a, int b, int SIZE)
{
  for(int i = 0; i < a; ++i)
  {
    if(board[i][b])
    {
      return false;
    }
  }

  for(int i = 1; i <= a && b-i >= 0; ++i)
  {
    if(board[a-i][b-i])
    {
      return false;
    }
  }

  for(int i = 1; i <= a && b+i < SIZE; i++)
  {
    if(board[a-i][b+i])
    {
      return false;
    }
  }

  return true;
}

void setQueen(int a, int SIZE) // пробует найти результаты решений
{
  if(a == SIZE)
  {
    result+=1;
    return;
  }

  for(int i = 0; i < SIZE; ++i)
  {
    // Здесь проверяем, что если поставим в board[a][i] ферзя, то он будет единственным в этой строке, столбце и диагоналях
    if(tryQueen(a, i, SIZE))
    {
      board[a][i] = 1;
      setQueen(a+1,SIZE);
      board[a][i] = 0;
    }
  }

  return;
}

int main()
{
  int N;
  cin >> N;
  setQueen(0, N);
  cout << result;

  return 0;
}
