#include <Windows.h>
#include <Shlwapi.h>
#include <locale.h>
#include <string>
#include <stdlib.h>
#pragma comment(lib, "Shlwapi.lib")

//#include <tchar.h>
//#include <string.h>

LPSTR delim;
LPSTR ctx;

int WINAPI WinMain(
	HINSTANCE hInst,
	HINSTANCE hPrevInst,
	LPSTR lpCmdLine,
	int nCmdShow
) {
	/*
	WCHAR	cmdw[50];
	size_t wLen_c = 0;
	errno_t err_c = 0;
	setlocale(LC_ALL, "japanese");
	err_c = mbstowcs_s(&wLen_c, cmdw, 40, lpCmdLine, _TRUNCATE);
	MessageBox(NULL, cmdw, TEXT("Result Path"), MB_OK);

	std::string space = " ";
	delim = const_cast<char*>(space.c_str());
	LPSTR path = new char[100];
	std::string str = "exe";
	LPSTR s2 = const_cast<char*>(str.c_str());
	LPSTR lpclCpy = lpCmdLine;
	LPSTR next = strtok_s(lpclCpy, delim, &ctx);
	while (next) {
		LPSTR sp;
		sp = strstr(next, s2);
		if (sp != NULL) {
			next = strtok_s(nullptr, delim, &ctx);
			continue;
		}
		else
		{
			strcpy_s(path, strlen(path), next);
			next = strtok_s(nullptr, delim, &ctx);
			while (next) {
				next = strtok_s(nullptr, delim, &ctx);
				strcat_s(path, strlen(path), next);
			}
			break;
		}
	}

	WCHAR	wStrW[50];
	//WCHAR originalCmdLine[50];

	size_t wLen = 0;
	errno_t err = 0;

	
	setlocale(LC_ALL, "japanese");
	err = mbstowcs_s(&wLen, wStrW, 20, path, _TRUNCATE);

	//MessageBox(NULL, originalCmdLine, TEXT("Original CmdLine"), MB_OK);
	MessageBox(NULL, wStrW, TEXT("Result Path"), MB_OK);

	free(path);
	//delete[] path;
	//delete[] s2, next, wStrW;
	//delete[] delim, ctx;*/

	if (PathFileExists(L"C:\\WINDOWS\\System32\\rundll32.exe")
		&& PathFileExists(L"C:\\Program Files\\Windows Photo Viewer\\PhotoViewer.dll")) {
		std::string str_part1 = "\"C:\\WINDOWS\\System32\\rundll32.exe\" \"C:\\Program Files\\Windows Photo Viewer\\PhotoViewer.dll\", ImageView_Fullscreen ";
		LPSTR part1 = const_cast<char*>(str_part1.c_str());
		char string[300];
		strcpy_s(string, _countof(string), part1);
		std::string path_s = lpCmdLine;
		path_s = path_s.substr(1, path_s.length() - 2);
		LPSTR path = const_cast<char*>(path_s.c_str());
		strcat_s(string, _countof(string), path);

		WCHAR	wStrW[300];

		size_t wLen = 0;
		errno_t err = 0;

		//ロケール指定
		setlocale(LC_ALL, "japanese");
		//変換
		err = mbstowcs_s(&wLen, wStrW, 300, string, _TRUNCATE);

		static STARTUPINFO si;
		PROCESS_INFORMATION ps;

		//MessageBox(NULL, wStrW, TEXT("Result"), MB_OK);
		//return 0;

		if (!CreateProcess(NULL, wStrW, NULL, NULL, FALSE, 0, NULL, NULL, &si, &ps)) {
			MessageBox(NULL,
				TEXT("Windowsフォトビューアーの起動に失敗しました。"),
				TEXT("起動失敗"),
				MB_OK);
		}
	}
	else
	{
		MessageBox(NULL,
			TEXT("このコンピューター内には、Windowsフォトビューアーのアセンブリが見つかりませんでした。"),
			TEXT("探索失敗"),
			MB_OK);
	}
}