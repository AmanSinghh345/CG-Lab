#include <graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>

// Player structure
struct Player {
    int x, y;
    int speed;
    int health;
    int score;
};

// Enemy structure
struct Enemy {
    int x, y;
    int speed;
    int active;
};

// Road barrier structure
struct Barrier {
    int x, y;
    int active;
};

// Game variables
Player player;
Enemy enemies[3];
Barrier barriers[5];
int gameRunning = 1;
int gameScore = 0;

// Initialize game
void init() {
    player.x = 300;
    player.y = 350;
    player.speed = 5;
    player.health = 100;
    player.score = 0;
    
    srand(time(0));
    
    // Initialize enemies
    for(int i = 0; i < 3; i++) {
        enemies[i].x = 150 + i * 100;
        enemies[i].y = -50 - i * 100;
        enemies[i].speed = 2 + rand() % 3;
        enemies[i].active = 1;
    }
    
    // Initialize barriers
    for(int i = 0; i < 5; i++) {
        barriers[i].x = 100 + rand() % 400;
        barriers[i].y = -100 - i * 150;
        barriers[i].active = 1;
    }
}

// Draw road
void drawRoad() {
    // Road background
    setfillstyle(SOLID_FILL, BROWN);
    bar(0, 0, 640, 480);
    
    // Road lanes
    setcolor(YELLOW);
    setlinestyle(DASHED_LINE, 0, 1);
    for(int i = 0; i < 480; i += 30) {
        line(150, i, 150, i + 15);
        line(320, i, 320, i + 15);
        line(490, i, 490, i + 15);
    }
}

// Draw player bike
void drawPlayer() {
    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    
    // Bike body (rectangle)
    rectangle(player.x - 15, player.y - 10, player.x + 15, player.y + 10);
    fillpoly(4, (int[]){player.x - 15, player.y - 10, player.x + 15, player.y - 10, 
                         player.x + 10, player.y, player.x - 10, player.y});
    
    // Wheels
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    circle(player.x - 10, player.y + 12, 5);
    circle(player.x + 10, player.y + 12, 5);
}

// Draw enemy bike
void drawEnemy(int i) {
    if(!enemies[i].active) return;
    
    setcolor(BLUE);
    setfillstyle(SOLID_FILL, BLUE);
    
    // Bike body
    rectangle(enemies[i].x - 12, enemies[i].y - 8, enemies[i].x + 12, enemies[i].y + 8);
    fillpoly(4, (int[]){enemies[i].x - 12, enemies[i].y - 8, enemies[i].x + 12, enemies[i].y - 8,
                         enemies[i].x + 8, enemies[i].y, enemies[i].x - 8, enemies[i].y});
    
    // Wheels
    setcolor(BLACK);
    circle(enemies[i].x - 8, enemies[i].y + 10, 4);
    circle(enemies[i].x + 8, enemies[i].y + 10, 4);
}

// Draw obstacles
void drawBarriers() {
    for(int i = 0; i < 5; i++) {
        if(!barriers[i].active) continue;
        
        setcolor(YELLOW);
        setfillstyle(SOLID_FILL, YELLOW);
        rectangle(barriers[i].x - 20, barriers[i].y - 8, barriers[i].x + 20, barriers[i].y + 8);
    }
}

// Update player position
void updatePlayer() {
    if(kbhit()) {
        int key = getch();
        
        if(key == 75) { // Left arrow
            if(player.x > 130) player.x -= player.speed;
        }
        if(key == 77) { // Right arrow
            if(player.x < 510) player.x += player.speed;
        }
        if(key == 72) { // Up arrow
            player.speed = 7;
        }
        else if(key == 80) { // Down arrow
            player.speed = 3;
        }
        if(key == 27) { // ESC
            gameRunning = 0;
        }
    }
}

// Update enemies
void updateEnemies() {
    for(int i = 0; i < 3; i++) {
        enemies[i].y += enemies[i].speed;
        
        // Wrap around
        if(enemies[i].y > 480) {
            enemies[i].y = -50;
            enemies[i].x = 150 + rand() % 200;
            player.score += 10;
        }
    }
}

// Update barriers
void updateBarriers() {
    for(int i = 0; i < 5; i++) {
        if(!barriers[i].active) continue;
        
        barriers[i].y += 4;
        
        if(barriers[i].y > 480) {
            barriers[i].y = -50;
            barriers[i].x = 100 + rand() % 400;
        }
    }
}

// Check collisions
void checkCollisions() {
    // Player vs Enemies
    for(int i = 0; i < 3; i++) {
        if(enemies[i].active) {
            int dx = player.x - enemies[i].x;
            int dy = player.y - enemies[i].y;
            
            if(dx * dx + dy * dy < 400) {
                player.health -= 10;
                player.score -= 5;
                if(player.health <= 0) gameRunning = 0;
                enemies[i].x = 150 + rand() % 200;
                enemies[i].y = -50;
            }
        }
    }
    
    // Player vs Barriers
    for(int i = 0; i < 5; i++) {
        if(barriers[i].active) {
            int dx = player.x - barriers[i].x;
            int dy = player.y - barriers[i].y;
            
            if(dx * dx + dy * dy < 900) {
                player.health -= 15;
                player.score -= 10;
                if(player.health <= 0) gameRunning = 0;
                barriers[i].y = -100;
            }
        }
    }
}

// Draw HUD (Heads-Up Display)
void drawHUD() {
    setcolor(WHITE);
    char buffer[50];
    
    sprintf(buffer, "Health: %d", player.health);
    outtextxy(10, 10, buffer);
    
    sprintf(buffer, "Score: %d", player.score);
    outtextxy(10, 30, buffer);
    
    sprintf(buffer, "Speed: %d", player.speed);
    outtextxy(10, 50, buffer);
}

// Game Over screen
void gameOver() {
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, BLACK);
    bar(150, 150, 490, 330);
    
    rectangle(150, 150, 490, 330);
    
    setcolor(RED);
    outtextxy(220, 170, "GAME OVER");
    
    char buffer[50];
    sprintf(buffer, "Final Score: %d", player.score);
    outtextxy(190, 220, buffer);
    
    setcolor(WHITE);
    outtextxy(160, 270, "Press any key to exit...");
    
    getch();
}

// Main game loop
void gameLoop() {
    while(gameRunning) {
        cleardevice();
        
        drawRoad();
        updatePlayer();
        updateEnemies();
        updateBarriers();
        checkCollisions();
        
        drawPlayer();
        for(int i = 0; i < 3; i++) {
            drawEnemy(i);
        }
        drawBarriers();
        drawHUD();
        
        delay(50);
    }
}

// Main function
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    
    init();
    gameLoop();
    gameOver();
    
    closegraph();
    return 0;
}
