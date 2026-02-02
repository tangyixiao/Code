#include <bits/stdc++.h>
using namespace std;

const int MAX_PIGS = 15;
const int MAX_CARDS = 2005;

// 猪的身份：0-主猪，1-忠猪，2-反猪
const bool IDENTITY_CONFLICT[3][3] = {
    {0, 0, 1}, // 主猪 vs 主猪/忠猪/反猪
    {0, 0, 1}, // 忠猪 vs 主猪/忠猪/反猪
    {1, 1, 0}  // 反猪 vs 主猪/忠猪/反猪
};

struct Pig {
    int identity;          // 身份：0主猪，1忠猪，2反猪
    int health;            // 体力值
    int loyaltyStatus;     // 表明身份：-1跳反，0未知，1跳忠
    bool isDead;           // 是否死亡
    int nextPig;           // 下一个活着的猪
    bool hasZhugeLiannu;   // 是否有诸葛连弩
    int cardCount;         // 手牌数量
    char cards[MAX_CARDS]; // 手牌
};

class PigKillGame {
private:
    int pigCount;             // 猪的数量
    int totalCards;           // 牌堆总牌数
    int rebelCount;           // 反猪总数
    int deadRebelCount;       // 已死亡的反猪数
    int currentRound;         // 当前回合标识（用于标记使用过的牌）
    Pig pigs[MAX_PIGS];       // 所有猪
    deque<char> cardDeque;    // 牌堆
    int tempCards[MAX_CARDS]; // 临时数组
    int usedCards[MAX_CARDS]; // 标记牌是否在本回合使用过

public:
    // 初始化游戏
    void initialize() {
        scanf("%d%d", &pigCount, &totalCards);
        rebelCount = deadRebelCount = 0;

        for (int i = 1, last = 0; i <= pigCount; i++) {
            pigs[i].health = pigs[i].cardCount = 4;
            pigs[i].isDead = pigs[i].loyaltyStatus = pigs[i].hasZhugeLiannu = 0;
            pigs[i].nextPig = i % pigCount + 1;

            char role = readChar();
            rebelCount += (role == 'F');
            pigs[i].identity = (role != 'F') ? ((role != 'Z') ? 0 : 1) : 2;

            readChar(); // 跳过空格
            for (int j = 1; j <= 4; j++) {
                pigs[i].cards[j] = readChar();
            }
        }

        pigs[1].loyaltyStatus = 1; // 主猪一开始就跳忠
        for (int i = 1; i <= totalCards; i++) {
            cardDeque.push_back(readChar());
        }
    }

    // 读取一个有效字符（跳过空白符）
    char readChar() {
        char ch = getchar();
        while (ch < 'A' || ch > 'Z') {
            ch = getchar();
        }
        return ch;
    }

    // 摸牌
    void drawCard(int pigIndex) {
        if (!cardDeque.empty()) {
            pigs[pigIndex].cards[++pigs[pigIndex].cardCount] = cardDeque.front();
            if (cardDeque.size() > 1) {
                cardDeque.pop_front();
            }
        }
    }

    // 判断是否应该攻击下家
    bool shouldAttackNext(int currentPig) {
        int nextPig = pigs[currentPig].nextPig;
        if (pigs[nextPig].loyaltyStatus == 0) {
            return false;
        } else if (pigs[nextPig].loyaltyStatus == 1) {
            return IDENTITY_CONFLICT[pigs[currentPig].identity][pigs[nextPig].identity];
        } else {
            return pigs[currentPig].identity == 0;
        }
    }

    // 寻找决斗目标
    int findDuelTarget(int currentPig) {
        if (pigs[currentPig].identity == 2) {
            return 1; // 反猪优先攻击主猪
        }
        for (int nextPig = pigs[currentPig].nextPig; nextPig != currentPig; nextPig = pigs[nextPig].nextPig) {
            if (!pigs[nextPig].isDead) {
                if ((pigs[nextPig].identity == 2 && pigs[nextPig].loyaltyStatus == 1) ||
                    (pigs[currentPig].identity == 0 && pigs[nextPig].loyaltyStatus == -1)) {
                    return nextPig;
                }
            }
        }
        return -1;
    }

    // 处理死亡惩罚和奖励
    void processDeathConsequences(int killer, int victim) {
        if (pigs[killer].identity == 0 && pigs[victim].identity == 1) {
            // 主猪杀死忠猪，弃置所有牌
            for (int i = 1; i <= pigs[killer].cardCount; i++) {
                usedCards[i] = currentRound;
            }
            pigs[killer].hasZhugeLiannu = 0;
        } else if (pigs[victim].identity == 2) {
            // 杀死反猪，摸三张牌
            drawCard(killer);
            drawCard(killer);
            drawCard(killer);
        }
    }

    // 在手中寻找指定牌
    int findCard(int pigIndex, char cardType) {
        for (int i = 1; i <= pigs[pigIndex].cardCount; i++) {
            if (pigs[pigIndex].cards[i] == cardType) {
                return i;
            }
        }
        return 0;
    }

    // 调整手牌（移除指定位置的牌）
    void removeCard(int pigIndex, int position) {
        for (int i = position; i < pigs[pigIndex].cardCount; i++) {
            pigs[pigIndex].cards[i] = pigs[pigIndex].cards[i + 1];
        }
        pigs[pigIndex].cardCount--;
    }

    // 响应桃
    void respondPeach(int pigIndex, int user) {
        if (pigIndex == user) {
            // 自己回合内使用桃
            for (int i = 1; i <= pigs[pigIndex].cardCount; i++) {
                if (usedCards[i] != currentRound && pigs[pigIndex].cards[i] == 'P') {
                    usedCards[i] = currentRound;
                    pigs[pigIndex].health++;
                    return;
                }
            }
        } else {
            // 濒死时使用桃
            int peachIndex = findCard(pigIndex, 'P');
            if (peachIndex) {
                pigs[pigIndex].health++;
                removeCard(pigIndex, peachIndex);
            }
        }
    }

    // 响应闪
    bool respondDodge(int pigIndex) {
        int dodgeIndex = findCard(pigIndex, 'D');
        if (dodgeIndex) {
            removeCard(pigIndex, dodgeIndex);
            return true;
        }
        return false;
    }

    // 响应杀
    bool respondKill(int pigIndex, int user) {
        if (pigIndex == user) {
            for (int i = 1; i <= pigs[pigIndex].cardCount; i++) {
                if (usedCards[i] != currentRound && pigs[pigIndex].cards[i] == 'K') {
                    usedCards[i] = currentRound;
                    return true;
                }
            }
            return false;
        } else {
            int killIndex = findCard(pigIndex, 'K');
            if (killIndex) {
                removeCard(pigIndex, killIndex);
                return true;
            }
            return false;
        }
    }

    // 响应无懈可击
    bool respondWuxie(int pigIndex, int user) {
        if (pigIndex == user) {
            for (int i = 1; i <= pigs[pigIndex].cardCount; i++) {
                if (usedCards[i] != currentRound && pigs[pigIndex].cards[i] == 'J') {
                    usedCards[i] = currentRound;
                    pigs[pigIndex].loyaltyStatus = 1;
                    return true;
                }
            }
            return false;
        } else {
            int wuxieIndex = findCard(pigIndex, 'J');
            if (wuxieIndex) {
                removeCard(pigIndex, wuxieIndex);
                pigs[pigIndex].loyaltyStatus = 1;
                return true;
            }
            return false;
        }
    }

    // 掉血处理
    void loseHealth(int pigIndex, int attacker) {
        pigs[pigIndex].health--;
        if (pigs[pigIndex].health < 1) {
            respondPeach(pigIndex, attacker);
        }
    }

    // 更新链表（猪死亡后）
    void updateLink(int deadPig) {
        for (int prevPig = 1; prevPig <= pigCount; prevPig++) {
            if (!pigs[prevPig].isDead && pigs[prevPig].nextPig == deadPig) {
                pigs[prevPig].nextPig = pigs[deadPig].nextPig;
                break;
            }
        }
    }

    // 使用桃
    void usePeach(int pigIndex) {
        pigs[pigIndex].health++;
    }

    // 使用杀
    void useKill(int attacker) {
        int target = pigs[attacker].nextPig;
        pigs[attacker].loyaltyStatus = 1;

        if (!respondDodge(target)) {
            loseHealth(target, attacker);
            if (pigs[target].health < 1) {
                deadRebelCount += (pigs[target].identity == 2);
                pigs[target].isDead = true;
                pigs[attacker].nextPig = pigs[target].nextPig;
            }
            if (isGameOver())
                return;
            if (pigs[target].health < 1) {
                processDeathConsequences(attacker, target);
            }
        }
    }

    // 使用无懈可击
    bool useWuxie(int user, int startPig, int targetPig, bool isCountering) {
        bool result = isCountering;
        int currentPig = startPig;

        while (true) {
            if (!pigs[currentPig].isDead) {
                if (!isCountering) {
                    if (!IDENTITY_CONFLICT[pigs[currentPig].identity][pigs[targetPig].identity]) {
                        if (respondWuxie(currentPig, user)) {
                            return useWuxie(user, currentPig, targetPig, 1 - isCountering);
                        }
                    }
                } else {
                    if (IDENTITY_CONFLICT[pigs[currentPig].identity][pigs[targetPig].identity]) {
                        if (respondWuxie(currentPig, user)) {
                            return useWuxie(user, currentPig, targetPig, 1 - isCountering);
                        }
                    }
                }
            }
            currentPig = pigs[currentPig].nextPig;
            if (currentPig == startPig)
                break;
        }
        return result;
    }

    // 使用决斗
    void useFight(int attacker, int target, int user) {
        pigs[attacker].loyaltyStatus = 1;

        if (pigs[target].loyaltyStatus == 1) {
            if (useWuxie(attacker, attacker, target, false)) {
                return;
            }
        }

        while (true) {
            if (pigs[attacker].identity == 0 && pigs[target].identity == 1) {
                // 主猪对忠猪出杀，忠猪不能出杀
                loseHealth(target, user);
                if (pigs[target].health < 1) {
                    deadRebelCount += (pigs[target].identity == 2);
                    pigs[target].isDead = true;
                    updateLink(target);
                }
                if (isGameOver())
                    return;
                if (pigs[target].health < 1) {
                    processDeathConsequences(attacker, target);
                }
                return;
            } else if (!respondKill(target, user)) {
                loseHealth(target, user);
                if (pigs[target].health < 1) {
                    deadRebelCount += (pigs[target].identity == 2);
                    pigs[target].isDead = true;
                    updateLink(target);
                }
                if (isGameOver())
                    return;
                if (pigs[target].health < 1) {
                    processDeathConsequences(attacker, target);
                }
                return;
            }

            if (!respondKill(attacker, user)) {
                loseHealth(attacker, user);
                if (pigs[attacker].health < 1) {
                    deadRebelCount += (pigs[attacker].identity == 2);
                    pigs[attacker].isDead = true;
                    updateLink(attacker);
                }
                if (isGameOver())
                    return;
                if (pigs[attacker].health < 1) {
                    processDeathConsequences(target, attacker);
                }
                return;
            }
        }
    }

    // 使用南猪入侵
    void useNanZhuInvasion(int user) {
        int currentPig = pigs[user].nextPig;
        while (currentPig != user) {
            if (!pigs[currentPig].isDead) {
                if (pigs[currentPig].loyaltyStatus == 1) {
                    if (useWuxie(user, user, currentPig, false)) {
                        currentPig = pigs[currentPig].nextPig;
                        continue;
                    }
                }

                if (!respondKill(currentPig, user)) {
                    loseHealth(currentPig, user);
                    if (currentPig == 1 && pigs[user].loyaltyStatus == 0) {
                        pigs[user].loyaltyStatus = -1;
                    }
                    if (pigs[currentPig].health < 1) {
                        deadRebelCount += (pigs[currentPig].identity == 2);
                        pigs[currentPig].isDead = true;
                        updateLink(currentPig);
                    }
                    if (isGameOver())
                        return;
                    if (pigs[currentPig].health < 1) {
                        processDeathConsequences(user, currentPig);
                    }
                }
            }
            currentPig = pigs[currentPig].nextPig;
        }
    }

    // 使用万箭齐发
    void useWanJianQiFa(int user) {
        int currentPig = pigs[user].nextPig;
        while (currentPig != user) {
            if (!pigs[currentPig].isDead) {
                if (pigs[currentPig].loyaltyStatus == 1) {
                    if (useWuxie(user, user, currentPig, false)) {
                        currentPig = pigs[currentPig].nextPig;
                        continue;
                    }
                }

                if (!respondDodge(currentPig)) {
                    loseHealth(currentPig, user);
                    if (currentPig == 1 && pigs[user].loyaltyStatus == 0) {
                        pigs[user].loyaltyStatus = -1;
                    }
                    if (pigs[currentPig].health < 1) {
                        deadRebelCount += (pigs[currentPig].identity == 2);
                        pigs[currentPig].isDead = true;
                        updateLink(currentPig);
                    }
                    if (isGameOver())
                        return;
                    if (pigs[currentPig].health < 1) {
                        processDeathConsequences(user, currentPig);
                    }
                }
            }
            currentPig = pigs[currentPig].nextPig;
        }
    }

    // 使用诸葛连弩
    void useZhugeLiannu(int user) {
        pigs[user].hasZhugeLiannu = 1;
    }

    // 判断游戏是否结束
    bool isGameOver() {
        return (rebelCount == deadRebelCount) || pigs[1].isDead;
    }

    // 出牌阶段
    bool playCards(int pigIndex) {
        memset(usedCards, 0, sizeof(usedCards));
        int killCount = 0; // 本回合使用的杀的数量
        bool gameEnded = false;

        for (currentRound = 1;; currentRound++) {
            int cardsUsedThisRound = 0;
            int remainingCardCount = 0;

            // 遍历手牌
            for (int i = 1; i <= pigs[pigIndex].cardCount; i++) {
                if (usedCards[i] != currentRound) {
                    char currentCard = pigs[pigIndex].cards[i];
                    bool cardUsed = false;

                    switch (currentCard) {
                    case 'P': // 桃
                        if (pigs[pigIndex].health < 4) {
                            usePeach(pigIndex);
                            usedCards[i] = currentRound;
                            cardsUsedThisRound++;
                            cardUsed = true;
                        }
                        break;

                    case 'K': // 杀
                        if ((killCount == 0 || pigs[pigIndex].hasZhugeLiannu) && shouldAttackNext(pigIndex)) {
                            useKill(pigIndex);
                            usedCards[i] = currentRound;
                            cardsUsedThisRound++;
                            killCount++;
                            cardUsed = true;
                        }
                        break;

                    case 'F': // 决斗
                    {
                        int target = findDuelTarget(pigIndex);
                        if (target != -1) {
                            useFight(pigIndex, target, pigIndex);
                            usedCards[i] = currentRound;
                            cardsUsedThisRound++;
                            cardUsed = true;
                        }
                    } break;

                    case 'N': // 南猪入侵
                        useNanZhuInvasion(pigIndex);
                        usedCards[i] = currentRound;
                        cardsUsedThisRound++;
                        cardUsed = true;
                        break;

                    case 'W': // 万箭齐发
                        useWanJianQiFa(pigIndex);
                        usedCards[i] = currentRound;
                        cardsUsedThisRound++;
                        cardUsed = true;
                        break;

                    case 'Z': // 诸葛连弩
                        useZhugeLiannu(pigIndex);
                        usedCards[i] = currentRound;
                        cardsUsedThisRound++;
                        cardUsed = true;
                        break;
                    }

                    if (cardUsed) {
                        i = pigs[pigIndex].cardCount; // 跳出当前循环
                        if (isGameOver()) {
                            gameEnded = true;
                            break;
                        }
                        if (pigs[pigIndex].isDead) {
                            return false;
                        }
                    }
                }
            }

            // 清理使用过的牌
            for (int i = 1; i <= pigs[pigIndex].cardCount; i++) {
                if (usedCards[i] != currentRound) {
                    tempCards[++remainingCardCount] = pigs[pigIndex].cards[i];
                }
            }

            // 更新手牌
            for (int i = 1; i <= remainingCardCount; i++) {
                pigs[pigIndex].cards[i] = tempCards[i];
            }
            pigs[pigIndex].cardCount = remainingCardCount;

            // 判断是否结束出牌
            if (gameEnded)
                return true;
            if (cardsUsedThisRound == 0)
                return false;
        }
    }

    // 一个完整的回合
    bool playTurn(int pigIndex) {
        drawCard(pigIndex);
        drawCard(pigIndex);
        return playCards(pigIndex);
    }

    // 游戏主循环
    void playGame() {
        bool gameEnded = false;
        for (int currentPig = 1; !gameEnded && rebelCount > 0; currentPig = pigs[currentPig].nextPig) {
            if (!pigs[currentPig].isDead) {
                gameEnded = playTurn(currentPig);
            }
        }
    }

    // 输出结果
    void printResult() {
        printf("%s\n", pigs[1].isDead ? "FP" : "MP");
        for (int i = 1; i <= pigCount; i++) {
            if (pigs[i].isDead) {
                printf("DEAD\n");
            } else {
                if (pigs[i].cardCount > 0) {
                    printf("%c", pigs[i].cards[1]);
                    for (int j = 2; j <= pigs[i].cardCount; j++) {
                        printf(" %c", pigs[i].cards[j]);
                    }
                }
                printf("\n");
            }
        }
    }
};

int main() {

    PigKillGame game;
    game.initialize();
    game.playGame();
    game.printResult();

    return 0;
}