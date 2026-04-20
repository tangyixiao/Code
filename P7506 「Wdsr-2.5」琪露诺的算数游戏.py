import sys
from collections import deque

def is_normal(card: str) -> bool:
    """判断是否为普通牌（A/B/C/D/E开头且后面是数字）"""
    return card[0] in 'ABCDE' and card[1:].isdigit()

def is_special(card: str) -> bool:
    """判断是否为解牌"""
    return card in ('PASS', 'TURN', 'DOUBLE')

def get_new_p(card: str, p: int) -> int:
    """计算出一张牌后的新 p 值，解牌不改变 p"""
    if not is_normal(card):
        return p
    t = card[0]
    x = int(card[1:])
    if t == 'A':
        return p + x
    elif t == 'B':
        return p - x
    elif t == 'C':
        return p * x
    elif t == 'D':
        return p // x
    else:  # 'E'
        return x

def decide(hand: list, p: int, is_double: bool):
    """
    根据当前手牌、p值和是否处于 DOUBLE 状态做出决策。
    返回应该打出的牌名；若返回 None 表示无论如何都会失败（随便出）。
    """
    normals = [c for c in hand if is_normal(c)]
    specials = [c for c in hand if is_special(c)]

    # 检查是否必败：没有解牌，且所有普通牌打出后都会导致 p > 99
    if not specials:
        safe = [c for c in normals if get_new_p(c, p) <= 99]
        if not safe:
            return None  # 必败

    if is_double:
        # 有 DOUBLE：优先解牌
        for sp in ['PASS', 'TURN', 'DOUBLE']:
            if sp in specials:
                return sp

        # 否则选普通牌中使 p 最小的安全牌
        safe = [(c, get_new_p(c, p)) for c in normals if get_new_p(c, p) <= 99]
        if safe:
            # 优先级：除法(D) > 减法(B) > 加法(A) > 乘法(C) > 固定(E)
            type_order = {'D': 0, 'B': 1, 'A': 2, 'C': 3, 'E': 4}
            safe.sort(key=lambda item: (item[1], type_order[item[0][0]]))
            return safe[0][0]
        else:
            # 理论上不会走到这里（有解牌的情况已经在前面返回）
            if specials:
                return specials[0]
            return None
    else:
        # 无 DOUBLE：优先普通牌中使 p 最大的安全牌
        safe = [(c, get_new_p(c, p)) for c in normals if get_new_p(c, p) <= 99]
        if safe:
            # 优先级：乘法(C) > 加法(A) > 减法(B) > 除法(D) > 固定(E)
            type_order = {'C': 0, 'A': 1, 'B': 2, 'D': 3, 'E': 4}
            safe.sort(key=lambda item: (-item[1], type_order[item[0][0]]))
            return safe[0][0]
        else:
            # 无安全普通牌，则选择解牌
            for sp in ['PASS', 'TURN', 'DOUBLE']:
                if sp in specials:
                    return sp
            return None

def main():
    data = sys.stdin.read().strip().split()
    if not data:
        return
    it = iter(data)
    n = int(next(it))
    m = int(next(it))
    k = int(next(it))

    players = []
    for _ in range(n):
        name = next(it)
        hand = [next(it) for _ in range(3)]
        players.append({'name': name, 'hand': hand})

    deck = deque()
    for _ in range(k):
        deck.append(next(it))

    start_player = 0
    output_lines = []

    for round_num in range(1, m + 1):
        output_lines.append(f"Round {round_num}:")
        p = 0
        current = start_player
        direction = 1           # 1 顺时针，-1 逆时针
        double_status = [False] * n
        round_end = False

        while not round_end:
            player = players[current]
            hand = player['hand']
            name = player['name']
            is_double = double_status[current]

            choice = decide(hand, p, is_double)

            if choice is None:
                # 必败：随便选一张普通牌打出
                for c in hand:
                    if is_normal(c):
                        choice = c
                        break
                else:
                    choice = hand[0]

                # 打出必败牌，p > 99，不输出 used 行
                hand.remove(choice)
                output_lines.append(f"{name} lost the game.")
                # 清空剩余手牌，摸三张
                hand.clear()
                for _ in range(3):
                    hand.append(deck.popleft())
                # 下一轮从该玩家开始
                start_player = current
                round_end = True
                break

            # 正常出牌
            new_p = get_new_p(choice, p)
            output_lines.append(f"{name} used {choice},now p={new_p}.")
            hand.remove(choice)
            hand.append(deck.popleft())   # 摸牌

            if is_special(choice):
                # 处理解牌效果
                next_player = (current + direction) % n
                if choice == 'PASS':
                    pass
                elif choice == 'TURN':
                    direction *= -1
                elif choice == 'DOUBLE':
                    double_status[next_player] = True

                # 如果在 DOUBLE 状态下出解牌，将 DOUBLE 转移给下一名玩家
                if is_double:
                    double_status[current] = False
                    double_status[next_player] = True

                p = new_p
                current = next_player
            else:
                # 普通牌
                if is_double:
                    # 解除自己的 DOUBLE 状态
                    double_status[current] = False
                    p = new_p

                    # 立即进行第二次出牌（情形1：无 DOUBLE）
                    choice2 = decide(hand, p, False)
                    if choice2 is None:
                        # 第二张牌必败
                        for c in hand:
                            if is_normal(c):
                                choice2 = c
                                break
                        else:
                            choice2 = hand[0]
                        hand.remove(choice2)
                        output_lines.append(f"{name} lost the game.")
                        hand.clear()
                        for _ in range(3):
                            hand.append(deck.popleft())
                        start_player = current
                        round_end = True
                        break

                    new_p2 = get_new_p(choice2, p)
                    output_lines.append(f"{name} used {choice2},now p={new_p2}.")
                    hand.remove(choice2)
                    hand.append(deck.popleft())
                    p = new_p2

                    # 第二张若是解牌，处理其效果
                    if is_special(choice2):
                        next_player = (current + direction) % n
                        if choice2 == 'PASS':
                            pass
                        elif choice2 == 'TURN':
                            direction *= -1
                        elif choice2 == 'DOUBLE':
                            double_status[next_player] = True
                        current = next_player
                    else:
                        current = (current + direction) % n
                else:
                    p = new_p
                    current = (current + direction) % n

    sys.stdout.write('\n'.join(output_lines))

if __name__ == '__main__':
    main()