// source code C++
#include <iostream>
#include <stdlib.h>
using namespace std;

/**< 八皇后问题的解决代码 */

class ChessBoard
{
public:
    ChessBoard(); // 8*8 chessboard
    ChessBoard(int);  // n*n chessboard
    void findSolution();

private:
    const bool available;
    const int square, norm;
    bool *column, *leftDiagonal, *rightDiagonal;
    int *positionInRow, howmany;

    void putQueeu(int);
    void printBoard(ostream&);
    void initializeBoard();

};

ChessBoard::ChessBoard() : available(true), square(8), norm(square-1)
{
    initializeBoard();
}

ChessBoard::ChessBoard(int n) : available(true), square(n), norm(square-1)
{
    initializeBoard();
}

void ChessBoard::initializeBoard()
{
    register int i;
    column = new bool[square];
    positionInRow = new int[square];
    leftDiagonal = new bool[square*2-1];
    rightDiagonal = new bool[square*2-1];

    for (i=0;i < square;++i)
    {
        positionInRow[i]=-1;
    }

    for (i=0;i<square;++i)
    {
        column[i] = available;
    }

    for (i=0;i<square*2-1;++i)
    {
        leftDiagonal[i]=rightDiagonal[i]=available;
    }
    howmany=0;
}

void ChessBoard::putQueeu(int row)
{
    for (int col=0;col<square;++col)
    {
        if (column[col] == available && leftDiagonal[row+col] == available && rightDiagonal[row-col+norm] == available)
        {
            positionInRow[row] = col;

            // 放下皇后
            column[col] = !available;
            leftDiagonal[row+col] = !available;
            rightDiagonal[row-col+norm] = !available;

            if (row < square-1)
            {
                putQueeu(row+1);
            }
            else  // 无法放下皇后
            {
                printBoard(cout);
            }

            // 恢复放下皇后的位置
            column[col] =available;
            leftDiagonal[row+col] = available;
            rightDiagonal[row-col+norm] =available;
        }
    }
}

void ChessBoard::findSolution()
{
    putQueeu(0);
    cout<<howmany<<"solutions found."<<endl;
}

void ChessBoard::printBoard(ostream& cout)
{
    for (int i=0;i<square;++i)
    {
        for (int j=0;j<square;++j)
        {
            // 输出棋盘
        }
    }
    cout<<endl;
}

void test3()
{
    ChessBoard chessboard;
    chessboard.findSolution();
}
