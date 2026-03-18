# C-Programming — 大一上 C 程式設計（中山大學）

> 本專案為中山大學（NSYSU）大一上學期「C 程式設計」課程的學習資料，包含每週實驗課程式碼、作業解答及期中/期末考試練習。
>
> **學號：** B113040045

---

## 📁 目錄結構

```
C-Programming/
├── C程設計實驗/     # 每週實驗課講義與範例程式
├── EXAM/            # 期中考、期末考解答
└── Homework/        # 每週課後作業
```

---

## 🔬 C程設計實驗（Lab 實驗課）

每週實驗課的 PPT 講義與範例程式，課程內容依週次遞進。

| 週次 | 資料夾 | 主題 |
|------|--------|------|
| 第 1 週 | `0908` | 課程介紹 |
| 第 2 週 | `0915` | 基本輸入輸出（printf / scanf）、變數與資料型別 |
| 第 3 週 | `0922` | 數學運算（pow()）、浮點數精度（float vs double） |
| 第 4 週 | `0929` | 條件判斷（if / else）、輸入驗證 |
| 第 5 週 | `1006` | 迴圈（for）、偶數列舉 |
| 第 6 週 | `1013` | 陣列、亂數產生（rand / srand）、排序概念 |
| 第 7 週 | `1020` | 選擇排序法（Selection Sort） |
| 第 9 週 | `1103` | 字串與字元陣列 |
| 第 10 週 | `1110` | 檔案讀取（getc / fscanf / fgets / fread） |
| 第 11 週 | `1117` | 函式（Functions）、遞迴（GCD / LCM） |
| 第 13 週 | `1201` | 指標（Pointers）、記憶體位址 |
| 第 14 週 | `1208` | 函式指標（Function Pointers）、計算機實作 |
| 期中一 | `FIRST MIDTERN EXAM` | 座標幾何、ASCII 圖形繪製 |
| 期中二 | `SECOND MIDTERN EXAM` | 字串旋轉、Linked List / Queue |
| 期末 | `FINAL EXAM` | 字串旋轉（rotateString）、二元搜尋樹（BST） |

---

## 📝 EXAM（考試解答）

個人考試解答及考題說明。

| 資料夾 | 內容 |
|--------|------|
| `FIRST MIDTERN/` | 期中考一解答：2D 字元陣列繪圖（座標幾何視覺化）、講解 PPT |
| `SECOND MIDTERN/` | 期中考二解答：字串操作，含測試程式與考題 PDF |
| `FINAL/` | 期末考解答：二元樹（BST）與 Stack 實作、考題 PDF 與講解 PPT |

---

## 🏠 Homework（作業）

每週的課後作業解答。

| 作業 | 資料夾 | 主題 |
|------|--------|------|
| HW 1 | `0915` | 三角形面積計算 |
| HW 2 | `0922` | 找零程式（100 / 50 / 10 / 5 / 1 元） |
| HW 3 | `0929` | 基礎程式練習 |
| HW 4 | `1006` | 基礎程式練習 |
| HW 5 | `1013` | 基礎程式練習 |
| HW 6 | `1020 (極麻煩)` | 三次多項式函數繪圖及微分（難度較高） |
| HW 7 | `1027` | 矩陣卷積（Convolution）+ ReLU 激活函數 |
| HW 8 | `1103` | 二值影像連通元件標記（Connected Component Labeling） |
| HW 9 | `1110` | 括號匹配（Stack 實作） |
| HW 10 | `1117` | 進階函式練習 |
| HW 11 | `1124` | 進階練習 |
| HW 12 | `1201` | 指標應用進階 |

---

## 🎯 課程涵蓋的程式概念

| 類別 | 概念 |
|------|------|
| **輸入輸出** | printf、scanf、getc、fscanf、fgets、fread、檔案讀寫 |
| **資料型別** | int、float、double、char、陣列、結構體（struct） |
| **流程控制** | if/else、for、while、switch |
| **函式** | 使用者自訂函式、遞迴（GCD/LCM）、函式指標 |
| **指標** | 取址（&）、解參考（\*）、指標運算 |
| **資料結構** | 陣列、Linked List、Stack、Queue、Binary Tree（BST） |
| **演算法** | Selection Sort、字串旋轉、連通元件標記、卷積運算 |
| **數學函式** | pow()、sqrt()、三角函式、多項式求值 |

---

## 🛠 編譯方式

本專案所有 `.c` 原始碼均可使用 `gcc` 編譯：

```bash
# 一般程式
gcc -o output filename.c

# 需要數學函式庫的程式（使用 pow、sqrt 等）
gcc -o output filename.c -lm
```

> 部分程式需要讀取外部 `.txt` 檔案（如 `coordinate.txt`、`BinaryImage.txt`），請確保執行時該檔案位於同一目錄下。

---

## 📊 資料統計

| 項目 | 數量 |
|------|------|
| C 原始碼（.c） | 89 個 |
| PowerPoint 講義（.pptx） | 13 個 |
| PDF 文件 | 6 個 |
| 文字檔（.txt） | 19 個 |
| 總資料夾數 | 42 個 |
