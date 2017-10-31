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
bool is_valid_move(int const destination_index, vector<int> chessboard) const
{
    //out of range
    if (destination_index < 0 || chessboard.length() >= destination_index)
        return false;

    return chessboard[destination_index] == 0;
}

void possibleUpMoves(int const current_index, vector<int> chessboard, int const row_column_length, vector<int>& possibleMoves) const
{
    int upRight_index = current_index - (2*row_column_length) + 1;
    int upLeft_index = upRight_index - 2;

    // also checking boundary condition
    if (upRight_index > 0 && upRight_index % row_column_length > 0)
        possibleMoves.push_back(upRight_index);

    if (upLeft_index > 0 && upLeft_index % row_column_length < row_column_length - 1)
        possibleMoves.push_back(upLeft_index);
}

void possibleDownMoves(int const current_index, vector<int> chessboard, int const row_column_length, vector<int>& possibleMoves) const
{
    int downRight_index = current_index + (2*row_column_length) + 1;
    int downLeft_index = downRight_index - 2;

    if (downRight_index < chessboard.length() && downRight_index % row_column_length > 0)
        possibleMoves.push_back(downRight_index);

    if (downLeft_index < chessboard.length() && downLeft_index % row_column_length < row_column_length - 1)
        possibleMoves.push_back(downLeft_index);
}

void possibleRightMoves(int const current_index, vector<int> chessboard, int const row_column_length, vector<int>& possibleMoves) const
{
    int rightUp_index = (current_index + 2) - row_column_length;
    int rightDown_index = (current_index + 2) + row_column_length;

    // also checking boundary condition
    if (rightUp_index > 0 && rightUp_index % row_column_length > 1)
        possibleMoves.push_back(rightUp_index);

    if (rightDown_index < chessboard.length() && rightDown_index % row_column_length > 1)
        possibleMoves.push_back(upLeft_index);
}

void possibleLeftMoves(int const current_index, vector<int> chessboard, int const row_column_length, vector<int>& possibleMoves) const
{
    int leftUp_index = (current_index - 2) - row_column_length;
    int leftDown_index = (current_index - 2) + row_column_length;

    // also checking boundary condition
    if (leftUp_index > 0 && leftUp_index % row_column_length < row_column_length - 2)
        possibleMoves.push_back(leftUp_index);

    if (leftDown_index < chessboard.length() && leftDown_index % row_column_length < row_column_length - 2)
        possibleMoves.push_back(leftDown_index);
}
/// \param current_index current position of knight on chessboard
/// \param chessboard a linear array of 2d-chessboard
/// \return an array of all the possible indexes, knight could move
vector<int> possibleMoves(int const current_index, vector<int> chessboard) const
{
    vector<int> possibleMoves;

    // because chessboard is 2d, so we are taking square root of total blocks.
    int row_column_length = sqrt(chessboard.length());

    // finding all the possible up moves.
    if (current_index - (2*row_column_length) > 0)
        possibleUpMoves(current_index, chessboard, row_column_length, possibleMoves);

    // finding all the possible down moves.
    if (current_index + (2*row_column_length) >= chessboard.length())
        possibleDownMoves(current_index, chessboard, row_column_length, possibleMoves);

    // finding all the possible right moves.
    if (current_index + (2*row_column_length) >= chessboard.length())
        possibleDownMoves(current_index, chessboard, row_column_length, possibleMoves);

    return possibleMoves;
}

