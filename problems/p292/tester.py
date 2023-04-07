#!/usr/bin/env python3
import random
from sys import argv

# some globals
rg_ncasas = (1, 10_000)
rg_nconexiones = (1, 100_000)
rg_esfuerzo = (1, 10_000)

# get seed 
seed = int(argv[1]) if int(argv[1]) > 0 else random.randint(0, 1_000_000)

print(f"Using seed {seed}")
random.seed(seed)

# generate things
ncasas = random.randint(*rg_ncasas) 
nconexiones = random.randint(*rg_nconexiones)
oficina = random.randint(1, ncasas)
npaquetes = random.randint(1, ncasas)

print(f"ncasas: {ncasas:6d}",
      f"nconexiones: {nconexiones:6d}",
      f"oficina: {oficina:6d}",
      f"npaquetes: {npaquetes:6d}", sep="\n")

# start creating input
input_text = f"{ncasas}\n{nconexiones}\n"

for i in range(nconexiones):
    input_text += f"{random.randint(1, ncasas)} {random.randint(1, ncasas)} {random.randint(*rg_esfuerzo)}\n"

input_text += f"{oficina} {npaquetes}\n"

input_text += ' '.join(str(random.randint(1, ncasas)) for _ in range(npaquetes))

# write file
with open(argv[2], 'w') as f:
    f.write(input_text)



