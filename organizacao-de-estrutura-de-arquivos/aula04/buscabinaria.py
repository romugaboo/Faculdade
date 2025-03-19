import random

v = [ random.randint(0,1000) for x in range(0,15) ]
procurado = v[0]
v.sort()
print(f"Vou procurar {procurado}")
print(v)

achei = False
inicio = 0
fim = len(v)-1
while inicio <= fim and not achei:
    meio = (inicio+fim)//2
    if v[meio]==procurado:
        achei = True
    elif procurado > v[meio]:
        inicio = meio+1
    else:
        fim = meio-1

if achei:
    print(f"Achei {procurado} na posicao {meio}")
else:
    print(f"O elemento {procurado} nao esta na lista")
    print(f"So de curiosidade: o valor de meio e {meio}")
