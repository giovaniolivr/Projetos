# coding: utf-8


import numpy as np
import matplotlib.pyplot as plt
import sys

fileName = str(sys.argv[1])

f1 = open(fileName, 'r')
pos = f1.read().splitlines()

for t in range(len(pos)):  ## label, x, y
    pos[t] = pos[t].split(' ')
    pos[t][0] = float(pos[t][0])
    pos[t][1] = float(pos[t][1])
    pos[t][2] = float(pos[t][2])

pos.append(pos[0])  # para aparcer a linha ligando o ultimo ponto ao primeiro

d = np.array(pos)

labels = ['{0}'.format(str(int(i))) for i in d[:,0]]  # aqui é a formatação das labels, se vc quiser add alguma palavras use: 'PALAVRA{0}'.format(str(int(i)))

fig = plt.figure()
ax = fig.add_subplot(111)

plt.subplots_adjust(bottom=0.1)

plt.plot(d[:, 1], d[:, 2], 'k')

plt.quiver(d[:-1, 1], d[:-1, 2], d[1:, 1] - d[:-1, 1], d[1:, 2] - d[:-1, 2], scale_units='xy', angles='xy', scale=1, alpha=0.7, color='black')  # A COR DA SETA MUDA AQUI, por exemplo, 'red'

plt.scatter(
    d[:, 1], d[:, 2], marker='o', c='red', s=50)  # aqui vc pode modar a cor (c='pink', por exemplo) e o formato dos pontos (marker='x', por exemplo) e o tamanho (s=150)

for label, x, y in zip(labels, d[:, 1], d[:, 2]):
    plt.annotate(
        label,
        xy=(x, y), xytext=(0, 5), fontweight='bold', fontsize=14, # aqui voce muda a posição da escrita, por exemplo, para mais longe xytext = (-10, -10)
        textcoords='offset points', ha='right', va='bottom',

    )
### COLOCAR NOME NO GRAFICO E NOS EIXOS
##ax.set_title('TRAJECTORY', fontweight='bold', fontsize=24)
ax.set_xlabel('x', fontsize=14)
ax.set_ylabel('y', fontsize=14)

plt.show()