// HelloWindowsDesktop.cpp
// compile with: /D_UNICODE /DUNICODE /DWIN32 /D_WINDOWS /c



#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>

// Global variables

// The main window class name.
static TCHAR szWindowClass[] = _T("DesktopApp");

// The string that appears in the application's title bar.
static TCHAR szTitle[] = _T("Windows Desktop Guided Tour Application");

// Stored instance handle for use in Win32 API calls such as FindResource
HINSTANCE hInst;

// Forward declarations of functions included in this code module:
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR     lpCmdLine,
    _In_ int       nCmdShow
)
{
    WNDCLASSEX wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(wcex.hInstance, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

    if (!RegisterClassEx(&wcex))
    {
        MessageBox(NULL,
            _T("Call to RegisterClassEx failed!"),
            _T("Windows Desktop Guided Tour"),
            NULL);

        return 1;
    }

    // Store instance handle in our global variable
    hInst = hInstance;

    // The parameters to CreateWindowEx explained:
    // WS_EX_OVERLAPPEDWINDOW : An optional extended window style.
    // szWindowClass: the name of the application
    // szTitle: the text that appears in the title bar
    // WS_OVERLAPPEDWINDOW: the type of window to create
    // CW_USEDEFAULT, CW_USEDEFAULT: initial position (x, y)
    // 500, 100: initial size (width, length)
    // NULL: the parent of this window
    // NULL: this application does not have a menu bar
    // hInstance: the first parameter from WinMain
    // NULL: not used in this application
    HWND hWnd = CreateWindowEx(
        WS_EX_OVERLAPPEDWINDOW,
        szWindowClass,
        szTitle,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        500, 500,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    if (!hWnd)
    {
        MessageBox(NULL,
            _T("Call to CreateWindow failed!"),
            _T("Windows Desktop Guided Tour"),
            NULL);

        return 1;
    }

    // The parameters to ShowWindow explained:
    // hWnd: the value returned from CreateWindow
    // nCmdShow: the fourth parameter from WinMain
    ShowWindow(hWnd,
        nCmdShow);
    UpdateWindow(hWnd);

    // Main message loop:
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}
void Image4(HDC hdc, int cx, int cy, int size) {
    int x1 = cx;
    int y1 = cy - size;
    int x2 = cx + size / 4;
    int y2 = cy - size / 4;
    int x3 = cx + size;
    int y3 = cy;
    int x4 = cx + size / 4;
    int y4 = cy + size / 4;
    int x5 = cx;
    int y5 = cy + size;
    int x6 = cx - size / 4;
    int y6 = cy + size / 4;
    int x7 = cx - size;
    int y7 = cy;
    int x8 = cx - size / 4;
    int y8 = cy - size / 4;

    HPEN hpen;
    hpen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
    SelectObject(hdc, hpen);
    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
    LineTo(hdc, x3, y3);
    LineTo(hdc, x4, y4);
    LineTo(hdc, x5, y5);
    LineTo(hdc, x6, y6);
    LineTo(hdc, x7, y7);
    LineTo(hdc, x8, y8);
    LineTo(hdc, x1, y1);


    DeleteObject(hpen);
}

void RecursiveImage4_1(HDC hdc, int cx, int cy, int size) {
    Image4(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    RecursiveImage4_1(hdc, cx + size, cy, size / 2);
}

void RecursiveImage4_2(HDC hdc, int cx, int cy, int size) {
    Image4(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    RecursiveImage4_2(hdc, cx + size, cy, size / 2);
    RecursiveImage4_2(hdc, cx - size, cy, size / 2);
}

void RecursiveImage4_3(HDC hdc, int cx, int cy, int size) {
    Image4(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    RecursiveImage4_3(hdc, cx, cy + size, size / 2);
    RecursiveImage4_3(hdc, cx, cy - size, size / 2);
}

void RecursiveImage4_4(HDC hdc, int cx, int cy, int size) {
    Image4(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    RecursiveImage4_4(hdc, cx, cy + size, size / 2);
    RecursiveImage4_4(hdc, cx, cy - size, size / 2);
    RecursiveImage4_4(hdc, cx - size, cy, size / 2);
}

void MyRecursiveImage4_1(HDC hdc, int cx, int cy, int size) {
    Image4(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    MyRecursiveImage4_1(hdc, cx + size, cy + size, size / 2);
    MyRecursiveImage4_1(hdc, cx - size, cy - size, size / 2);
}

void MyRecursiveImage4_2(HDC hdc, int cx, int cy, int size) {
    Image4(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    MyRecursiveImage4_2(hdc, cx - size, cy + size, size / 2);
    MyRecursiveImage4_2(hdc, cx + size, cy - size, size / 2);
}

void MyRecursiveImage4_3(HDC hdc, int cx, int cy, int size) {
    Image4(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    MyRecursiveImage4_3(hdc, cx - size, cy - size, size / 2);
    MyRecursiveImage4_3(hdc, cx - size, cy + size, size / 2);
}

void MyRecursiveImage4_4(HDC hdc, int cx, int cy, int size) {
    Image4(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    MyRecursiveImage4_4(hdc, cx + size, cy - size, size / 2);
    MyRecursiveImage4_4(hdc, cx + size, cy + size, size / 2);
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;

    switch (message)
    {

    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);

        //Image4(hdc, 200, 200, 100);
        //RecursiveImage4_1(hdc, 200, 200, 100);
        //RecursiveImage4_2(hdc, 200, 200, 100);
        //RecursiveImage4_3(hdc, 200, 200, 100);
        //RecursiveImage4_4(hdc, 200, 200, 100);

        //MyRecursiveImage4_1(hdc, 200, 200, 100);
        //MyRecursiveImage4_2(hdc, 200, 200, 100);
        //MyRecursiveImage4_3(hdc, 200, 200, 100);
        //MyRecursiveImage4_4(hdc, 200, 200, 100);

        EndPaint(hWnd, &ps);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
        break;
    }
    return 0;
}
