import random

MAX_LIVES = 100_000
MAX_RANGE = 10_000_000


def solve(lives: int, start_energy: int, things: list[int]):
    energy = start_energy

    for thing in things:
        if thing > 0:
            energy = min(energy + thing, start_energy)
            continue

        if thing < 0:
            if abs(thing) >= start_energy:
                return False

            energy += thing
            if energy <= 0:
                lives -= 1
                energy = start_energy + thing
                if lives <= 0:
                    return False
    return True


def make_test():
    lives = random.randint(1, MAX_LIVES)
    things = random.randint(1, MAX_LIVES)

    things_list = [
        random.randint(-MAX_RANGE, MAX_RANGE) for _ in range(things)
    ]
    things_list = [thing if thing != 0 else 1 for thing in things_list]
    print(f"{lives} {things}\n{' '.join(map(str, things_list))}")
    # given_energy = input().strip()

    # can_solve = solve(lives, int(given_energy), things_list)
    # can_solve_prev = solve(lives, int(given_energy) - 1, things_list)
    # assert can_solve, "The given energy should be enough to solve the problem"
    # assert not can_solve_prev, "The given energy - 1 should not be enough to solve the problem"


make_test()
