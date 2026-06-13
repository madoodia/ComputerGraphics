#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <random>
#include <chrono>
#include <thread>

using namespace std;

// Constants
const int BOARD_WIDTH = 10;
const int BOARD_HEIGHT = 20;

const int BOARD_LEFT = 4;
const int BOARD_TOP = 4;
const int CELL_SIZE = 2;
const int SCREEN_WIDTH = BOARD_WIDTH * CELL_SIZE + BOARD_LEFT * 2 + 20;
const int SCREEN_HEIGHT = BOARD_HEIGHT + BOARD_TOP * 2;

// Tetromino shapes (4x4 grids)
const vector<vector<vector<int>>> SHAPES = {
    // I
    {{0, 0, 0, 0},
     {1, 1, 1, 1},
     {0, 0, 0, 0},
     {0, 0, 0, 0}},
    // O
    {{0, 0, 0, 0},
     {0, 1, 1, 0},
     {0, 1, 1, 0},
     {0, 0, 0, 0}},
    // T
    {{0, 0, 0, 0},
     {0, 1, 0, 0},
     {1, 1, 1, 0},
     {0, 0, 0, 0}},
    // S
    {{0, 0, 0, 0},
     {0, 1, 1, 0},
     {1, 1, 0, 0},
     {0, 0, 0, 0}},
    // Z
    {{0, 0, 0, 0},
     {1, 1, 0, 0},
     {0, 1, 1, 0},
     {0, 0, 0, 0}},
    // J
    {{0, 0, 0, 0},
     {1, 0, 0, 0},
     {1, 1, 1, 0},
     {0, 0, 0, 0}},
    // L
    {{0, 0, 0, 0},
     {0, 0, 1, 0},
     {1, 1, 1, 0},
     {0, 0, 0, 0}}
};

const int NUM_SHAPES = SHAPES.size();

// Colors for each piece type (using color codes that can be mapped to console)
const int PIECE_COLORS[] = {11, 14, 13, 10, 12, 9, 6}; // Cyan, Yellow, Magenta, Green, Red, Blue, Orange

// Enum for game state
enum GameState
{
    PLAYING,
    GAME_OVER,
    PAUSED
};

// Structure for a piece
struct Piece
{
    int type;
    int rotation;
    int x, y;
};

// Function to set console cursor position
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Function to set console text color
void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Hide cursor
void hideCursor()
{
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

// Random number generator
int randomInt(int min, int max)
{
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}

// Rotate a shape 90 degrees clockwise
vector<vector<int>> rotateShape(const vector<vector<int>>& shape)
{
    int n = shape.size();
    vector<vector<int>> rotated(n, vector<int>(n, 0));
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            rotated[x][n - 1 - y] = shape[y][x];
        }
    }
    return rotated;
}

// Tetris Game class
class Tetris
{
private:
    vector<vector<int>> board;
    vector<vector<int>> boardColors;
    Piece currentPiece;
    Piece nextPiece;
    int score;
    int level;
    int linesCleared;
    GameState state;
    int fallDelay;
    chrono::steady_clock::time_point lastFallTime;
    int holdPiece;
    bool canHold;

    // Initialize board
    void initBoard()
    {
        board.assign(BOARD_HEIGHT, vector<int>(BOARD_WIDTH, 0));
        boardColors.assign(BOARD_HEIGHT, vector<int>(BOARD_WIDTH, 0));
    }

    // Spawn a new piece
    void spawnPiece()
    {
        currentPiece = nextPiece;
        currentPiece.x = BOARD_WIDTH / 2 - 2;
        currentPiece.y = 0;

        // Generate next piece
        nextPiece.type = randomInt(0, NUM_SHAPES - 1);
        nextPiece.rotation = 0;
        nextPiece.x = 0;
        nextPiece.y = 0;

        canHold = true;

        // Check if game over
        if (!isValidPosition(currentPiece))
        {
            state = GAME_OVER;
        }
    }

    // Get shape for a piece
    vector<vector<int>> getShape(int type, int rotation) const
    {
        vector<vector<int>> shape = SHAPES[type];
        for (int r = 0; r < rotation; r++)
        {
            shape = rotateShape(shape);
        }
        return shape;
    }

    // Check if piece position is valid
    bool isValidPosition(const Piece& piece) const
    {
        auto shape = getShape(piece.type, piece.rotation);
        for (int y = 0; y < 4; y++)
        {
            for (int x = 0; x < 4; x++)
            {
                if (shape[y][x])
                {
                    int bx = piece.x + x;
                    int by = piece.y + y;
                    if (bx < 0 || bx >= BOARD_WIDTH || by >= BOARD_HEIGHT || by < 0)
                    {
                        return false;
                    }
                    if (by >= 0 && board[by][bx])
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    // Lock piece on board
    void lockPiece()
    {
        auto shape = getShape(currentPiece.type, currentPiece.rotation);
        for (int y = 0; y < 4; y++)
        {
            for (int x = 0; x < 4; x++)
            {
                if (shape[y][x])
                {
                    int bx = currentPiece.x + x;
                    int by = currentPiece.y + y;
                    if (by >= 0 && by < BOARD_HEIGHT && bx >= 0 && bx < BOARD_WIDTH)
                    {
                        board[by][bx] = currentPiece.type + 1;
                        boardColors[by][bx] = PIECE_COLORS[currentPiece.type];
                    }
                }
            }
        }
        clearLines();
        spawnPiece();
    }

    // Clear completed lines
    void clearLines()
    {
        int cleared = 0;
        for (int y = BOARD_HEIGHT - 1; y >= 0; y--)
        {
            bool full = true;
            for (int x = 0; x < BOARD_WIDTH; x++)
            {
                if (board[y][x] == 0)
                {
                    full = false;
                    break;
                }
            }
            if (full)
            {
                // Remove line
                board.erase(board.begin() + y);
                boardColors.erase(boardColors.begin() + y);
                board.insert(board.begin(), vector<int>(BOARD_WIDTH, 0));
                boardColors.insert(boardColors.begin(), vector<int>(BOARD_WIDTH, 0));
                cleared++;
                y++; // Re-check this row
            }
        }

        if (cleared > 0)
        {
            linesCleared += cleared;
            // Scoring
            int points[] = {0, 100, 300, 500, 800};
            score += points[cleared] * level;
            level = linesCleared / 10 + 1;
            fallDelay = max(50, 500 - (level - 1) * 30);
        }
    }

    // Move piece
    bool movePiece(int dx, int dy)
    {
        Piece newPiece = currentPiece;
        newPiece.x += dx;
        newPiece.y += dy;
        if (isValidPosition(newPiece))
        {
            currentPiece = newPiece;
            return true;
        }
        if (dy > 0)
        {
            lockPiece();
        }
        return false;
    }

    // Rotate piece
    void rotatePiece()
    {
        Piece newPiece = currentPiece;
        newPiece.rotation = (newPiece.rotation + 1) % 4;

        // Try basic rotation
        if (isValidPosition(newPiece))
        {
            currentPiece = newPiece;
            return;
        }

        // Wall kick - try shifting left/right
        for (int kick : {-1, 1, -2, 2})
        {
            newPiece.x = currentPiece.x + kick;
            if (isValidPosition(newPiece))
            {
                currentPiece = newPiece;
                return;
            }
        }
    }

    // Hard drop
    void hardDrop()
    {
        while (isValidPosition(currentPiece))
        {
            currentPiece.y++;
        }
        currentPiece.y--;
        lockPiece();
    }

    // Hold piece
    void holdCurrentPiece()
    {
        if (!canHold)
            return;
        canHold = false;

        if (holdPiece == -1)
        {
            holdPiece = currentPiece.type;
            spawnPiece();
        } else
        {
            int temp = currentPiece.type;
            currentPiece.type = holdPiece;
            currentPiece.rotation = 0;
            currentPiece.x = BOARD_WIDTH / 2 - 2;
            currentPiece.y = 0;
            holdPiece = temp;
        }
    }

    // Draw the game
    void draw()
    {
        // Draw border
        gotoxy(BOARD_LEFT - 2, BOARD_TOP - 1);
        setColor(15); // White
        cout << "+";
        for (int x = 0; x < BOARD_WIDTH * CELL_SIZE; x++)
            cout << "-";
        cout << "+";

        for (int y = 0; y < BOARD_HEIGHT; y++)
        {
            gotoxy(BOARD_LEFT - 2, BOARD_TOP + y);
            cout << "|";
            gotoxy(BOARD_LEFT + BOARD_WIDTH * CELL_SIZE, BOARD_TOP + y);
            cout << "|";
        }

        gotoxy(BOARD_LEFT - 2, BOARD_TOP + BOARD_HEIGHT);
        cout << "+";
        for (int x = 0; x < BOARD_WIDTH * CELL_SIZE; x++)
            cout << "-";
        cout << "+";

        // Draw board
        for (int y = 0; y < BOARD_HEIGHT; y++)
        {
            gotoxy(BOARD_LEFT, BOARD_TOP + y);
            for (int x = 0; x < BOARD_WIDTH; x++)
            {
                if (board[y][x])
                {
                    setColor(boardColors[y][x]);
                    cout << "[]";
                } else
                {
                    setColor(8); // Gray
                    cout << ". ";
                }
            }
        }

        // Draw current piece (ghost + solid)
        auto shape = getShape(currentPiece.type, currentPiece.rotation);

        // Draw ghost piece
        Piece ghost = currentPiece;
        while (isValidPosition(ghost))
            ghost.y++;
        ghost.y--;

        for (int y = 0; y < 4; y++)
        {
            for (int x = 0; x < 4; x++)
            {
                if (shape[y][x])
                {
                    int bx = ghost.x + x;
                    int by = ghost.y + y;
                    if (by >= 0 && by < BOARD_HEIGHT && bx >= 0 && bx < BOARD_WIDTH)
                    {
                        gotoxy(BOARD_LEFT + bx * CELL_SIZE, BOARD_TOP + by);
                        setColor(8); // Dark gray for ghost
                        cout << "##";
                    }
                }
            }
        }

        // Draw current piece
        for (int y = 0; y < 4; y++)
        {
            for (int x = 0; x < 4; x++)
            {
                if (shape[y][x])
                {
                    int bx = currentPiece.x + x;
                    int by = currentPiece.y + y;
                    if (by >= 0 && by < BOARD_HEIGHT && bx >= 0 && bx < BOARD_WIDTH)
                    {
                        gotoxy(BOARD_LEFT + bx * CELL_SIZE, BOARD_TOP + by);
                        setColor(PIECE_COLORS[currentPiece.type]);
                        cout << "[]";
                    }
                }
            }
        }

        // Draw next piece preview
        int previewX = BOARD_LEFT + BOARD_WIDTH * CELL_SIZE + 6;
        int previewY = BOARD_TOP + 2;
        gotoxy(previewX, previewY - 2);
        setColor(15);
        cout << "NEXT:";

        auto nextShape = getShape(nextPiece.type, 0);
        for (int y = 0; y < 4; y++)
        {
            gotoxy(previewX, previewY + y);
            for (int x = 0; x < 4; x++)
            {
                if (nextShape[y][x])
                {
                    setColor(PIECE_COLORS[nextPiece.type]);
                    cout << "[]";
                } else
                {
                    cout << "  ";
                }
            }
        }

        // Draw hold piece
        int holdX = BOARD_LEFT - 14;
        int holdY = BOARD_TOP + 2;
        gotoxy(holdX, holdY - 2);
        setColor(15);
        cout << "HOLD:";

        if (holdPiece != -1)
        {
            auto holdShape = getShape(holdPiece, 0);
            for (int y = 0; y < 4; y++)
            {
                gotoxy(holdX, holdY + y);
                for (int x = 0; x < 4; x++)
                {
                    if (holdShape[y][x])
                    {
                        setColor(PIECE_COLORS[holdPiece]);
                        cout << "[]";
                    } else
                    {
                        cout << "  ";
                    }
                }
            }
        }

        // Draw score info
        int infoX = BOARD_LEFT + BOARD_WIDTH * CELL_SIZE + 6;
        gotoxy(infoX, BOARD_TOP + 8);
        setColor(15);
        cout << "SCORE:" << endl;
        gotoxy(infoX, BOARD_TOP + 9);
        cout << score << endl;
        gotoxy(infoX, BOARD_TOP + 11);
        cout << "LEVEL:" << endl;
        gotoxy(infoX, BOARD_TOP + 12);
        cout << level << endl;
        gotoxy(infoX, BOARD_TOP + 14);
        cout << "LINES:" << endl;
        gotoxy(infoX, BOARD_TOP + 15);
        cout << linesCleared << endl;

        // Game over message
        if (state == GAME_OVER)
        {
            gotoxy(BOARD_LEFT + 2, BOARD_TOP + BOARD_HEIGHT / 2 - 1);
            setColor(12); // Red
            cout << "GAME OVER!";
            gotoxy(BOARD_LEFT + 1, BOARD_TOP + BOARD_HEIGHT / 2 + 1);
            setColor(15);
            cout << "Press R to restart";
        }
    }

public:
    Tetris() : score(0), level(1), linesCleared(0), state(PLAYING), fallDelay(500), holdPiece(-1), canHold(true)
    {
        initBoard();

        // Initialize first piece
        nextPiece.type = randomInt(0, NUM_SHAPES - 1);
        nextPiece.rotation = 0;

        spawnPiece();
        lastFallTime = chrono::steady_clock::now();
    }

    // Handle input
    void handleInput()
    {
        if (_kbhit())
        {
            int key = _getch();
            if (key == 224)
            { // Arrow keys
                key = _getch();
                if (state == PLAYING)
                {
                    switch (key)
                    {
                        case 75:
                            movePiece(-1, 0);
                            break; // Left
                        case 77:
                            movePiece(1, 0);
                            break; // Right
                        case 80:
                            movePiece(0, 1);
                            break; // Down
                        case 72:
                            rotatePiece();
                            break; // Up
                    }
                }
            } else
            {
                switch (key)
                {
                    case ' ': // Space - hard drop
                        if (state == PLAYING)
                            hardDrop();
                        break;
                    case 'p':
                    case 'P':
                        if (state == PLAYING)
                            state = PAUSED;
                        else if (state == PAUSED)
                            state = PLAYING;
                        break;
                    case 'c':
                    case 'C':
                        if (state == PLAYING)
                            holdCurrentPiece();
                        break;
                    case 'r':
                    case 'R':
                        if (state == GAME_OVER)
                            reset();
                        break;
                    case 27: // ESC
                        exit(0);
                }
            }
        }
    }

    // Update game logic
    void update()
    {
        if (state != PLAYING)
            return;

        auto now = chrono::steady_clock::now();
        auto elapsed = chrono::duration_cast<chrono::milliseconds>(now - lastFallTime).count();

        if (elapsed >= fallDelay)
        {
            movePiece(0, 1);
            lastFallTime = now;
        }
    }

    // Render
    void render()
    {
        system("cls");
        draw();

        // Controls
        gotoxy(0, SCREEN_HEIGHT + 1);
        setColor(15);
        cout << "CONTROLS:";
        gotoxy(0, SCREEN_HEIGHT + 2);
        cout << "Arrows: Move/Rotate   Space: Hard Drop";
        gotoxy(0, SCREEN_HEIGHT + 3);
        cout << "C: Hold   P: Pause   ESC: Exit";
    }

    // Reset game
    void reset()
    {
        initBoard();
        score = 0;
        level = 1;
        linesCleared = 0;
        state = PLAYING;
        fallDelay = 500;
        holdPiece = -1;
        canHold = true;
        nextPiece.type = randomInt(0, NUM_SHAPES - 1);
        nextPiece.rotation = 0;
        spawnPiece();
        lastFallTime = chrono::steady_clock::now();
    }

    // Check if game is over
    bool isGameOver() const { return state == GAME_OVER; }
};

// Main function
int main()
{
    // Set console title
    SetConsoleTitle(TEXT("Tetris"));

    // Set console window size
    system("mode con cols=60 lines=32");

    hideCursor();

    Tetris game;

    // Main game loop
    while (true)
    {
        game.handleInput();
        game.update();
        game.render();
        this_thread::sleep_for(chrono::milliseconds(50));
    }

    return 0;
}
