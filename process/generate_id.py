import os
import pandas as pd
from random import randint, choice, shuffle, sample

msak_maporigin='./CelebA-HQ-to-CelebA-mapping.txt'
origin_mapid='./identity_CelebA.txt'
save_path = './id_map.txt'

ID=[]
with open(msak_maporigin,'r') as f:
    lines = f.readlines()
    for i in range (1,30001):
        num_images = str(lines[i])
        name=lines[i].split()
        picid=name[2]
        pl=picid.split('.')
        picid=int(pl[0])
        ID.append(picid)
    print(ID[29999])


kl = [[0]]

idx = [0]*202598
print(idx)
with open(origin_mapid,'r') as f:
    lines = f.readlines()
    print(lines[202598])
    for i in range (0,202560):
        num_images = str(lines[i])
        nam = lines[i].split()
        print(nam)
        po=nam[0]
        po=po.split('.')
        nam[0]=int(po[0])
        print(nam)
        idx[nam[0]]=int(nam[1])

for i in range (0,30000):
    ID[i]=idx[ID[i]]

print(ID[0])
print(ID[29999])

with open(save_path,'w') as f:
    for i in range (0,30000):
        f.write(str(i))
        f.write(' ')
        f.write(str(ID[i]))
        f.write('\n')
