import random
from sys import argv
import time

random.seed(time.time())
COUNT = int(argv[1]) - int(argv[2])
RICH = int(argv[2]) 
MAXES = 100
MAX_MAX = 10**12

moneys = []
for _ in range(COUNT):
    moneys.append(random.randint(1, MAX_MAX - MAXES))

for _ in range(RICH):
    moneys.append(random.randint(MAX_MAX - MAXES + 1, MAX_MAX))

sum_rich = sum(moneys[-RICH:])

random.shuffle(moneys)
print(f"{COUNT + RICH} {RICH}\n{' '.join(str(m) for m in moneys)}")

print(f"{sum(moneys)} {sum_rich}")


