import random
import tkinter as tk
from tkinter import messagebox

class MineSweeper:
    def __init__(self, rows=10, cols=10, mines=10):
        self.rows = rows
        self.cols = cols
        self.mines = mines
        self.buttons = []
        self.mine_map = [[0]*cols for _ in range(rows)]
        self.is_reveal = [[False]*cols for _ in range(rows)]
        self.is_flag = [[False]*cols for _ in range(rows)]
        
        # 窗口
        self.root = tk.Tk()
        self.root.title("扫雷")
        
        # 放地雷
        self.place_mines()
        
        # 建按钮
        self.create_widgets()

    def place_mines(self):
        count = 0
        while count < self.mines:
            r = random.randint(0, self.rows-1)
            c = random.randint(0, self.cols-1)
            if self.mine_map[r][c] != -1:
                self.mine_map[r][c] = -1
                count += 1
                # 周围+1
                for dr in (-1,0,1):
                    for dc in (-1,0,1):
                        if dr==0 and dc==0: continue
                        nr = r+dr
                        nc = c+dc
                        if 0<=nr<self.rows and 0<=nc<self.cols:
                            if self.mine_map[nr][nc] != -1:
                                self.mine_map[nr][nc] += 1

    def create_widgets(self):
        for r in range(self.rows):
            row_buttons = []
            for c in range(self.cols):
                btn = tk.Button(self.root, width=2, height=1, font=('Arial',12))
                btn.bind('<Button-1>', lambda e, x=r, y=c: self.reveal(x,y))
                btn.bind('<Button-3>', lambda e, x=r, y=c: self.flag(x,y))
                btn.grid(row=r, column=c)
                row_buttons.append(btn)
            self.buttons.append(row_buttons)

    def reveal(self, r, c):
        # 越界/已翻开/有旗 直接返回
        if not (0<=r<self.rows and 0<=c<self.cols): return
        if self.is_reveal[r][c] or self.is_flag[r][c]: return
        
        # 点到地雷
        if self.mine_map[r][c] == -1:
            self.buttons[r][c].config(text='💣', bg='red')
            messagebox.showerror('游戏结束', '你踩到地雷了！')
            self.show_all_mines()
            return
        
        # 翻开
        self.is_reveal[r][c] = True
        num = self.mine_map[r][c]
        self.buttons[r][c].config(text=str(num) if num!=0 else '', bg='lightgray')
        
        # 空白自动扩散
        if num == 0:
            for dr in (-1,0,1):
                for dc in (-1,0,1):
                    self.reveal(r+dr, c+dc)
        
        self.check_win()

    def flag(self, r, c):
        if self.is_reveal[r][c]: return
        self.is_flag[r][c] = not self.is_flag[r][c]
        self.buttons[r][c].config(text='🚩' if self.is_flag[r][c] else '')

    def show_all_mines(self):
        for r in range(self.rows):
            for c in range(self.cols):
                if self.mine_map[r][c] == -1:
                    self.buttons[r][c].config(text='💣')

    def check_win(self):
        cnt = 0
        for r in range(self.rows):
            for c in range(self.cols):
                if self.is_reveal[r][c]:
                    cnt +=1
        total = self.rows*self.cols - self.mines
        if cnt == total:
            messagebox.showinfo('胜利', '恭喜你扫雷成功！')
            self.root.quit()

    def run(self):
        self.root.mainloop()

# 行数、列数、地雷数 可以自己改
if __name__ == '__main__':
    game = MineSweeper(rows=10, cols=10, mines=10)
    game.run()