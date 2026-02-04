import pygame
import random
import sys

# 初始化pygame
pygame.init()

# 游戏窗口设置
WIDTH, HEIGHT = 800, 600
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("太空射击游戏")

# 颜色定义
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
RED = (255, 50, 50)
GREEN = (50, 255, 100)
BLUE = (50, 100, 255)
YELLOW = (255, 255, 50)
PURPLE = (180, 70, 220)

# 玩家类
class Player:
    def __init__(self):
        self.width = 50
        self.height = 40
        self.x = WIDTH // 2
        self.y = HEIGHT - 100
        self.speed = 7
        self.color = BLUE
        self.health = 100
        self.score = 0
        
    def draw(self):
        # 绘制飞船主体
        pygame.draw.polygon(screen, self.color, [
            (self.x, self.y - self.height//2),
            (self.x - self.width//2, self.y + self.height//2),
            (self.x + self.width//2, self.y + self.height//2)
        ])
        
        # 绘制飞船尾部火焰
        flame_height = random.randint(5, 15)
        pygame.draw.polygon(screen, YELLOW, [
            (self.x - 10, self.y + self.height//2),
            (self.x, self.y + self.height//2 + flame_height),
            (self.x + 10, self.y + self.height//2)
        ])
        
        # 绘制生命条
        pygame.draw.rect(screen, RED, (self.x - 25, self.y - 60, 50, 8))
        pygame.draw.rect(screen, GREEN, (self.x - 25, self.y - 60, self.health//2, 8))
        
    def move(self, keys):
        if keys[pygame.K_LEFT] and self.x > self.width//2:
            self.x -= self.speed
        if keys[pygame.K_RIGHT] and self.x < WIDTH - self.width//2:
            self.x += self.speed
        if keys[pygame.K_UP] and self.y > 100:
            self.y -= self.speed
        if keys[pygame.K_DOWN] and self.y < HEIGHT - self.height//2:
            self.y += self.speed
            
    def get_rect(self):
        return pygame.Rect(self.x - self.width//2, self.y - self.height//2, self.width, self.height)

# 子弹类
class Bullet:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.radius = 5
        self.speed = 10
        self.color = GREEN
        
    def draw(self):
        pygame.draw.circle(screen, self.color, (self.x, self.y), self.radius)
        
    def move(self):
        self.y -= self.speed
        
    def is_off_screen(self):
        return self.y < 0
        
    def get_rect(self):
        return pygame.Rect(self.x - self.radius, self.y - self.radius, self.radius*2, self.radius*2)

# 敌人类
class Enemy:
    def __init__(self):
        self.size = random.randint(20, 40)
        self.x = random.randint(self.size, WIDTH - self.size)
        self.y = random.randint(-100, -self.size)
        self.speed = random.uniform(1.0, 3.0)
        self.color = random.choice([RED, PURPLE, (255, 150, 50)])
        
    def draw(self):
        pygame.draw.circle(screen, self.color, (self.x, self.y), self.size)
        
        # 绘制敌人的"眼睛"
        pygame.draw.circle(screen, BLACK, (self.x - self.size//3, self.y - self.size//4), self.size//5)
        pygame.draw.circle(screen, BLACK, (self.x + self.size//3, self.y - self.size//4), self.size//5)
        
    def move(self):
        self.y += self.speed
        
    def is_off_screen(self):
        return self.y > HEIGHT + self.size
        
    def get_rect(self):
        return pygame.Rect(self.x - self.size, self.y - self.size, self.size*2, self.size*2)

# 爆炸效果类
class Explosion:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.radius = 5
        self.max_radius = 30
        self.growth_rate = 2
        self.color = YELLOW
        self.active = True
        
    def draw(self):
        pygame.draw.circle(screen, self.color, (self.x, self.y), self.radius, 2)
        
    def update(self):
        self.radius += self.growth_rate
        if self.radius >= self.max_radius:
            self.active = False

# 游戏初始化
player = Player()
bullets = []
enemies = []
explosions = []
enemy_spawn_timer = 0
bullet_cooldown = 0
game_over = False
clock = pygame.time.Clock()
font = pygame.font.SysFont(None, 36)

# 游戏主循环
running = True
while running:
    # 处理事件
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_SPACE and not game_over:
                if bullet_cooldown == 0:
                    bullets.append(Bullet(player.x, player.y - player.height//2))
                    bullet_cooldown = 10  # 子弹冷却时间
            if event.key == pygame.K_r and game_over:
                # 重新开始游戏
                player = Player()
                bullets = []
                enemies = []
                explosions = []
                enemy_spawn_timer = 0
                bullet_cooldown = 0
                game_over = False
    
    if not game_over:
        # 获取按键状态
        keys = pygame.key.get_pressed()
        
        # 更新玩家位置
        player.move(keys)
        
        # 更新子弹冷却时间
        if bullet_cooldown > 0:
            bullet_cooldown -= 1
            
        # 生成敌人
        enemy_spawn_timer += 1
        if enemy_spawn_timer >= 30:  # 每30帧生成一个敌人
            enemies.append(Enemy())
            enemy_spawn_timer = 0
            
        # 更新子弹
        for bullet in bullets[:]:
            bullet.move()
            if bullet.is_off_screen():
                bullets.remove(bullet)
                
        # 更新敌人
        for enemy in enemies[:]:
            enemy.move()
            if enemy.is_off_screen():
                enemies.remove(enemy)
                
        # 检查子弹和敌人的碰撞
        for bullet in bullets[:]:
            for enemy in enemies[:]:
                if bullet.get_rect().colliderect(enemy.get_rect()):
                    explosions.append(Explosion(enemy.x, enemy.y))
                    player.score += 10
                    if bullet in bullets:
                        bullets.remove(bullet)
                    if enemy in enemies:
                        enemies.remove(enemy)
                        
        # 检查玩家和敌人的碰撞
        for enemy in enemies[:]:
            if player.get_rect().colliderect(enemy.get_rect()):
                explosions.append(Explosion(enemy.x, enemy.y))
                player.health -= 20
                if enemy in enemies:
                    enemies.remove(enemy)
                if player.health <= 0:
                    game_over = True
                    
        # 更新爆炸效果
        for explosion in explosions[:]:
            explosion.update()
            if not explosion.active:
                explosions.remove(explosion)
    
    # 绘制背景
    screen.fill(BLACK)
    
    # 绘制星空背景
    for _ in range(50):
        x = random.randint(0, WIDTH)
        y = random.randint(0, HEIGHT)
        size = random.randint(1, 3)
        brightness = random.randint(150, 255)
        pygame.draw.circle(screen, (brightness, brightness, brightness), (x, y), size)
    
    # 绘制游戏对象
    player.draw()
    
    for bullet in bullets:
        bullet.draw()
        
    for enemy in enemies:
        enemy.draw()
        
    for explosion in explosions:
        explosion.draw()
    
    # 绘制分数和生命值
    score_text = font.render(f"分数: {player.score}", True, GREEN)
    health_text = font.render(f"生命值: {player.health}", True, GREEN)
    screen.blit(score_text, (10, 10))
    screen.blit(health_text, (10, 50))
    
    # 绘制游戏说明
    controls_text = font.render("方向键移动, 空格键射击, R键重新开始", True, WHITE)
    screen.blit(controls_text, (WIDTH//2 - controls_text.get_width()//2, HEIGHT - 40))
    
    # 绘制游戏结束画面
    if game_over:
        game_over_text = font.render("游戏结束!", True, RED)
        restart_text = font.render("按R键重新开始", True, YELLOW)
        screen.blit(game_over_text, (WIDTH//2 - game_over_text.get_width()//2, HEIGHT//2 - 50))
        screen.blit(restart_text, (WIDTH//2 - restart_text.get_width()//2, HEIGHT//2))
    
    # 更新显示
    pygame.display.flip()
    
    # 控制帧率
    clock.tick(60)
 
# 退出游戏
pygame.quit()
sys.exit()