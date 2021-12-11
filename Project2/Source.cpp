#include <iostream>
#include <Windows.h>
#include "user.h"
using namespace std;

void deleteEndL(char* text) {
	for (int i = 0; i < strlen(text); i++) {
		if (text[i] == '\n')
			text[i] = '\0';
	}
}
void deleteBook(user** Book, int size) {
	for (int i = 0; i < size; i++) {
		delete Book[i];
	}
	delete Book;
}
user** addAbonent(user** Book, int& size) {
	user** TEMP = new user * [size + 1];
	for (int i = 0; i < size; i++) {
		TEMP[i] = Book[i];
	}

	cout << "Введите имя абонента: ";
	char* name = new char[100];
	gets_s(name, 100);

	cout << "Введите описание абонента: ";
	char* describe = new char[100];
	gets_s(describe, 100);

	cout << "Введите домашний номер абонента: ";
	char* homeTel = new char[100];
	gets_s(homeTel, 100);

	cout << "Введите рабочий номер абонента: ";
	char* workTel = new char[100];
	gets_s(workTel, 100);

	cout << "Введите телефонный номер абонента: ";
	char* phoneTel = new char[100];
	gets_s(phoneTel, 100);

	TEMP[size] = new user(name, describe, homeTel, workTel, phoneTel);
	size++;
	delete name;
	delete describe;
	delete homeTel;
	delete workTel;
	delete phoneTel;
	//deleteBook(Book, size);
	return TEMP;
}
void FindByName(user** Book, int size) {

	char* name = new char[100];
	cout << "\nВведите имя пользователя, который вас интересует: ";
	gets_s(name, 100);

	for (int i = 0; i < size; i++) {
		if (_stricmp(name, Book[i]->getName()) == 0) {
			cout << "\nИмя: " << Book[i]->getName() << "\tОписание: " << Book[i]->getDescribe();
			cout << "\nДомашний: " << Book[i]->getHomeTel() << "\tРабочий: " << Book[i]->getWorkTel() << "\t:Телефонный: " << Book[i]->getPhoneTel() << "\n";
		}
	}
}
void showBook(user** Book, int size) {
	for (int i = 0; i < size; i++) {
		cout << "\nИмя: " << Book[i]->getName() << "\tОписание: " << Book[i]->getDescribe();
		cout << "\nДомашний: " << Book[i]->getHomeTel() << "\tРабочий: " << Book[i]->getWorkTel() << "\t:Телефонный: " << Book[i]->getPhoneTel();
	}
}
void saveBook(user** Book, int size) {
	FILE* pf;

	fopen_s(&pf, "miniDataBase.txt", "wt");

	if (pf != nullptr) {

		fprintf(pf, "%i", size);

		for (int i = 0; i < size; i++) {
			fprintf(pf, "\n");
			fputs(Book[i]->getName(), pf);

			fprintf(pf, "\n");
			fputs(Book[i]->getDescribe(), pf);

			fprintf(pf, "\n");
			fputs(Book[i]->getHomeTel(), pf);

			fprintf(pf, "\n");
			fputs(Book[i]->getWorkTel(), pf);

			fprintf(pf, "\n");
			fputs(Book[i]->getPhoneTel(), pf);
		}
	}
	else {
		cout << "\nNullPointerException";
	}
	fclose(pf);
}
user** delAbonent(user** Book, int& size) {

	char* name = new char[100];
	cout << "\nВведите имя человека, которого хотите удалить: ";
	gets_s(name, 100);


	int f = 0;
	for (int i = 0; i < size; i++) {
		if (_stricmp(name, Book[i]->getName()) == 0) {
			for (int j = i; j < size - 1; j++) {
				Book[j] = Book[j + 1];
			}
			f++;
		}
	}

	user** TEMP = new user* [size - 1];
	for (int i = 0; i < size - 1; i++) {
		TEMP[i] = Book[i];
	}

	delete name;
	if (f == 0) {
		cout << "\nТакого абонента нет";
		deleteBook(TEMP,size-1);
		return Book;
	}
	else {
		cout << "\nАбонент удален";
		size--;
		return TEMP;
	}

}
void uploadBook(user**& Book, int& size) {
	FILE* pf;


	fopen_s(&pf, "miniDataBase.txt", "rt");

	if (pf != nullptr) {
		fscanf_s(pf, "%i\n", &size);

		Book = new user * [size];

		char* tmpName = new char[100];
		char* tmpDescr = new char[100];
		char* tmpHomeT = new char[100];
		char* tmpWorkT = new char[100];
		char* tmpPhoneT = new char[100];
		
		for (int i = 0; i < size; i++) {


			fgets(tmpName, 100, pf);
			deleteEndL(tmpName);

			fgets(tmpDescr, 100, pf);
			deleteEndL(tmpDescr);

			fgets(tmpHomeT, 100, pf);
			deleteEndL(tmpHomeT);

			fgets(tmpWorkT, 100, pf);
			deleteEndL(tmpWorkT);

			fgets(tmpPhoneT, 100, pf);
			deleteEndL(tmpPhoneT);

			Book[i] = new user(tmpName, tmpDescr, tmpHomeT, tmpWorkT, tmpPhoneT);
		}
		delete tmpName;
		delete tmpDescr;
		delete tmpHomeT;
		delete tmpWorkT;
		delete tmpPhoneT;
	}
	else {
		cout << "\nNullPointerException";
	}
	fclose(pf);

}
int main() {
	setlocale(LC_ALL, "");

	user** phoneBook = nullptr;
	int size = 0;

	int check;
	do {

		cout << "\tMenu";
		cout << "\n1 - Добавить абонента";
		cout << "\n2 - Удалить абонента";
		cout << "\n3 - Поиск абонента по имени";
		cout << "\n4 - Показать всех абонентов";
		cout << "\n5 - Сохранить данные";
		cout << "\n6 - Загрузить данные";
		cout << "\n0 - Выход";

		cout << "\n\nВаш выбор: ";
		cin >> check;
		cin.ignore();

		switch (check)
		{
		case 1:
			phoneBook = addAbonent(phoneBook, size);
			cout << "\nПользователь добавлен.\n";
			Sleep(2000);
			system("cls");
			break;
		case 2:
			phoneBook = delAbonent(phoneBook, size);
	
			Sleep(2000);
			system("cls");
			break;
		case 3:
			FindByName(phoneBook, size);
			system("pause");
			system("cls");
			break;
		case 4:
			showBook(phoneBook, size);
			cout << "\n";//чтобы надпись паузы не сливалась с списком
			system("pause");
			system("cls");
			break;
		case 5:
			saveBook(phoneBook, size);
			cout << "\nФайл сохранен.\n";
			Sleep(2000);
			system("cls");
			break;
		case 6:
			uploadBook(phoneBook, size);
			cout << "\nФайл загружен.\n";
			Sleep(2000);
			system("cls");
			break;
		}

	} while (check != 0);

	//Auto-Save
	if (size != 0) {
		//saveBook(phoneBook, size);
	}
}