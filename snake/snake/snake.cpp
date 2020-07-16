#include <iostream>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>

using namespace std;

//ОБЬЯВЛЕНИЕ ПЕРЕМЕННЫХ
const int width = 24;
const int height = 24;
const int size22 = width * height;
int play_field[size22];
int head_x, head_y, d, n, p, t, m, c;
int direction = 1;
int snake_length = 3;
int score = 0;
bool game111;
int x, y = 0;

//ФУНКЦИИ
int menu();
int go();
void draw2();
void draw();
void body();
void kor();
void level();
void eda();
char q7(int value);
void bomb();
int help();

int help() {
	system("color 0D");
	system("cls");
	cout << "0 - Как играть " << endl;
	cout << "1 - Режим ОБЫЧНЫЙ " << endl;
	cout << "2 - Режим ЛОЖНАЯ ЕДА " << endl;
	cin >> m;
	switch (m)
	{
	case 0: system("cls"); cout << "Для управления змейкой используйте клавиши w a s d , при попадании за границы поля СМЕРТЬ, при попадании на собственный хвост СМЕРТЬ." << endl <<
		"Желаем приятной игры ! ! ! " << endl << endl;
		cout << "1 - В меню " << endl << "2 - Начать игру" << endl;
		cin >> c;
		switch (c)
		{
		case 1:menu();
		case 2:level();
		default:menu();
			break;
		}
		system("pause");

	case 1: system("cls"); cout << "В режиме ОБЫЧНЫЙ ваша задача сьесть как можно больше еды обозначенными символом о , не врезавшись в стенки и не сьев свой хвост) " << endl <<
		"Продолжив игру вы сохраняете кол-во набранных очков, но кол-во еды увеличивается." << endl << endl;
		cout << "1 - В меню " << endl << "2 - Начать игру" << endl;
		cin >> c;
		switch (c)
		{
		case 1:menu();
		case 2:level();
		default:menu();
			break;
		}
		system("pause");

	case 2: system("cls"); cout << "В данном режиме правила такие же, как и в обычном, но теперь на вашем пути есть псевдо еда обозначенная символом %, сьев ее вы сразу же умираете" << endl << endl;
		cout << "1 - В меню " << endl << "2 - Начать игру" << endl;
		cin >> c;
		switch (c)
		{
		case 1:menu();
		case 2:level();
		default:menu();
			break;
		}
		system("pause");
	default:menu();
		break;
	}
	return menu();
}

char q7(int value) {
	if (value > 0) return 'Z';
	switch (value) {
	case -1:return 'X';
	case -2:return 'o';
	case -3:return '%';
	}

}

void draw2() {
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			cout << q7(play_field[x + y * width]);
		}
		cout << endl;
	}
	cout << "Score: " << score << endl;
}

void eda()
{
	int x, y = 0;
	do {
		srand(time(NULL));
		x = rand() % (width - 2) + 1;
		y = rand() % (height - 2) + 1;

	} while (play_field[x + y * width] != 0);

	play_field[x + y * width] = -2;

}

void eda2()
{
	int x, y = 0;
	do {
		srand(time(NULL));
		x = rand() % (width - 2) + 1;
		y = rand() % (height - 2) + 1;
	} while (play_field[x + y * width] != 0);

	play_field[x + y * width] = -3;

	do {
		srand(time(NULL));
		x = rand() % (width - 2) + 1;
		y = rand() % (height - 2) + 1;
	} while (play_field[x + y * width] != 0);

	play_field[x + y * width] = -3;

	do {
		srand(time(NULL));
		x = rand() % (width - 2) + 1;
		y = rand() % (height - 2) + 1;
	} while (play_field[x + y * width] != 0);

	play_field[x + y * width] = -3;
	do {
		srand(time(NULL));
		x = rand() % (width - 2) + 1;
		y = rand() % (height - 2) + 1;
	} while (play_field[x + y * width] != 0);

	do {
		srand(time(NULL));
		x = rand() % (width - 2) + 1;
		y = rand() % (height - 2) + 1;
	} while (play_field[x + y * width] != 0);

	do {
		srand(time(NULL));
		x = rand() % (width - 2) + 1;
		y = rand() % (height - 2) + 1;
	} while (play_field[x + y * width] != 0);

	play_field[x + y * width] = -3;
	play_field[x + y * width] = -3;
	play_field[x + y * width] = -3;

}

void bomb() {
	draw();
	eda2();
	game111 = true;
	while (game111) {
		if (_kbhit()) {
			char key = _getch();
			switch (key) {
			case 'w':
				if (direction != 3)direction = 1;
				break;
			case 'd':
				if (direction != 4)direction = 2;
				break;
			case 's':
				if (direction != 1)direction = 3;
				break;
			case 'a':
				if (direction != 2)direction = 4;
				break;
			}

		}
		kor();
		system("cls");

		draw2();
		switch (d)
		{
		case 1: Sleep(80);
			break;
		case 2: Sleep(60);
			break;
		case 3: Sleep(40);
			break;
		}
	}
	game111 = false;
	system("cls");
	cout << "GAME OVER" << endl << "Кол-во очков - " << score << endl;

	system("pause");
	cin.ignore();
	return;

}

void body(int x, int y) {

	int x1 = head_x + x;
	int y1 = head_y + y;

	if (play_field[x1 + y1 * width] == -2) {
		snake_length++;
		score = score + 10;
		eda();
	}

	else if (play_field[x1 + y1 * width] != 0) {
		game111 = false;
	}
	head_x = x1;
	head_y = y1;
	play_field[head_x + head_y * width] = snake_length + 1;
}

void draw() {
	system("color 0A");
	head_x = width / 2;
	head_y = height / 2;
	play_field[head_x + head_y * height] = 1;

	for (int x = 0; x < width; x++) {
		play_field[x] = -1;
		play_field[x + (height - 1)*width] = -1;
	}
	for (int y = 0; y < height; y++) {
		play_field[0 + y * height] = -1;
		play_field[(width - 1) + y * width] = -1;
	}

	eda();

}

void level() {
	system("cls");
	setlocale(0, "");
	HKL keyboard = GetKeyboardLayout(0);
	int keyboard2 = LOWORD(keyboard);
	if (keyboard2 == 0x0419) {
		cout << "Измените раскладку клавиатуры для корректной работы игры" << endl;
	}
	cout << endl << "Введите уровень сложности " << endl;
	cout << "1 - Легко " << endl << "2 - Средний " << endl << "3 - Сложно " << endl << "0 - Выход" << endl;
	cin >> d;
	if (d == 0) {
		exit(0);
	}
	if (d == 1 || d == 2 || d == 3) {
		menu();
	}
	else {
		while (true) {
			cout << "Введите уровень сложности " << endl;
			cout << "1 - Легко " << endl << "2 - Средний " << endl << "3 - Сложно " << endl << "0 - Выход" << endl << endl;
			cin >> d;
			if (d == 1 || d == 2 || d == 3) {
				menu();
				break;
			}
		}
	}
}

int go() {
	draw();
	game111 = true;
	while (game111) {
		if (_kbhit()) {
			char key = _getch();
			switch (key) {
			case 'w':
				if (direction != 3)direction = 1;
				break;
			case 'd':
				if (direction != 4)direction = 2;
				break;
			case 's':
				if (direction != 1)direction = 3;
				break;
			case 'a':
				if (direction != 2)direction = 4;
				break;
			}

		}
		kor();
		system("cls");

		draw2();
		switch (d)
		{
		case 1: Sleep(80);
			break;
		case 2: Sleep(65);
			break;
		case 3: Sleep(55);
			break;
		}
	}
	game111 = false;
	system("cls");
	cout << "GAME OVER" << endl << "Кол-во очков - " << score << endl << endl;
	cout << "Продолжить?" << endl;
	cout << "1 - Да" << endl << "2 - Выход" << endl;
	cin.ignore();
	cin >> t;
	switch (t)
	{
	case 1:go();
	case 2:exit(0);
	default:menu();
	}

	cin.ignore();
	return 0;


}

void kor() {
	switch (direction)
	{
	case 1: body(-1, 0);
		break;
	case 2: body(0, 1);
		break;
	case 3: body(1, 0);
		break;
	case 4: body(0, -1);
		break;

	}
	for (int i = 0; i < size22; i++) {
		if (play_field[i] > 0) {
			play_field[i]--;
		}
	}
}

void mode() {
	system("cls");
	cout << "1 - Обычный" << endl;
	cout << "2 - Ложная еда" << endl;
	cin >> n;
	switch (n)
	{
	case 1:go();
		break;
	case 2:bomb();
		break;
	}

}

int menu() {
	system("color 0D");
	system("cls");
	cout << "1 - Уровень сложности" << endl;
	cout << "2 - Режим" << endl;
	cout << "3 - Помощь" << endl;
	cout << "4 - Выход" << endl;
	cin >> p;
	switch (p)
	{
	case 1:level();
		break;
	case 2:mode();
		break;
	case 3:help();
	case 4:exit(0);
	default:menu();
	}


	return 0;
}

int main()
{
	setlocale(0, "");
	menu();
	return 0;
}