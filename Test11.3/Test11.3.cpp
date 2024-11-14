#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab11.3/lab11.3.cpp"
#include <fstream>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test113
{
	TEST_CLASS(Test113)
	{
	public:

		// Додамо визначення функцій BackupFile та RestoreFile як приватних методів класу Test113
		void BackupFile(const std::string& filename, const std::string& backupFilename) {
			std::ifstream src(filename, std::ios::binary);
			std::ofstream dst(backupFilename, std::ios::binary);
			dst << src.rdbuf();
			src.close();
			dst.close();
		}

		void RestoreFile(const std::string& filename, const std::string& backupFilename) {
			std::ifstream src(backupFilename, std::ios::binary);
			std::ofstream dst(filename, std::ios::binary);
			dst << src.rdbuf();
			src.close();
			dst.close();
			std::remove(backupFilename.c_str());
		}

		TEST_METHOD(TestAddEmployee)
		{
			const std::string filename = "WORK.txt";
			const std::string backupFilename = "WORK_backup.txt";

			// Зберігаємо оригінальний файл
			BackupFile(filename, backupFilename);

			// Додаємо тестового співробітника
			// Тут викличте функцію AddEmployee для перевірки

			// Перевіряємо, що запис був доданий
			std::ifstream fin(filename);
			std::string lastLine;
			while (getline(fin, lastLine)) {} // Читаємо останній рядок
			fin.close();

			// Виконати перевірку на наявність даних (можна додати конкретні тести на значення)

			// Відновлюємо оригінальний файл
			RestoreFile(filename, backupFilename);
		}
	};
}
