import sys


class Node:
    def __init__(self, value: int, left: 'Node|None' = None, right: 'Node|None' = None):
        self.value = value
        self.left: 'Node|None' = left
        self.right: 'Node|None' = right

    def add(self, value: int):
        if value < self.value:
            if self.left is None:
                self.left = Node(value)
            else:
                self.left.add(value)
        elif value > self.value:
            if self.right is None:
                self.right = Node(value)
            else:
                self.right.add(value)

    def height(self) -> int:
        return 1 + max(self.left.height() if self.left else 0,
                       self.right.height() if self.right else 0)


with open(sys.argv[1], 'r') as f:
    lines = f.readlines()

with open(sys.argv[2], 'r') as f:
    correct_lines = f.readlines()[1:]

for l, line in enumerate(lines):
    if line.startswith('IM'):
        print(line.strip())
        continue

    numbers = line.split()
    root = Node(int(numbers[0]))
    for number in numbers[1:]:
        root.add(int(number))

    print(root.height())
    assert str(
        root.height()) in correct_lines[l], f"Expected {correct_lines[l]}, got {root.height()}"
