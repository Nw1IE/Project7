#include <iostream>
#include <Windows.h>
#include <string>
#include <limits>
#include <iomanip>

#if defined(max)
#undef max
#endif


//������� ������
bool isAdmin = false;
int userCount = 2;
std::string* loginArr = new std::string[userCount]{ "Admin", "user" };
std::string* passwordArr = new std::string[userCount]{ "Admin", "user" };
//******************************************

// ���� ������ �������
int size = 10;
int* idArr = new int[size];
int* countArr = new int[size];
double* priceArr = new double[size];
std::string* nameArr = new std::string[size];
//*****************************************

// �����
double cash = 10000;
double eMoney = 0;
double cashMoney = 0;
/*******************************************/


//�������
void Start();
bool Login();
void ShopUserMenu();
void ShopAdminMenu();
void CreateStaticStorage();
void RefillStorage();
bool isStringDigit(std::string string);
void RemoveFromStorage();
void ChangePrice();

void ChangeStaff();
void AddEmloyee();
void StaffRedact();
void RemoveEmployee();

void StorageRedact();
void StorageReduct();

void AddProduct();
void RenameProduct();
void DeleteProduct();
void Selling();
void AddCheckItem();
void PrintCheck(double totalSum);
void Income();


template <typename ArrType>
void FillStorage(ArrType staticArr[], ArrType dynaminArr[], int size);

template<typename ArrType1>
void PrintStorage(ArrType1 dynaminArr[]);
void ShowStorage();

//���
int sizeCheck = 1;
int* countCheckArr = new int[sizeCheck];
double* priceCheckArr = new double[sizeCheck];
double* totalPriceCheckArr = new double[sizeCheck];
std::string* nameCheakArr = new std::string[sizeCheck];




/****************************************/

int main()
{
	Start();





	delete[] loginArr;
	delete[] passwordArr;
	delete[] idArr;
	delete[] nameArr;
	delete[] countArr;
	delete[] priceArr;
	delete[] countCheckArr;
	delete[]priceCheckArr;
	delete[] totalPriceCheckArr;

	return 0;
}
void ShopUserMenu();

//��������
void Start()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "\n\n\t\t��������� �������\t\n\n\n";
	if (Login() == true)
	{
		//std::cin.ignore(std::numeric_limits<std::streamsize>::max());
		if (isAdmin == true)
		{
			std::string choose;
			do
			{
				std::cout << "1- ������������ ������� �����\n2 - ��� ������� ����?\n";
				std::cout << "����: ";
				std::getline(std::cin, choose, '\n');

			} while (choose.size() > 1 || choose[0] < 49 || choose[0] > 50);

			if (choose == "1")
			{
				CreateStaticStorage();
			}
			else
			{
				//Dinamic cklad
			}

			ShopAdminMenu();
		}
		else
		{
			CreateStaticStorage();
			ShopUserMenu();
		}
	}


}

//�������������, ����
bool Login()
{
	while (true)
	{
		std::string login, pass;
		std::cout << "������� �����: ";
		std::getline(std::cin, login, '\n');
		std::cout << "������� ������: ";
		std::getline(std::cin, pass, '\n');

		if (login == loginArr[0] && pass == passwordArr[0])
		{
			std::cout << "����� ���������� " << loginArr[0] << '\n';
			isAdmin = true;
			return true;
		}

		for (int i = 1; i < userCount; i++)
		{
			if (login == loginArr[i] && pass == passwordArr[i])
			{
				std::cout << " ����� ���������� " << loginArr[i] << '\n';
				isAdmin = false;
				return  true;
			}
		}
		system("cls");
		std::cout << "������� ������ ����� ��� ������!\n\n";

	}
}

void ShopUserMenu()
{
	std::string choose;
	while (true)
	{
		do
		{
			std::cout << "1. ������ �������\n";
			std::cout << "2. �������� �����\n";
			std::cout << "3. ��������� �����\n";
			std::cout << "4. ������� �� ������\n";
			std::cout << "5. ����� �� �������\n\n";
			std::cout << "0. ������� �����\n\n\n";

			std::cout << "����: ";
			std::getline(std::cin, choose, '\n');
			system("cls");

		} while (choose.size() > 1 || choose[0] < 48 || choose[0] > 53);


		if (choose == "1")
		{
			Selling();
		}
		else if (choose == "2")
		{
			ShowStorage();
		}
		else if (choose == "3")
		{
			RefillStorage();
		}
		else if (choose == "4")
		{
			RemoveFromStorage();
		}
		else if (choose == "5")
		{
			Income();
		}
		else if (choose == "0")
		{
			system("cls");
			while (true)
			{
				std::cout << "1 - ������� �����\n2 - ������\n\n����: ";
				std::getline(std::cin, choose, '\n');
				if (isStringDigit(choose))
				{
					break;
				}
				else
				{
					std::cout << "\n\n������������ ����\n\n";
				}
			}
			if (std::stoi(choose) == 1)
			{
				Income();
				std::cout << "\n\t\t\t����� �������. �������\n\n";
				break;
			}
		}
		else
		{

		}


	}
}

// ��������� �����
void ShopAdminMenu()
{
	//��������� �����
	std::string choose;
	while (true)
	{
		do
		{
			std::cout << "1. ������ �������\n";
			std::cout << "2. �������� �����\n";
			std::cout << "3. ��������� �����\n";
			std::cout << "4. ������� �� ������\n";
			std::cout << "5. �������� ����\n";
			std::cout << "6. �������� �����\n";
			std::cout << "7. �������� ��������\n";
			std::cout << "8. ����� �� �������\n\n";
			std::cout << "0. ������� �����\n\n\n";

			std::cout << "����: ";
			std::getline(std::cin, choose, '\n');
			system("cls");

		} while (choose.size() > 1 || choose[0] < 48 || choose[0] > 56);


		if (choose == "1")
		{
			Selling();
		}
		else if (choose == "2")
		{
			ShowStorage();
		}
		else if (choose == "3")
		{
			RefillStorage();
		}
		else if (choose == "4")
		{
			RemoveFromStorage();
		}
		else if (choose == "5")
		{
			ChangePrice();
		}
		else if (choose == "6")
		{
			StorageReduct();
		}
		else if (choose == "7")
		{
			ChangeStaff();
		}
		else if (choose == "8")
		{
			Income();
		}
		else if (choose == "0")
		{
			system("cls");
			while (true)
			{
				std::cout << "1 - ������� �����\n2 - ������\n\n����: ";
				std::getline(std::cin, choose, '\n');
				if (isStringDigit(choose))
				{
					break;
				}
				else
				{
					std::cout << "\n\n������������ ����\n\n";
				}
			}
			if (std::stoi(choose) == 1)
			{
				Income();
				std::cout << "\n\t\t\t����� �������. �������\n\n";
				break;
			}
		}

		else
		{
			std::cerr << "Admin MenuErr";
		}

	}
}
void CreateStaticStorage()
{
	const int staticSize = 10;

	int idStaticArr[staticSize]{ 1,2,3,4,5,6,7,8,9,10 };

	std::string nameStaticArr[staticSize]
	{
		"������������ �������", "������-��������", "������������", "�����������",
			"����������� �������", "�������� �������", "�������� ��������", "������� �������",
			"������� �������", "C��������"
	};

	int countStaticArr[staticSize]{ 1, 3, 5, 7, 9, 11,13, 6, 11, 12 };
	double priceStaticArr[staticSize]{ 1804.99, 719.99, 479.0, 480.0, 500.0, 417.0, 1500.0, 150.0, 180.0,  407.0 };

	FillStorage(idStaticArr, idArr, staticSize);
	FillStorage(nameStaticArr, nameArr, staticSize);
	FillStorage(countStaticArr, countArr, staticSize);
	FillStorage(priceStaticArr, priceArr, staticSize);

}

void RefillStorage()
{
	std::string idStr, addStr, choose;
	int id{}, add;
	bool exit = false;
	while (!exit)
	{
		while (true)
		{
			std::cout << "���������� ������\n������� id ������ : ";
			std::getline(std::cin, idStr, '\n');
			if (std::isdigit(idStr[0]) && idStr.size() == 1)
			{
				id = std::stoi(idStr);
			}
			else if (std::isdigit(idStr[0]) &&
				std::isdigit(idStr[1]) && idStr.size() == 2)
			{
				id = std::stoi(idStr);
			}
			else
			{
				std::cout << "������ �����\n";
			}

			if (id > 0 && id <= size)
			{

				system("cls");
				break;
			}
			else
			{
				std::cout << "�������� ID\n";
			}
		}


		std::cout << "\n\n" << idArr[id - 1] << " " << nameArr[id - 1] << "\n\n";

		while (true)
		{
			std::cout << "������� ���-�� ������� �� ����������: ";
			std::getline(std::cin, addStr, '\n');

			if (isStringDigit(addStr))
			{
				add = std::stoi(addStr);

				if (add >= 0 && add < 500)
				{
					break;
				}

				else
				{
					std::cout << "������������ ���-��\n\n";
				}

			}
		}

		while (true)
		{
			std::cout << "�������� " << add << " ������(��) " << nameArr[id - 1] << "?";
			std::cout << "1 - ��\t2 - ���\t3 - ������\n\n";
			std::getline(std::cin, choose, '\n');
			if (choose == "1")
			{
				countArr[id - 1] += add;
				std::cout << "����� ������� ��������\n\n";
				exit = true;
				break;
			}
			else if (choose == "2")
			{
				break;
			}
			else if (choose == "3")
			{
				exit = true;
				break;
			}
			else
			{
				std::cout << "������ �����\n\n";
			}
		}




	}



}

bool isStringDigit(std::string string)
{
	for (int i = 0; i < string.size(); i++)
	{
		if (!std::isdigit(string[i]))
		{
			return false;
		}
		return true;
	}
}

void ShowStorage()
{
	std::cout << "ID\t��������\t\t���-��\t����\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << idArr[i] << "\t" << std::left << std::setw(20) << nameArr[i] << "\t"
			<< countArr[i] << "\t" << priceArr[i] << "\n";
	}
}

template<typename ArrType>
void FillStorage(ArrType staticArr[], ArrType dynamincArr[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		dynamincArr[i] = staticArr[i];
	}
}

template<typename ArrType1>
void PrintStorage(ArrType1 dynamicArr[])
{
	for (int i = 0; i < size; i++)
	{
		std::cout << dynamicArr[i] << " ";
	}
	std::cout << "\n";
}

void RemoveFromStorage()
{
	std::string idStr, removeStr, choose;
	int id{}, remove{};
	bool exit = false;
	while (!exit)
	{
		while (true)
		{
			std::cout << "���������� ������\n������� id ������ : ";
			std::getline(std::cin, idStr, '\n');
			if (std::isdigit(idStr[0]) && idStr.size() == 1)
			{
				id = std::stoi(idStr);
			}
			else if (std::isdigit(idStr[0]) &&
				std::isdigit(idStr[1]) && idStr.size() == 2)
			{
				id = std::stoi(idStr);
			}
			else
			{
				std::cout << "������ �����\n";
			}

			if (id > 0 && id <= size)
			{

				system("cls");
				break;
			}
			else
			{
				std::cout << "�������� ID\n";
			}
		}


		std::cout << "\n\n" << idArr[id - 1] << " " << nameArr[id - 1] << "\n\n";

		while (true)
		{
			std::cout << "������� ���-�� ������� �� ����������: ";
			std::getline(std::cin, removeStr, '\n');

			if (isStringDigit(removeStr))
			{
				removeStr = std::stoi(removeStr);

				if (remove >= 0 && remove < 500)
				{
					break;
				}

				else
				{
					std::cout << "������������ ���-��\n\n";
				}

			}
		}

		while (true)
		{
			std::cout << "��������� " << remove << " ������(��) " << nameArr[id - 1] << "?";
			std::cout << "1 - ��\t2 - ���\t3 - ������\n\n";
			std::getline(std::cin, choose, '\n');
			if (choose == "1")
			{
				countArr[id - 1] -= remove;
				std::cout << "����� ������� ������\n\n";
				exit = true;
				break;
			}
			else if (choose == "2")
			{
				break;
			}
			else if (choose == "3")
			{
				exit = true;
				break;
			}
			else
			{
				std::cout << "������ �����\n\n";
			}
		}

	}
}



void ChangePrice() {
	system("cls");
	ShowStorage();
	std::cout << "\n\n\n";
	std::string idStr, changeStr, choose;
	int id{};
	double change{};
	bool exit = false;

	while (!exit)
	{

		while (true)
		{
			std::cout << "��������� ���� ������\n������� id ������: ";
			std::getline(std::cin, idStr, '\n');

			if (std::isdigit(idStr[0]) && idStr.size() == 1)
			{
				id = std::stoi(idStr);

			}
			else if (std::isdigit(idStr[0]) && std::isdigit(idStr[1]) && idStr.size() == 2)
			{
				id = std::stoi(idStr);

			}
			else
			{
				std::cout << "������ �����";

			}
			if (id > 0 && id <= size)
			{
				system("cls");
				break;
			}
			else
			{
				std::cout << "������ �����";
			}
		}
		std::cout << "\n\n" << idArr[id - 1] << " " << nameArr[id - 1] << "\n ���� ������: " << priceArr[id - 1] << "\n\n";

		while (true)
		{
			std::cout << "������� ����� ������: ";
			std::getline(std::cin, changeStr, '\n');
			if (isStringDigit(changeStr))
			{
				change = std::stoi(changeStr);
			}
			if (change >= 0 && change <= 9999)
			{
				break;
			}
			else
			{
				std::cout << "������ �����";
			}
		}
		while (true)
		{

			std::cout << "��������� ������ " << nameArr[id - 1] << " ����� ����" << "?\n";
			std::cout << "1 - ��\t\t2 - ���\t\t3 - ������\n\n";
			std::getline(std::cin, choose, '\n');

			if (choose == "1")
			{
				priceArr[id - 1] = (change + 0.99);
				std::cout << "���� ������� �����������\n\n";
				exit = true;
				break;
			}
			if (choose == "2")
			{
				break;
			}
			if (choose == "3")
			{
				exit = true;
				break;
			}
			else
			{
				std::cerr << "������ �����";
			}
		}

	}
}

void ChangeStaff()
{
	std::string choose;

	while (true)
	{
		std::cout << "\n\n1. �������� ������ ����������\n2. ��������������� ����������\n3. ������� ����������\n0. �����\n\n����:";
		std::getline(std::cin, choose, '\n');

		if (choose == "1")
		{
			AddEmloyee();
		}
		if (choose == "2")
		{
			StaffRedact();
		}
		if (choose == "3")
		{
			RemoveEmployee();
		}
		if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\nuser ��������\n";
		}
	}

	for (int i = 0; i < userCount; i++)
	{
		std::cout << loginArr[i] << " " << passwordArr[i] << "\n";
	}

}

void AddEmloyee()
{
	std::string* tempLogin = new std::string[userCount];
	std::string* tempPass = new std::string[userCount];
	for (int i = 0; i < userCount; i++)
	{
		tempLogin[i] = loginArr[i];
		tempPass[i] = passwordArr[i];
	}
	delete[]loginArr;
	delete[]passwordArr;

	userCount++;

	loginArr = new std::string[userCount];
	passwordArr = new std::string[userCount];

	for (int i = 0; i < userCount - 1; i++)
	{
		loginArr[i] = tempLogin[i];
		passwordArr[i] = tempPass[i];
	}


	std::string newLogin, newPass;
	std::cout << "������� ����� ������ ����������: ";
	std::getline(std::cin, newLogin, '\n');
	std::cout << "������� ������ ������ ����������: ";
	std::getline(std::cin, newPass, '\n');


	loginArr[userCount - 1] = newLogin;
	passwordArr[userCount - 1] = newPass;

	delete[]tempLogin;
	delete[]tempPass;
}

void StaffRedact()
{
	std::string chooseID, newlogin, newPass;
	int empId;
	while (true)
	{
		std::cout << "ID\t�����\t������\n";
		for (int i = 0; i < userCount; i++)
		{
			std::cout << i + 1 << "\t" << std::left << std::setw(10) << loginArr[i] << "\t" << passwordArr[i] << "\n";
		}
		std::cout << "������� ID ����������\t 0 - �����\n����: ";
		std::getline(std::cin, chooseID, '\n');

		if (chooseID == "0")
		{
			break;
		}
		else if (isStringDigit(chooseID) && chooseID != "1")
		{
			empId = std::stoi(chooseID);
			for (int i = 0; i < userCount; i++)
			{
				if (i == empId - 1)
				{
					std::cout << "������� ����� ����� ����������: ";
					std::getline(std::cin, newlogin, '\n');
					std::cout << "������� ����� ������ ����������: ";
					std::getline(std::cin, newPass, '\n');

					loginArr[i] = newlogin;
					passwordArr[i] = newPass;
					break;
				}
			}

		}
		else
		{
			std::cout << "\n\n������ �����!\n\n";
		}
	}

}

void RemoveEmployee()
{
	std::string chooseId;
	int empId{};
	while (true)
	{
		std::cout << "������� ID ���������� ��� ��������: ";
		std::getline(std::cin, chooseId, '\n');
		if (chooseId == "0")
		{
			break;
		}
		else if (isStringDigit(chooseId))
		{
			empId = std::stoi(chooseId);

			std::string* tempLogin = new std::string[userCount];
			std::string* tempPass = new std::string[userCount];
			for (int i = 0; i < userCount; i++)
			{
				tempLogin[i] = loginArr[i];
				tempPass[i] = passwordArr[i];
			}

			delete[]loginArr;
			delete[]passwordArr;
			userCount--;
			loginArr = new std::string[userCount];
			passwordArr = new std::string[userCount];

			for (int i = 0, j = 0; i < userCount, j < userCount; i++, j++)
			{
				if (i == empId - 1)
				{
					i++;
					loginArr[i] = tempLogin[i];
					passwordArr[i] = tempPass[i];
				}
				else
				{
					loginArr[j] = tempLogin[i];
					passwordArr[j] = tempPass[i];
				}
			}

			break;
		}
		else
		{
			std::cout << "\n\n������ �����\n\n";
		}

	}


}

void StorageRedact()
{
	std::string choose;
	std::cout << "��������� ������ ��������\n\n";

	while (true)
	{
		std::cout << "1 - �������� ����� �����\n2 - �������� �������� ������\n3 - �������� ������\n0 - �����\n\n����: ";
		std::getline(std::cin, choose, '\n');
		if (choose == "0")
		{
			break;
		}
		else if (choose == "1")
		{
			AddProduct();
			break;
		}
		else if (choose == "2")
		{
			RenameProduct();
			break;
		}
		else if (choose == "3")
		{
			DeleteProduct();
			break;
		}
		else
		{

			std::cout << "\n\n������������ ����\n\n";
		}
	}



}

void AddProduct()
{
	std::string choose;
	while (true)
	{
		std::cout << "1 - �������� ����� �����\t0 - �����\n\n����: ";
		std::getline(std::cin, choose, '\n');
		if (choose == "0")
		{
			break;
		}
		else if (choose == "1")
		{
			int* tempId = new int[size];
			int* tempCount = new int[size];
			double* tempPrice = new double[size];
			std::string* tempName = new std::string[size];
			for (int i = 0; i < size; i++)
			{
				tempId[i] = idArr[i];
				tempCount[i] = countArr[i];
				tempPrice[i] = priceArr[i];
				tempName[i] = nameArr[i];
			}

			delete[] idArr;
			delete[] countArr;
			delete[] priceArr;
			delete[] nameArr;

			size++;

			int* countCheckArr = new int[sizeCheck];
			double* priceCheckArr = new double[sizeCheck];
			double* totalpriceCheckArr = new double[sizeCheck];
			std::string* nameCheckArr = new std::string[sizeCheck];

			idArr = new int[size];
			countArr = new int[size];
			priceArr = new double[size];
			nameArr = new std::string[size];

			for (int i = 0; i < size - 1; i++)
			{
				idArr[i] = tempId[i];
				countArr[i] = tempCount[i];
				priceArr[i] = tempPrice[i];
				nameArr[i] = tempName[i];
			}

			std::string newName, newCountStr, newPriceStr;

			while (true)
			{
				std::cout << "������� �������� ������ ������: ";
				std::getline(std::cin, newName, '\n');
				if (newName.size() <= 30)
				{
					nameArr[size - 1] = newName;
					break;
				}
				else
				{
					std::cout << "\n\n������� ������� ��������\n\n";
				}
			}

			while (true)
			{
				std::cout << "������� ���-�� ������ ������: ";
				std::getline(std::cin, newCountStr, '\n');
				if (isStringDigit(newCountStr))
				{
					if (std::stoi(newCountStr) >= 0 && std::stoi(newCountStr) < 1000)
					{
						countArr[size - 1] = std::stoi(newCountStr);
						break;
					}
				}
				else
				{
					std::cout << "\n\n������������ ����\n\n";
				}

				while (true)
				{
					std::cout << "������� ���� ������ ������: ";
					std::getline(std::cin, newPriceStr, '\n');
					if (isStringDigit(newPriceStr))
					{
						if (std::stod(newPriceStr) >= 0 && std::stod(newPriceStr) < 1000)
						{
							priceArr[size - 1] = std::stod(newPriceStr);
							break;
						}
					}
					else
					{
						std::cout << "\n\n������������ ����\n\n";
					}
				}
				idArr[size - 1] = size;

				std::cout << "\n\t��������\t���-��\t����";
				std::cout << "\n\n" << idArr[size - 1] << "\t" << std::left << std::setw(10)
					<< nameArr[size - 1] << "\t" << countArr[size - 1] << "\t"
					<< priceArr[size - 1] << "\n\n����� ����� ������� �������� �� �����\n\n";
			}
			delete[] tempId;
			delete[] tempCount;
			delete[] tempPrice;
			delete[] tempName;
		}
		else
		{
			std::cout << "\n\n����������� ����\n\n";
		}
	}
}

void StorageReduct()
{
	std::string choose;
	std::cout << "��������� ������ ��������\n\n";

	while (true)
	{
		std::cout << "1. �������� ����� �����\t2. �������� �������� ������\t3. �������� ������\n 0 - �����\n����: ";
		std::getline(std::cin, choose, '\n');
		if (choose == "0")
		{
			break;
		}
		else if (choose == "1")
		{
			AddProduct();
		}
		else if (choose == "2")
		{
			RenameProduct();
		}
		else if (choose == "3")
		{
			DeleteProduct();
		}
		else
		{
			std::cout << "����������� ����\n\n";
		}
	}
}

void RenameProduct()
{
	std::string choose;
	std::string idStr, newName;
	int id{};
	while (true)
	{
		std::cout << "1 - �������� ��������\t0 - �����\n����: ";
		std::getline(std::cin, choose, '\n');

		if (choose == "0")
		{
			break;
		}
		else if (choose == "1")
		{
			while (true)
			{
				std::cout << "������� ID: ";
				std::getline(std::cin, idStr, '\n');

				if (isStringDigit(idStr))
				{
					id = std::stoi(idStr);
					if (id > 0 && id <= size)
					{
						break;
					}
					else
					{
						std::cout << "������������ ID!!\n\n";
					}
				}
			}
			while (true)
			{
				std::cout << "\n\n" << idArr[id - 1] << "\t" << std::left << std::setw(30) << nameArr[id - 1] << "\n\n";
				std::cout << "������� ����� �������� ������: ";
				std::getline(std::cin, newName, '\n');
				if (newName.size() <= 30)
				{
					nameArr[id - 1] = newName;
					break;
				}
				else
				{
					std::cout << "������������ ����� �������� 30 ��������\n\n";
				}
			}

			std::cout << "\n\n" << idArr[id - 1] << "\t" << std::left << std::setw(30) << nameArr[id - 1] << "\t" <<
				countArr[id - 1] << "\t" << priceArr[id - 1] << "\n" << "�������� ������ ��������\n\n";

		}
		else
		{
			std::cout << "������������ ����!!\n\n";
		}
	}


}

void DeleteProduct()
{
	std::string choose;
	while (true)
	{
		std::cout << "1. ������� �����\t0 - �����\n����: ";
		std::getline(std::cin, choose, '\n');
		if (choose == "0")
		{
			break;
		}
		else if (choose == "1")
		{
			std::string idStr, newName;
			int id{};

			while (true)
			{
				std::cout << "������� ID ������: ";
				std::getline(std::cin, idStr, '\n');

				if (isStringDigit(idStr))
				{
					id = std::stoi(idStr);
					if (id > 0 && id <= size)
					{
						break;
					}
					else
					{
						std::cout << "������������ ID!!\n\n";
					}
				}
				else
				{
					std::cout << "\n������������ ����\n\n";
				}
			}



			int* tempId = new int[size];
			int* tempCount = new int[size];
			double* tempPrice = new double[size];
			std::string* tempName = new std::string[size];
			for (int i = 0; i < size; i++)
			{
				tempId[i] = idArr[i];
				tempCount[i] = countArr[i];
				tempPrice[i] = priceArr[i];
				tempName[i] = nameArr[i];
			}


			delete[]idArr;
			delete[]countArr;
			delete[]priceArr;
			delete[]nameArr;

			size--;
			idArr = new int[size];
			countArr = new int[size];
			priceArr = new double[size];
			nameArr = new std::string[size];


			for (int i = 0, j = 0; i < size, j < size; i++, j++)
			{
				if (i == id - 1)
				{
					i++;
					idArr[j] = tempId[j];
					countArr[j] = tempCount[i];
					priceArr[j] = tempPrice[i];
					nameArr[j] = tempName[i];
				}
				else
				{
					idArr[j] = tempId[j];
					countArr[j] = tempCount[i];
					priceArr[j] = tempPrice[i];
					nameArr[j] = tempName[i];
				}
			}


			delete[]tempId;
			delete[]tempCount;
			delete[]tempPrice;
			delete[]tempName;

			break;
		}
	}
}

void Selling()
{
	std::string chooseId, chooseCount, choosePayPal, userCash;
	int id{}, count{};
	bool isFirst = true;
	int sizeCheck = 1;
	double totalSum = 0;
	sizeCheck = 1;


	delete[]priceCheckArr;
	delete[]countCheckArr;
	delete[]totalPriceCheckArr;
	delete[]nameCheakArr;

	priceCheckArr = new double[sizeCheck];
	countCheckArr = new int[sizeCheck];
	totalPriceCheckArr = new double[sizeCheck];
	nameCheakArr = new std::string[sizeCheck];

	while (true)
	{
		system("cls");
		ShowStorage();
		std::cout << "������� ID ������ ��� �������\n0 ��� ������: ";
		std::getline(std::cin, chooseId, '\n');
		if (!isStringDigit(chooseId))
		{
			std::cout << "\n�������� ID\n";
			continue;
		}
		else
		{
			id = std::stoi(chooseId);
			if (id == 0)
			{
				if (!isFirst)
				{
					PrintCheck(totalSum);
					while (true)
					{

						std::cout << "�������� ������ ������:\n1 - ��������\n2 - ������\n����: ";
						std::getline(std::cin, choosePayPal, '\n');
						if (!isStringDigit(choosePayPal))
						{
							std::cout << "������������ ����\n\n";
						}
						else
						{
							if (std::stoi(choosePayPal) == 1)
							{
								while (true)
								{
									std::cout << "������� ����� ��������: ";
									std::getline(std::cin, userCash, '\n');
									if (!isStringDigit(userCash))

									{
										std::cout << "������������ ����\n\n";


									}
									else
									{
										if (std::stod(userCash) < totalSum)
										{
											std::cout << "������������ �������\n\n";
										}
										else if (cash >= std::stod(userCash) - totalSum)
										{
											std::cout << "\n\n����: " << std::stod(userCash)
												<< "\n\n������ ������ �������\n" << "�����: "
												<< std::stod(userCash) - totalSum << " ���\n\n";
											cashMoney = totalSum;
											cash += std::stod(userCash);
											cash -= std::stod(userCash) - totalSum;
											break;

										}
									}
								}

							}
							else if (std::stoi(choosePayPal) == 2)
							{
								std::cout << "������ ������ �������\n";
								eMoney += totalSum;
								break;
							}
							else
							{
								std::cout << "������������ ����!!\n\n";
							}
							break;
						}
					}
					break;
				}
				else
				{
					break;
				}
			}
			else if (id > 0 && id <= size)
			{
				while (true)
				{
					std::cout << "������� ���������� ������ " << nameArr[id - 1] << ": ";
					std::getline(std::cin, chooseCount, '\n');
					if (!isStringDigit(chooseCount))
					{
						std::cout << "\n\n������������ ����\n\n";
						continue;
					}
					else
					{
						count = std::stoi(chooseCount);
						if (count > 0 && count <= countArr[id - 1])
						{
							std::cout << std::left << std::setw(30) << nameArr[id - 1] << " " << count << " �������� � ���\n\n";
							if (isFirst)
							{
								priceCheckArr[sizeCheck - 1] = priceArr[id - 1];
								nameCheakArr[sizeCheck - 1] = nameArr[id - 1];
								totalPriceCheckArr[sizeCheck - 1] = priceArr[id - 1] * count;
								countCheckArr[sizeCheck - 1] = count;
								totalSum += totalPriceCheckArr[sizeCheck - 1];
								isFirst = false;
								countArr[id - 1] -= count;
							}
							else
							{
								AddCheckItem();
								priceCheckArr[sizeCheck - 1] = priceArr[id - 1];
								nameCheakArr[sizeCheck - 1] = nameArr[id - 1];
								totalPriceCheckArr[sizeCheck - 1] = priceArr[id - 1] * count;
								countCheckArr[sizeCheck - 1] = count;
								totalSum += totalPriceCheckArr[sizeCheck - 1];
								countArr[id - 1] -= count;
							}
							break;
						}
						else
						{
							std::cout << "\n\n������������ ���-��\n\n";
							break;
						}
					}
				}
			}
			else
			{
				std::cout << "\n\n������������ ����\n\n";
				break;
			}
		}
	}
}

void AddCheckItem()
{
	double* tempPriceCheck = new double[sizeCheck];
	int* tempCountCheck = new int[sizeCheck];
	double* tempTotalPriceCheck = new double[sizeCheck];
	std::string* tempNameCheck = new std::string[sizeCheck];
	for (int i = 0; i < sizeCheck; i++)
	{
		tempPriceCheck[i] = priceCheckArr[i];
		tempCountCheck[i] = countCheckArr[i];
		tempTotalPriceCheck[i] = totalPriceCheckArr[i];
		tempNameCheck[i] = nameCheakArr[i];
	}


	delete[]priceCheckArr;
	delete[]countCheckArr;
	delete[]totalPriceCheckArr;
	delete[]nameCheakArr;

	sizeCheck++;
	countCheckArr = new int[sizeCheck];
	priceCheckArr = new double[sizeCheck];
	totalPriceCheckArr = new double[sizeCheck];
	nameCheakArr = new std::string[sizeCheck];


	for (int i = 0; i < sizeCheck - 1; i++)
	{
		priceCheckArr[i] = tempPriceCheck[i];
		countCheckArr[i] = tempCountCheck[i];
		totalPriceCheckArr[i] = tempTotalPriceCheck[i];
		nameCheakArr[i] = tempNameCheck[i];
	}

	delete[]tempPriceCheck;
	delete[]tempCountCheck;
	delete[]tempTotalPriceCheck;
	delete[]tempNameCheck;
}

void PrintCheck(double totalSum)
{
	int sizeCheck = 1;
	std::cout << "�\t��������\t\t\t����������\t���� �� ��\t�����\n";
	for (int i = 0; i < sizeCheck; i++)
	{
		std::cout << i + 1 << "\t" << std::left << std::setw(30) << nameCheakArr[i] << "\t\t" << countCheckArr[i] << "\t" << priceCheckArr[i] << "\t\t" << totalPriceCheckArr[i] << "\n\n";
	}
	std::cout << "\n\n\t�������� �����: " << totalSum << " ������\n\n\n";
}

void Income()
{
	std::cout << "\t\t����� � �������\n\n";
	std::cout << "������� �� �������� �������:\t\t" << cashMoney << "\n";
	std::cout << "������� �� ����������� ������: \t\t" << eMoney << "\n";
	std::cout << "�������� � �����:\t\t\t" << cash << "\n\n";
	std::cout << "�������� �������:\t\t\t" << cashMoney + eMoney << "\n";
}


