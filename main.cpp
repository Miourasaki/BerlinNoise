#include <iostream>
#include <random>
#include <cmath>


int fastFloor(double x)
{
    return x > 0 ? (int) x : (int) x - 1;
}

int p[512]{
        151, 160, 137, 91, 90, 15,
        131, 13, 201, 95, 96, 53, 194, 233, 7, 225, 140, 36, 103, 30, 69, 142, 8, 99, 37, 240, 21, 10, 23,
        190, 6, 148, 247, 120, 234, 75, 0, 26, 197, 62, 94, 252, 219, 203, 117, 35, 11, 32, 57, 177, 33,
        88, 237, 149, 56, 87, 174, 20, 125, 136, 171, 168, 68, 175, 74, 165, 71, 134, 139, 48, 27, 166,
        77, 146, 158, 231, 83, 111, 229, 122, 60, 211, 133, 230, 220, 105, 92, 41, 55, 46, 245, 40, 244,
        102, 143, 54, 65, 25, 63, 161, 1, 216, 80, 73, 209, 76, 132, 187, 208, 89, 18, 169, 200, 196,
        135, 130, 116, 188, 159, 86, 164, 100, 109, 198, 173, 186, 3, 64, 52, 217, 226, 250, 124, 123,
        5, 202, 38, 147, 118, 126, 255, 82, 85, 212, 207, 206, 59, 227, 47, 16, 58, 17, 182, 189, 28, 42,
        223, 183, 170, 213, 119, 248, 152, 2, 44, 154, 163, 70, 221, 153, 101, 155, 167, 43, 172, 9,
        129, 22, 39, 253, 19, 98, 108, 110, 79, 113, 224, 232, 178, 185, 112, 104, 218, 246, 97, 228,
        251, 34, 242, 193, 238, 210, 144, 12, 191, 179, 162, 241, 81, 51, 145, 235, 249, 14, 239, 107,
        49, 192, 214, 31, 181, 199, 106, 157, 184, 84, 204, 176, 115, 121, 50, 45, 127, 4, 150, 254,
        138, 236, 205, 93, 222, 114, 67, 29, 24, 72, 243, 141, 128, 195, 78, 66, 215, 61, 156, 180,
        151, 160, 137, 91, 90, 15,
        131, 13, 201, 95, 96, 53, 194, 233, 7, 225, 140, 36, 103, 30, 69, 142, 8, 99, 37, 240, 21, 10, 23,
        190, 6, 148, 247, 120, 234, 75, 0, 26, 197, 62, 94, 252, 219, 203, 117, 35, 11, 32, 57, 177, 33,
        88, 237, 149, 56, 87, 174, 20, 125, 136, 171, 168, 68, 175, 74, 165, 71, 134, 139, 48, 27, 166,
        77, 146, 158, 231, 83, 111, 229, 122, 60, 211, 133, 230, 220, 105, 92, 41, 55, 46, 245, 40, 244,
        102, 143, 54, 65, 25, 63, 161, 1, 216, 80, 73, 209, 76, 132, 187, 208, 89, 18, 169, 200, 196,
        135, 130, 116, 188, 159, 86, 164, 100, 109, 198, 173, 186, 3, 64, 52, 217, 226, 250, 124, 123,
        5, 202, 38, 147, 118, 126, 255, 82, 85, 212, 207, 206, 59, 227, 47, 16, 58, 17, 182, 189, 28, 42,
        223, 183, 170, 213, 119, 248, 152, 2, 44, 154, 163, 70, 221, 153, 101, 155, 167, 43, 172, 9,
        129, 22, 39, 253, 19, 98, 108, 110, 79, 113, 224, 232, 178, 185, 112, 104, 218, 246, 97, 228,
        251, 34, 242, 193, 238, 210, 144, 12, 191, 179, 162, 241, 81, 51, 145, 235, 249, 14, 239, 107,
        49, 192, 214, 31, 181, 199, 106, 157, 184, 84, 204, 176, 115, 121, 50, 45, 127, 4, 150, 254,
        138, 236, 205, 93, 222, 114, 67, 29, 24, 72, 243, 141, 128, 195, 78, 66, 215, 61, 156, 180
};

// f(t) = 6(t^5) - 15(t^4) + 10(t^3)
double fade(double t) { return t * t * t * (t * (t * 6 - 15) + 10); }

double lerp(double t, double a, double b) { return a + t * (b - a); }

double dot(int hash, double x, double y)
{
    switch (hash & 3)
    {
        case 0:
            return x + y;
        case 1:
            return -x + y;
        case 2:
            return x - y;
        case 3:
            return -x - y;
    }
    std::exit(1);
}

double berlin2d(double x, double y)
{
    int xn = fastFloor(x);
    int yn = fastFloor(y);
    double xf = x - xn;
    double yf = y - yn;

    xn = xn % 255;
    yn = yn % 255;
    int aa = p[p[xn] + yn];
    int ab = p[p[xn + 1] + yn];
    int ba = p[p[xn] + yn + 1];
    int bb = p[p[xn + 1] + yn + 1];
    double v1 = lerp(fade(xf), dot(aa, xf, yf), dot(ab, xf - 1, yf));
    double v2 = lerp(fade(xf), dot(ba, xf, yf - 1), dot(bb, xf - 1, yf - 1));
    double v3 = lerp(fade(yf), v1, v2);
    return v3;
}

int main()
{

    for (;;)
    {

        double ox, oy, line;
        int cont;
        std::cout << "Number of superpositions ↓" << std::endl;
        if (!(std::cin >> cont)) {
            std::cerr << "Error reading seed." << std::endl;
            return 1;
        }
        std::cout << "input start point ↓ x (space) y" << std::endl;
        if (!(std::cin >> ox >> oy))
        {
            std::cerr << "Error reading start point." << std::endl;
            return 1;
        }
        std::cout << "input start side length ↓" << std::endl;
        if (!(std::cin >> line))
        {
            std::cerr << "Error reading side length." << std::endl;
            return 1;
        }

        for (double i = oy; i < oy + line; i += 0.1)
        {
            for (double j = ox; j <= ox + line; j += 0.1)
            {
                double result = 0.0;
                for (int c =0 ; c<cont ; c++) {
                    double r1 = pow(2, 0-c) * berlin2d(i * pow(2, c), j * pow(2, c));
                    result += r1;
                }
                if (result >= 0.75)
                {
                    std::cout << "\033[47m" << "  " << "\033[0m";
                } else if (result >= 0.5)
                {
                    std::cout << "\033[46m" << "  " << "\033[0m";
                } else if (result >= 0.25)
                {
                    std::cout << "\033[45m" << "  " << "\033[0m";
                } else if (result >= 0)
                {
                    std::cout << "\033[44m" << "  " << "\033[0m";
                } else if (result >= -0.2)
                {
                    std::cout << "\033[43m" << "  " << "\033[0m";
                } else if (result >= -0.4)
                {
                    std::cout << "\033[42m" << "  " << "\033[0m";
                } else if (result >= -0.6)
                {
                    std::cout << "\033[41m" << "  " << "\033[0m";
                } else
                {
                    std::cout << "\033[40m" << "  " << "\033[0m";
                }

            }
            std::cout << std::endl;
        }

    }
}
