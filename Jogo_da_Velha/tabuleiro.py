# -*- coding: utf-8 -*-

class Tabuleiro:
    DESCONHECIDO = 0
    JOGADOR_0 = 1
    JOGADOR_X = 4

    def __init__(self):
        self.matriz = [ [Tabuleiro.DESCONHECIDO, Tabuleiro.DESCONHECIDO, Tabuleiro.DESCONHECIDO], 
                        [Tabuleiro.DESCONHECIDO, Tabuleiro.DESCONHECIDO, Tabuleiro.DESCONHECIDO],
                        [Tabuleiro.DESCONHECIDO, Tabuleiro.DESCONHECIDO, Tabuleiro.DESCONHECIDO]]
       
    def tem_campeao(self):
        soma = 0
        #Verificar linhas
        for i in range(3):
            soma = 0
            for j in range(3):
                soma = self.matriz[i][j] + soma
            if soma == 3:
                return Tabuleiro.JOGADOR_0
            elif soma == 12:
                return Tabuleiro.JOGADOR_X

        #Verificar colunas
        for j in range(3):
            soma = 0
            for i in range(3):
                soma = self.matriz[i][j] + soma
            if soma == 3:
                return Tabuleiro.JOGADOR_0
            elif soma == 12:
                return Tabuleiro.JOGADOR_X


        #Verifica diagonais
        soma = self.matriz[0][0] + self.matriz[1][1] + self.matriz[2][2]
        if soma == 3:
            return Tabuleiro.JOGADOR_0
        elif soma == 12:
            return Tabuleiro.JOGADOR_X

        soma = self.matriz[0][2] + self.matriz[1][1] + self.matriz[2][0]
        if soma == 3:
            return Tabuleiro.JOGADOR_0
        elif soma == 12:
            return Tabuleiro.JOGADOR_X

        return Tabuleiro.DESCONHECIDO