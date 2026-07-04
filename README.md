# 🎮 TIC-TAC-TOE in C

A fully-featured **two-player and single-player Tic-Tac-Toe game** built in C language. This is my first C project, developed to strengthen my understanding of programming fundamentals and hands-on experience with Git and GitHub.

---

## 📌 Features

- 🆚 **Player vs Player** — Two human players on the same machine
- 🤖 **Player vs Computer** — Play against a Smart AI computer
- 👤 **Custom Player Names** — Enter your own name before the game starts
- ✏️ **Symbol Selection** — Player 1 chooses X or O; Player 2 gets the opposite automatically
- ⚡ **X Always Goes First** — No matter who picks X, X always plays first
- 🏆 **Win Detection** — Checks all 8 winning combinations (rows, columns, diagonals)
- 🤝 **Draw Detection** — Detects when all 9 cells are filled with no winner
- 📊 **Scoreboard** — Tracks wins, losses, and draws across multiple games
- 🔁 **Play Again Option** — Replay without restarting the program
- 🥇 **Overall Winner** — Announces the overall winner after all rounds
- 🔄 **New Game Option** — Start a completely fresh game after final score
- ✅ **Input Validation** — Handles invalid input (characters, out-of-range numbers)
- 🖥️ **Cross-Platform** — Works on Windows, Linux, and macOS

---

## 🤖 Smart AI Logic

The computer follows a priority-based strategy:

| Priority | Action |
|----------|--------|
| 1st | Win if possible |
| 2nd | Block player from winning |
| 3rd | Take center cell |
| 4th | Play a random empty cell |

---

## 🛠️ How to Compile and Run

### On Windows:
```bash
gcc TIC-TAC-TOE.c -o TIC-TAC-TOE
.\TIC-TAC-TOE
```

### On Linux / macOS:
```bash
gcc TIC-TAC-TOE.c -o TIC-TAC-TOE
./TIC-TAC-TOE
```

> Make sure you have **GCC** installed on your system.

---

## 🎮 How to Play

1. Run the program
2. Select game mode:
   - `1` → Player vs Player
   - `2` → Player vs Computer
3. Enter player names
4. Player 1 chooses their symbol (`X` or `O`)
5. Players take turns entering a number from **1 to 9** to place their symbol:

```
 1 | 2 | 3
-----------
 4 | 5 | 6
-----------
 7 | 8 | 9
```

6. First player to get **3 in a row** (horizontally, vertically, or diagonally) wins!
7. After each game, view the scoreboard and choose to play again or quit

---

## 📁 Project Structure

```
TIC-TAC-TOE/
│
├── TIC-TAC-TOE.c      # Main source code
└── README.md          # Project documentation
```

---

## 💡 Concepts Used

- Arrays and Loops
- Functions (`print_board`, `check_win`, `smart_move`)
- Nested Loops
- `do-while`, `while` loops
- Input Validation and Buffer Handling
- Preprocessor Directives (`#ifdef` for cross-platform support)
- String functions (`strcpy`, `toupper`)
- Random number generation (`rand`, `srand`)
- Global and Local Variables

---

## 🚀 Future Improvements

- [ ] Add difficulty levels (Easy / Medium / Hard)
- [ ] Add color to the board using ANSI codes
- [ ] Save scores to a file
- [ ] Add an unbeatable AI using the Minimax algorithm

---

## 👨‍💻 Author

**YASH KUMAR YADAV**
- 1st Year B.Tech Student
- GitHub: [Yashkumaryadav-sys](https://github.com/Yashkumaryadav-sys)

