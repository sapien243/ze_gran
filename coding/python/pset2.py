#!/usr/bin/env python
# coding: utf-8

# Pset 2: Tic-Tac-Toe aka "Noughts and Crosses" (EIE, UoN)
# Using Minimax, implement an AI to play Tic-Tac-Toe optimally.

from IPython.display import clear_output
import time
from random import randint
import copy
# Run {pip install -i https://test.pypi.org/simple/ fee232==0.1.3}
from tictactoe.tictactoe import *

X, O, E = "X", "O", None
blue, black, red = '\033[94m', '\033[0m', '\033[91m'


def initial_state():
    """
    Returns starting state of the board.
    """
    return [[E, E, E],
            [E, E, E],
            [E, E, E]]


def player(board):
    """
    Returns player who has the next turn on a board.
    """

    # YOUR CODE HERE
    plx = plo = 0
    for row in board:
        for pos in row:
            if pos == X:
                plx += 1
            if pos == O:
                plo += 1

    return X if plx == plo else O
    # raise NotImplementedError()


def actions(board):
    """
    Returns set of all possible actions (i, j) available on the board.
    """

    # YOUR CODE HERE
    act_set = set()
    for i, row in enumerate(board):
        for j, pos in enumerate(row):
            if pos == E:
                act_set.add((i, j))

    return act_set
    # raise NotImplementedError()


def result(board, action):
    """
    Returns the board that results from making move (i, j) on the board.
    """

    # YOUR CODE HERE
    shadow = copy.deepcopy(board)
    i = action[0]
    j = action[1]
    if (i or j) > 2 or shadow[i][j] != E:
        raise Exception("Invalid action")
    shadow[i][j] = player(shadow)

    return shadow
    # raise NotImplementedError()


def winner(board):
    """
    Returns the winner of the game, if there is one.
    """

    # YOUR CODE HERE
    for i in range(3):
        row = set(board[i])
        if len(row) == 1 and board[i][0] != E:
            return board[i][0]
    for j in range(3):
        col = {board[0][j], board[1][j], board[2][j]}
        if len(col) == 1 and board[0][j] != E:
            return board[0][j]
    for k, l in zip([0, 2], [2, 0]):
        dig = {board[0][k], board[1][1], board[2][l]}
        if len(dig) == 1 and board[1][1] != E:
            return board[1][1]

    return None
    # raise NotImplementedError()


def terminal(board):
    """
    Returns True if game is over, False otherwise.
    """

    # YOUR CODE HERE
    if winner(board) != None or len(actions(board)) == 0:
        return True

    return False
    # raise NotImplementedError()


def utility(board):
    """
    Returns 1 if X has won the game, -1 if O has won, 0 otherwise.
    """

    # YOUR CODE HERE
    stat = winner(board)
    if stat == None:
        return 0

    return 1 if stat == X else -1
    # raise NotImplementedError()


def minimax(board):
    """
    Returns the optimal action for the current player on the board.
    """

    # YOUR CODE HERE
    if terminal(board):
        return None
    guy = 1 if player(board) == X else -1
    optimal = minmax(board, guy)
    return optimal[0]
    # raise NotImplementedError()


def minmax(board, guy):
    best, ties, loss = [], [], []
    best_len, ties_len, loss_len = 0, 0, 0

    for mov in actions(board):
        test = result(board, mov)
        if terminal(test):
            score = utility(test)
            if score == guy:
                return [mov, score]
        else:
            score = minmax(test, guy*-1)[1]

        if (guy == 1 and score > 0) or (guy != 1 and score < 0):
            best.append([mov, score])
            best_len+=1
        elif score == 0:
            ties.append([mov, score])
            ties_len+=1
        else:
            loss.append([mov, score])
            loss_len+=1

    if best_len > 0:
        return best[randint(0, best_len-1)]
    if ties_len > 0:
        return ties[randint(0, ties_len-1)]
    return loss[randint(0, loss_len-1)]


"""
import math

def minimax(board):
    # Helper function to find the max value for a player
    def max_value(board):
        if terminal(board):
            return utility(board)
        v = -math.inf
        for action in actions(board):
            v = max(v, min_value(result(board, action)))
        return v

    # Helper function to find the min value for a player
    def min_value(board):
        if terminal(board):
            return utility(board)
        v = math.inf
        for action in actions(board):
            v = min(v, max_value(result(board, action)))
        return v

    # Start of minimax function
    if terminal(board):
        return None
    player_turn = player(board)
    if player_turn == X:
        v = -math.inf
        best_move = None
        for action in actions(board):
            new_v = min_value(result(board, action))
            if new_v > v:
                v = new_v
                best_move = action
    else:
        v = math.inf
        best_move = None
        for action in actions(board):
            new_v = max_value(result(board, action))
            if new_v < v:
                v = new_v
                best_move = action
    return best_move
"""


## Alph-beta pruning
# TODO:


# Test the functions
test_0(initial_state, player)
test_1(player)
test_2(actions)
test_3(result)
test_4(winner)
test_5(terminal)
test_6(utility)
test_7(minimax)


def display_board(board, header=None, footer=None):
    '''
    A function to diplay the board on the screen
    '''

    if header is None:
        print(' ')
    else:
        print(red + header + black, '\n')

    temp_board = copy.deepcopy(board)
    for i in range(3):
        for j in range(3):
            if temp_board[i][j] == None:
                temp_board[i][j] = ' '

    print('1    |2    |3  ')
    print(' ', blue + temp_board[0][0], black + ' | ', blue +
          temp_board[0][1], black + ' | ', blue + temp_board[0][2] + black)
    print('_____|_____|_____')
    print('4    |5    |6  ')
    print(' ', blue + temp_board[1][0], black + ' | ', blue +
          temp_board[1][1], black + ' | ', blue + temp_board[1][2] + black)
    print('_____|_____|_____')
    print('7    |8    |9  ')
    print(' ', blue + temp_board[2][0], black + ' | ', blue +
          temp_board[2][1], black + ' | ', blue + temp_board[2][2] + black)
    print('     |     |  ')

    if footer is not None:
        print('\n')
        print(footer)


def player_input(board, title=None):
    '''
    Check for the user input
    '''

    while True:
        move = input(
            'Choose a valid position for your next  move (1, 2, ..., 9): ')
        if move not in ['1', '2', '3', '4', '5', '6', '7', '8', '9']:
            continue
        # -1 because the board_positions displayed started at 1 and not 0
        move = int(move) - 1
        i, j = move // 3, move % 3

        if board[i][j] == None:
            return (i, j)
        else:
            print('You need to choose an available position!')


def play_game(board):
    '''
    A function to simulate the game
    '''

    user = None
    ai_turn = False

    print('Welcome to Tic Tac Toe...')

    while True:
        user = input('Choose the player you would like to be (X or O): ')
        user = user.upper()
        if user not in ['X', 'O']:
            print('You chose an invalid option...')
            time.sleep(3)
            clear_output()
            continue
        else:
            break

    minimax_time = None

    while True:
        game_over = terminal(board)
        next_player = player(board)

        # Determine the title
        if game_over:
            game_winner = winner(board)
            if game_winner is None:
                title = f'Game over: Tie.'
            else:
                title = f'Game over: {game_winner} wins.'
        elif user == next_player:
            if minimax_time is not None:
                title = f"The AI's move took {minimax_time} milliseconds.\nYour turn to play."
            else:
                title = f'Your turn to play.'
        else:
            title = f'The AI is thinking...'

        clear_output()
        display_board(board, title)

        # Check for AI move
        if user != next_player and not game_over:
            if ai_turn:
                time.sleep(5)
                start_time = round(time.time() * 1000)
                move = minimax(board)
                end_time = round(time.time() * 1000)
                minimax_time = int(end_time - start_time)
                board = result(board, move)
                ai_turn = False
            else:
                ai_turn = True

        # Check for a user move
        if user == next_player and not game_over:
            i, j = player_input(board, title)
            board = result(board, (i, j))

        if game_over:
            break


## Play the game
board = initial_state()
play_game(board)

## Fin
