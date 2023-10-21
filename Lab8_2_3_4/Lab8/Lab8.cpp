
#include "framework.h"
#include "Lab8.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_LAB8, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB8));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB8));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB8);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
void DrawHome(HDC hdc)
{
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(250, 150, 0));
    SelectObject(hdc, hPen);
    //крыша
    MoveToEx(hdc, 150, 350, NULL);
    LineTo(hdc, 275, 250);
    LineTo(hdc, 400, 350);

    // стена дома
    LineTo(hdc, 400, 525);
    LineTo(hdc, 150, 525);
    LineTo(hdc, 150, 350);
    LineTo(hdc, 400, 350);

    // окно
    MoveToEx(hdc, 225, 400, NULL);
    LineTo(hdc, 225, 475);
    LineTo(hdc, 325, 475);
    LineTo(hdc, 325, 400);
    LineTo(hdc, 225, 400);
    MoveToEx(hdc, 275, 400, NULL);
    LineTo(hdc, 275, 475);
    MoveToEx(hdc, 275, 425, NULL);
    LineTo(hdc, 325, 425);
}

void DrawCar(HDC hdc)
{
    // car

    HBRUSH hBrush;
    hBrush = CreateSolidBrush(RGB(255, 128, 67));
    SelectObject(hdc, hBrush);

    Rectangle(hdc, 50, 200, 300, 250); 
    MoveToEx(hdc, 100, 200, NULL);
    LineTo(hdc, 150, 150);
    LineTo(hdc, 250, 150);
    LineTo(hdc, 300, 200);

    HPEN hPen = CreatePen(PS_SOLID, 10, RGB(50, 50, 50));
    SelectObject(hdc, hPen);
    hBrush = CreateSolidBrush(RGB(200, 200, 200));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, 75, 225, 125, 275);
    Ellipse(hdc, 225, 225, 275, 275);
}

void DrawTree(HDC hdc)
{
    HPEN hPen = CreatePen(PS_SOLID, 3, RGB(0, 100, 0));
    SelectObject(hdc, hPen);

    // green flower
    int x = 10 + 160;
    do {
        MoveToEx(hdc, 150 + 160, 250, NULL);  
        LineTo(hdc, x, 200);
        x += 10;
    } while (x <= 280 + 160);

    // pink flower
    hPen = CreatePen(PS_SOLID, 3, RGB(240, 0, 200));  
    SelectObject(hdc, hPen);
    x = 120 + 160;
    do {
        MoveToEx(hdc, 150 + 160, 250, NULL);
        LineTo(hdc, x, 175);
        x += 5;
    } while (x <= 180 + 160);
}

void DrawSnowman(HDC hdc)
{
    HPEN hPen = CreatePen(PS_SOLID, 2, RGB(50, 50, 50)); // snowman
    SelectObject(hdc, hPen);
    HBRUSH hBrush = CreateSolidBrush(RGB(250, 150, 150));
    SelectObject(hdc, hBrush);

    Ellipse(hdc, 380, 210, 490, 300);
    Ellipse(hdc, 390, 180, 480, 250);
    Ellipse(hdc, 400, 150, 470, 200);


    hPen = CreatePen(PS_SOLID, 3, RGB(150, 50, 50));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, 410, 215, NULL); // left hand
    LineTo(hdc, 360, 230);
    MoveToEx(hdc, 370, 225, NULL);
    LineTo(hdc, 360, 220);

    MoveToEx(hdc, 460, 215, NULL); // right hand
    LineTo(hdc, 510, 230);
    MoveToEx(hdc, 500, 225, NULL);
    LineTo(hdc, 510, 220);

    hPen = CreatePen(PS_SOLID, 3, RGB(200, 100, 0)); // nos snowman'a
    SelectObject(hdc, hPen);
    MoveToEx(hdc, 431, 175, NULL);
    LineTo(hdc, 435, 205);
    LineTo(hdc, 439, 175);

    hPen = CreatePen(PS_SOLID, 3, RGB(10, 10, 10));
    SelectObject(hdc, hPen);

    Ellipse(hdc, 425, 170, 427, 172); // eyes
    Ellipse(hdc, 441, 170, 443, 172);
}

void DrawCactus(HDC hdc)
{
    HPEN hPen = CreatePen(PS_SOLID, 3, RGB(0, 100, 0)); // cactus
    SelectObject(hdc, hPen);
    HBRUSH hBrush = CreateSolidBrush(RGB(0, 150, 0));
    SelectObject(hdc, hBrush);
    Rectangle(hdc, 600, 80, 650, 300);
    Rectangle(hdc, 580, 120, 610, 230);
    Rectangle(hdc, 645, 150, 665, 230);

    hPen = CreatePen(PS_SOLID, 3, RGB(250, 60, 60)); // flowers
    SelectObject(hdc, hPen);
    hBrush = CreateSolidBrush(RGB(250, 150, 150));
    SelectObject(hdc, hBrush);
    Rectangle(hdc, 575, 115, 590, 130);
    Rectangle(hdc, 635, 70, 655, 90);
}

void DrawBus(HDC hdc)
{
    HPEN hPen = CreatePen(PS_SOLID, 3, RGB(210, 210, 0)); // bus corpus
    SelectObject(hdc, hPen);
    HBRUSH hBrush = CreateSolidBrush(RGB(230, 230, 100));
    SelectObject(hdc, hBrush);

    Rectangle(hdc, 700, 220, 800, 300);
    Rectangle(hdc, 790, 150, 1200, 300);

    hBrush = CreateSolidBrush(RGB(230, 230, 230)); // bus window
    SelectObject(hdc, hBrush);
    Rectangle(hdc, 810, 180, 1180, 230);

    hPen = CreatePen(PS_SOLID, 10, RGB(50, 50, 50)); // bus circles
    SelectObject(hdc, hPen);
    hBrush = CreateSolidBrush(RGB(200, 200, 200));
    SelectObject(hdc, hBrush);

    Ellipse(hdc, 810, 270, 880, 340);
    Ellipse(hdc, 1100, 270, 1170, 340);
}

void DrawWaterStorage(HDC hdc)
{
    HPEN hPen = CreatePen(PS_SOLID, 5, RGB(150, 150, 150));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, 675, 525, NULL);
    LineTo(hdc, 800, 525);
    LineTo(hdc, 800, 425);
    LineTo(hdc, 675, 425);
    LineTo(hdc, 675, 525);
    MoveToEx(hdc, 700, 425, NULL);
    LineTo(hdc, 700, 400);
    MoveToEx(hdc, 775, 425, NULL);
    LineTo(hdc, 775, 400);

    MoveToEx(hdc, 675, 400, NULL);
    LineTo(hdc, 800, 400);
    LineTo(hdc, 740, 360);
    LineTo(hdc, 675, 400);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);

            DrawHome(hdc);
            DrawCar(hdc);
            DrawTree(hdc);
            DrawSnowman(hdc);
            DrawCactus(hdc);
            DrawBus(hdc);
            DrawWaterStorage(hdc);


            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
