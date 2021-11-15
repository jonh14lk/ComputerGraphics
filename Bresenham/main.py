pixels = [] # 0 - pixel não colorido, 1 - pixel colorido

def write_pixel(x, y):
    print("Colorindo pixel " + "(" + str(x) + ", " + str(y) + ")")
    pixels[x][y] = 1

def init_pixels():
    for i in range(0, 10):
        col = []
        for j in range(0, 10):
            col.append(0)
        pixels.append(col)

def bresenham(x1, y1, x2, y2):
    dx = x2 - x1; dy = y2 - y1; d = 2 * dy - dx
    incE = 2 * dy; incNE = 2 * (dy - dx)
    x = x1; y = y1
    write_pixel(x, y)
    while x < x2:
        if d <= 0:
            d += incE; x += 1
        else:
            d += incNE; x += 1; y += 1
        write_pixel(x, y)

def print_pixels():
    print("Resultado:")
    for i in range(0, 10):
        for j in range (0, 10):
            print(pixels[i][j], end = ' ')
        print()

def main():
    x1 = 1; y1 = 1
    x2 = 8; y2 = 5
    init_pixels()
    bresenham(x1, y1, x2, y2)
    print_pixels()

if __name__ == '__main__':
    main()