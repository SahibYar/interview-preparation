//
// Created by sahibyar on 10/31/17.
//

/*
 * As it is a backtracking algorithm, so basic steps for back tracking are
 * 1. Choose        // choose what to send to child nodes
 * 2. Compute       // call the function recursively
 * 3. un-choose     // do what you want to send to previous recursive  calls on call stack
 */

/*
 * The problem statement
 * https://en.wikipedia.org/wiki/Knight%27s_tour
 * A knight's tour is a sequence of moves of a knight on a
 * chessboard such that the knight visits every square only once.
 */
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

/// \param destination_index where it wanna go next
/// \param chessboard a linear array of 2d-chessboard
/// \return if space is empty or not
bool is_valid_move(int const destination_index, vector<int> chessboard)
{
    //out of range
    if (destination_index < 0 || destination_index >= chessboard.size())
        return false;

    return chessboard[destination_index] == 0;
}

void possibleUpMoves(int const current_index, vector<int> chessboard, int const row_column_length, vector<int>& possibleMoves)
{
    int upRight_index = current_index - (2*row_column_length) + 1;
    int upLeft_index = upRight_index - 2;

    bool isValid = is_valid_move(upRight_index, chessboard);
    // also checking boundary condition
    if (isValid && upRight_index % row_column_length > 0)
        possibleMoves.push_back(upRight_index);

    isValid = is_valid_move(upLeft_index, chessboard);
    if (isValid && upLeft_index % row_column_length < row_column_length - 1)
        possibleMoves.push_back(upLeft_index);
}

void possibleDownMoves(int const current_index, vector<int> chessboard, int const row_column_length, vector<int>& possibleMoves)
{
    int downRight_index = current_index + (2*row_column_length) + 1;
    int downLeft_index = downRight_index - 2;

    bool isValid = is_valid_move(downRight_index, chessboard);
    if (isValid && downRight_index % row_column_length > 0)
        possibleMoves.push_back(downRight_index);

    isValid = is_valid_move(downLeft_index , chessboard);
    if (isValid && downLeft_index % row_column_length < row_column_length - 1)
        possibleMoves.push_back(downLeft_index);
}

void possibleRightMoves(int const current_index, vector<int> chessboard, int const row_column_length, vector<int>& possibleMoves)
{
    int rightUp_index = (current_index + 2) - row_column_length;
    int rightDown_index = (current_index + 2) + row_column_length;

    bool isValid = is_valid_move(rightUp_index, chessboard);
    // also checking boundary condition
    if (isValid && rightUp_index % row_column_length > 1)
        possibleMoves.push_back(rightUp_index);

    isValid = is_valid_move(rightUp_index, chessboard);
    if (isValid && rightDown_index % row_column_length > 1)
        possibleMoves.push_back(rightDown_index);
}

void possibleLeftMoves(int const current_index, vector<int> chessboard, int const row_column_length, vector<int>& possibleMoves)
{
    int leftUp_index = (current_index - 2) - row_column_length;
    int leftDown_index = (current_index - 2) + row_column_length;

    bool isValid = is_valid_move(leftUp_index, chessboard);
    // also checking boundary condition
    if (isValid && leftUp_index % row_column_length < row_column_length - 2)
        possibleMoves.push_back(leftUp_index);

    isValid = is_valid_move(leftDown_index, chessboard);
    if (isValid && leftDown_index % row_column_length < row_column_length - 2)
        possibleMoves.push_back(leftDown_index);
}
/// \param current_index current position of knight on chessboard
/// \param chessboard a linear array of 2d-chessboard
/// \return an array of all the possible indexes, knight could move
vector<int> allPossibleMoves(int const current_index, vector<int> chessboard)
{
    vector<int> possibleMoves;

    // because chessboard is 2d, so we are taking square root of total blocks.
    int row_column_length = sqrt(chessboard.size());

    // finding all the possible up moves.
    if (current_index - (2*row_column_length) > 0)
        possibleUpMoves(current_index, chessboard, row_column_length, possibleMoves);

    // finding all the possible down moves.
    if (current_index + (2*row_column_length) >= chessboard.size())
        possibleDownMoves(current_index, chessboard, row_column_length, possibleMoves);

    // finding all the possible right moves.
    if (current_index + (2*row_column_length) >= chessboard.size())
        possibleDownMoves(current_index, chessboard, row_column_length, possibleMoves);

    return possibleMoves;
}

void knightTraversalHelper(int startingPosition, vector<int>& pathTraversed, int chessBoardLength)
{
    // find all the possible moves
    vector<int> possibleMoves = allPossibleMoves(startingPosition, pathTraversed);

    if (pathTraversed.size() == chessBoardLength) {
        for (auto i = pathTraversed.begin(); i != pathTraversed.end(); ++i)
            cout << *i << " ";
        cout << endl;
        return; // Success
    }
    else if(pathTraversed.size() == 1 && possibleMoves.size() == 0) {
        cout << "No possible path found" << endl;
        return; // Failure
    }
    // BackTracking function.
    // choose   ->  compute ->  un-choose
    while (possibleMoves.size() > 0)
    {
        // choose

        // find the next move, and delete it from possibleMoves
        int nextMove = possibleMoves.back();
        possibleMoves.pop_back();
        pathTraversed.push_back(nextMove);      // add it to path traversed.

        // compute
        knightTraversalHelper(nextMove, pathTraversed, chessBoardLength);

        // un-choose
        pathTraversed.pop_back();
    }
}

void knight_traversal(int startingPosition, int chessboardLength)
{
    vector<int> pathTraversed;
    knightTraversalHelper(startingPosition, pathTraversed, chessboardLength);
}

int main()
{
    int chessboardLength = 3*3;
    int startingPosition = 0;

    knight_traversal(startingPosition, chessboardLength);
    return EXIT_SUCCESS;
}