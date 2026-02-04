import random
import os
class GuessNumberGame:
    def __init__(self):
        self.target_number = 0
        self.attempts = 0
        self.max_attempts = 10
        self.game_over = False
        self.best_score = None
        
    def start_game(self):
        """开始新游戏"""
        self.target_number = random.randint(1, 100)
        self.attempts = 0
        self.game_over = False
        print("\n" + "="*50)
        print("欢迎来到猜数字游戏！")
        print("我已经想好了一个1到100之间的整数。")
        print(f"你有{self.max_attempts}次机会猜出这个数字。")
        print("="*50)
        
        # 显示最佳记录（如果有）
        if self.best_score:
            print(f"当前最佳记录: {self.best_score}次猜中")
        
        self.play_round()
    
    def play_round(self):
        """进行游戏回合"""
        while not self.game_over and self.attempts < self.max_attempts:
            remaining = self.max_attempts - self.attempts
            print(f"\n你还剩{remaining}次机会。")
            
            # 获取玩家输入
            guess = self.get_player_guess()
            
            if guess is None:
                continue  # 输入无效，重新尝试
            
            self.attempts += 1
            
            # 检查猜测结果
            self.check_guess(guess)
        
        # 游戏结束，询问是否再玩一次
        if self.game_over:
            self.ask_replay()
        else:
            print(f"\n很遗憾，你没有在{self.max_attempts}次内猜中数字。")
            print(f"正确答案是: {self.target_number}")
            self.ask_replay()
    
    def get_player_guess(self):
        """获取玩家输入的数字"""
        try:
            guess = int(input("请输入你猜的数字 (1-100): "))
            
            if guess < 1 or guess > 100:
                print("请输入1到100之间的数字！")
                return None
                
            return guess
        except ValueError:
            print("请输入有效的数字！")
            return None
    
    def check_guess(self, guess):
        """检查猜测的数字是否正确"""
        if guess == self.target_number:
            print(f"\n恭喜！你猜对了！数字就是{self.target_number}。")
            print(f"你用了{self.attempts}次猜中。")
            
            # 更新最佳记录
            if self.best_score is None or self.attempts < self.best_score:
                self.best_score = self.attempts
                print(f"🎉 新记录！最佳记录现在是{self.best_score}次！")
            
            self.game_over = True
        elif guess < self.target_number:
            # 提供线索
            if self.target_number - guess <= 5:
                print("接近了！但猜的数字偏小一点。")
            elif self.target_number - guess <= 10:
                print("有点接近，但还是偏小。")
            else:
                print("猜的数字太小了。")
        else:
            # 提供线索
            if guess - self.target_number <= 5:
                print("接近了！但猜的数字偏大一点。")
            elif guess - self.target_number <= 10:
                print("有点接近，但还是偏大。")
            else:
                print("猜的数字太大了。")
    
    def ask_replay(self):
        """询问是否再玩一次"""
        print("\n" + "-"*50)
        choice = input("想再玩一次吗？(输入 y 继续，其他键退出): ").lower()
        
        if choice == 'y' or choice == 'yes':
            self.start_game()
        else:
            print("\n感谢游玩！再见！")
            if self.best_score:
                print(f"你的最佳记录是: {self.best_score}次猜中")

def show_instructions():
    """显示游戏说明"""
    print("="*60)
    print("猜数字游戏 - 说明")
    print("="*60)
    print("1. 计算机会随机生成一个1到100之间的整数")
    print("2. 你有10次机会猜出这个数字")
    print("3. 每次猜测后，计算机会告诉你猜的数字是太大、太小还是正确")
    print("4. 游戏会根据你离目标数字的远近给出提示")
    print("5. 尝试用最少的次数猜中数字，创造最佳记录！")
    print("="*60)
    input("按回车键开始游戏...")

def main():
    """主函数"""
    os.system('chcp 65001')  # 设置编码为UTF-8
    print("欢迎来到Python猜数字游戏！")
    
    # 显示说明
    show_instructions()
    
    # 创建游戏实例并开始游戏
    game = GuessNumberGame()
    game.start_game()

if __name__ == "__main__":
    main()