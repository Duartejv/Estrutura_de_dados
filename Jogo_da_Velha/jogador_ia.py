from random import randint

from jogador import Jogador
from tabuleiro import Tabuleiro

class JogadorIA(Jogador):
    def __init__(self, tabuleiro: Tabuleiro, tipo: int):
        super().__init__(tabuleiro, tipo)

    def getJogada(self) -> (int, int):
        #R(1)
        #completar linha(R1)
        for l in range(3):
            lista = []
            soma=0
            for c in range(3):
                soma = self.matriz[l][c] + soma
                if self.matriz[l][c] == Tabuleiro.DESCONHECIDO:
                    lista.append((l, c))
            if len(lista) != 0 and (soma == 2 or soma == 8):
                return lista[0]

        #completar coluna(R1)
        for c in range(3):
            lista = []
            soma = 0
            for l in range(3):
                soma = self.matriz[l][c] + soma
                if self.matriz[l][c] == Tabuleiro.DESCONHECIDO:
                    lista.append((l, c))
            if len(lista) != 0 and (soma == 2 or soma == 8):
                return lista[0]

        #completar verticais(R1)
        lista = []
        soma = 0
        soma = self.matriz[0][0] + self.matriz[1][1] + self.matriz[2][2]
        if soma == 2 or soma == 8:
            if self.matriz[0][0] == Tabuleiro.DESCONHECIDO:
                lista.append((0, 0))
            elif self.matriz[1][1] == Tabuleiro.DESCONHECIDO:
                lista.append((1, 1))
            elif self.matriz[2][2] == Tabuleiro.DESCONHECIDO:
                lista.append((2, 2))

            return lista[0]
        
        lista = []
        soma = 0
        soma = self.matriz[0][2] + self.matriz[1][1] + self.matriz[2][0]
        if soma == 2 or soma == 8:
            if self.matriz[0][2] == Tabuleiro.DESCONHECIDO:
                lista.append((0, 2))
            elif self.matriz[1][1] == Tabuleiro.DESCONHECIDO:
                lista.append((1, 1))
            elif self.matriz[2][0] == Tabuleiro.DESCONHECIDO:
                lista.append((2, 0))
            return lista[0]
        
        #R2
        #linha(R2)
        for l in range(3):
            lista = []
            soma=0
            for c in range(3):
                soma = self.matriz[l][c] + soma
                if self.matriz[l][c] == Tabuleiro.DESCONHECIDO:
                    lista.append((l, c))
            if len(lista) != 0 and (soma == 1):
                return lista[0]
        
        #coluna(R2)
        for c in range(3):
            lista = []
            soma=0
            for l in range(3):
                soma = self.matriz[l][c] + soma
                if self.matriz[l][c] == Tabuleiro.DESCONHECIDO:
                    lista.append((l, c))
            if len(lista) != 0 and (soma == 1):
                return lista[0]
        
        #verticais(2R)
        lista = []
        soma = 0
        soma = self.matriz[0][0] + self.matriz[1][1] + self.matriz[2][2]
        if soma == 1:
            if self.matriz[0][0] == Tabuleiro.DESCONHECIDO:
                lista.append((0, 0))
            elif self.matriz[1][1] == Tabuleiro.DESCONHECIDO:
                lista.append((1, 1))
            elif self.matriz[2][2] == Tabuleiro.DESCONHECIDO:
                lista.append((2, 2))

            return lista[0]
        
        lista = []
        soma = 0
        soma = self.matriz[0][2] + self.matriz[1][1] + self.matriz[2][0]
        if soma == 1:
            if self.matriz[0][2] == Tabuleiro.DESCONHECIDO:
                lista.append((0, 2))
            elif self.matriz[1][1] == Tabuleiro.DESCONHECIDO:
                lista.append((1, 1))
            elif self.matriz[2][0] == Tabuleiro.DESCONHECIDO:
                lista.append((2, 0))
            return lista[0]
        
        #R3
        #meio(R3)
        if self.matriz[1][1] == Tabuleiro.DESCONHECIDO:
            lista = []
            lista.append((1, 1))
            return lista[0]
        
        #R4
        #oposição das verticais(R4)
        lista = []
        soma = 0
        soma = self.matriz[0][0] + self.matriz[1][1] + self.matriz[2][2]
        if soma == 4 or soma == 5:
            if self.matriz[0][0] == Tabuleiro.DESCONHECIDO:
                lista.append((0, 0))
            elif self.matriz[2][0] == Tabuleiro.DESCONHECIDO:
                lista.append((2, 2))

            return lista[0]
        
        lista = []
        soma = 0
        soma = self.matriz[0][2] + self.matriz[1][1] + self.matriz[2][0]
        if soma == 4 or soma == 5:
            if self.matriz[0][2] == Tabuleiro.DESCONHECIDO:
                lista.append((0, 2))
            elif self.matriz[2][0] == Tabuleiro.DESCONHECIDO:
                lista.append((2, 0))

            return lista[0]
        
        #R5
        #lugar livre
        lista = []
        if self.matriz[0][0] == Tabuleiro.DESCONHECIDO:
            lista.append((0, 0))
            return lista[0]
        elif self.matriz[0][2] == Tabuleiro.DESCONHECIDO:
            lista.append((0, 2))
            return lista[0]
        elif self.matriz[2][2] == Tabuleiro.DESCONHECIDO:
            lista.append((2, 2))
            return lista[0]
        elif self.matriz[2][0] == Tabuleiro.DESCONHECIDO:
            lista.append((2, 0))
            return lista[0]

        #R6
        #considerações finais
        
        nenhum = []
        for l in range(3):
            for c in range(3):
                if self.matriz[l][c] == Tabuleiro.DESCONHECIDO:
                    nenhum.append((l, c))
        if(len(nenhum) > 0):
            p = randint(0, len(nenhum)-1)
            return nenhum[p]
        else:
           return None