# -*- coding: utf-8 -*-
import time
from maze import Maze
from collections import deque

def backtrack(maze: Maze) -> bool:
    stack = deque()
    visited = set()

    start = maze.get_init_pos_player()
    stack.append(start)
    visited.add(start)

    while stack:
        pos = stack.pop()
        row, col = pos

        maze.mov_player(pos)
        time.sleep(0.05)  # delay visual opcional

        if maze.M[row][col] == maze.PRIZE:
            print("Tesouro encontrado em:", pos)
            return True

        # Verificar vizinhos: cima, baixo, esquerda, direita
        for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            nr, nc = row + dr, col + dc

            if (0 <= nr < len(maze.M)) and (0 <= nc < len(maze.M[0])):
                if (maze.M[nr][nc] == maze.HALL or maze.M[nr][nc] == maze.PRIZE) and ((nr, nc) not in visited):
                    stack.append((nr, nc))
                    visited.add((nr, nc))

    print("Tesouro não encontrado.")
    return False


if __name__ == "__main__":
    maze_csv_path = "labirinto1.txt"
    maze = Maze()
    maze.load_from_csv(maze_csv_path)
    maze.run()
    maze.init_player()
    backtrack(maze)
