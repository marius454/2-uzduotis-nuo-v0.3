// OOP uzduotis 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std::chrono;
void failu_kurimas(int m)
{
	std::ofstream fk("kursiokai.txt");
	int n = 5;
	std::cout << m << " mokiniu: " << std::endl;

	for (int i = 0; i < m; i++)
	{
		std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_int_distribution<int> dist(0, 10);
		fk << "Pavarde" << i + 1 << " Vardas" << i + 1 << " ";
		for (int j = 0; j < n + 1; j++)
			fk << dist(mt) << " ";
		if (i != m - 1)
			fk << std::endl;
	}
	fk.close();
}

bool acompare(studentai lhs, studentai rhs) { return lhs.pavarde < rhs.pavarde; }

int main()
{
	int t = 10;
	for (unsigned int k = 0; k < 5; k++) {
		auto start = high_resolution_clock::now();
		failu_kurimas(t);
		unsigned int m = 0, nd, nr;
		std::ifstream fd("kursiokai.txt");
		if (!fd)
		{
			std::cerr << "failas kursiokai.txt neegzistuoja" << std::endl;
			return 0;
		}
		std::ofstream fr("rezultatai.txt");
		std::vector<studentai> stud;
		/*std::cout << "pasirinkite:" << std::endl;
		std::cout << "1) ivesti duomenis is klaviaturos" << std::endl;
		std::cout << "2) nuskaityti duomenys is failo (kursiokai.txt)" << std::endl;
		std::cin >> nr;
		if (nr == 1)
		{
			std::cout << "iveskite kiek bus vedama mokiniu: ";
			std::cin >> m;
			std::cout << "iveskite kiek bus vedama nd pazymiu: ";
			std::cin >> nd;
			stud.reserve(m);
			for (unsigned int i = 0; i < m; i++)
			{
				studentai temp;
				std::cout << "iveskite " << i + 1 << "-ojo mokinio(es) pavarde: ";
				std::cin >> temp.pavarde;
				std::cout << "iveskite " << i + 1 << "-ojo mokinio(es) varda: ";
				std::cin >> temp.vardas;
				std::cout << "iveskite " << i + 1 << "-ojo mokinio(es) " << nd << " namu darbu pazymius:" << std::endl;
				for (unsigned int j = 0; j < nd; j++)
				{
					unsigned short int a;
					std::cin >> a;
					assert(a <= 10);
					temp.paz.push_back(a);
				}
				std::cout << "iveskite " << i + 1 << "-ojo mokinio egzamino bala: ";
				std::cin >> temp.egz;
				assert(temp.egz <= 10);
				stud.push_back(temp);
			}*/
			//}
			//else if (nr == 2)
			//{

		while (!fd.eof())
		{
			m++;
			studentai temp;
			fd >> temp.pavarde;
			fd >> temp.vardas;
			std::string str;
			getline(fd, str);
			std::istringstream is(str);
			unsigned short a;
			while (is >> a)
			{
				if (a <= 10)
					temp.paz.push_back(a);
				else
					std::cerr << "skaicius nera tarp 0 ir 10 todel bus praleidziamas";
			}
			temp.egz = temp.paz.back();
			stud.push_back(temp);
		}
		if (stud.size() == 0) { throw std::domain_error("studentu vektorius tuscias"); }
		for (unsigned int i = 0; i < m; i++)
		{
			if (stud[i].paz.size() == 0) { throw std::domain_error("nd pazymiu vektorius tuscias"); }
			int sum = 0;
			/*if (nr == 2)*/ nd = stud[i].paz.size() - 1;
			for (unsigned int j = 0; j < nd; j++)
			{
				sum = sum + stud[i].paz.at(j);
			}
			stud[i].vid = 0.4*(sum / nd) + 0.6*stud[i].egz;

		}
		

		for (unsigned int i = 0; i < m; i++)
			std::sort(stud[i].paz.begin(), stud[i].paz.end() - 1);

		for (unsigned int i = 0; i < m; i++)
		{
			/*if (nr == 2)*/ nd = stud[i].paz.size() - 1;
			if ((nd) % 2 != 0)
				stud[i].med = 0.4*stud[i].paz[nd / 2] + 0.6*stud[i].egz;
			else
			{
				double med = (stud[i].paz[nd / 2 - 1] + stud[i].paz[nd / 2]) / 2;
				stud[i].med = 0.4*med + 0.6*stud[i].egz;
			}
		}
		std::sort(stud.begin(), stud.end(), acompare);
		std::vector<studentai> less60;
		std::vector<studentai> more60;
		unsigned int m1 = 0, m2 = 0;
		for (unsigned int i = 0; i < m; i++)
		{
			if (stud[i].vid >= 6) {
				more60.push_back(stud[i]);
				m1++;
			}
			else {
				less60.push_back(stud[i]);
				m2++;
			}
		}

		fr << "			" << std::setw(20) << std::left << "Pavarde" << std::setw(20) << std::left << "Vardas" << std::setw(30) << "Galutinis-vidurkis" << "Galutinis-mediana" << std::endl;
		fr << "galvociai:" << std::endl;
		for (unsigned int i = 0; i < m1; i++)
		{
			fr << "			" << std::setw(20) << std::left << more60[i].pavarde << std::setw(20) << std::left << more60[i].vardas << std::setw(30);
			fr << std::fixed << std::setprecision(2) << more60[i].vid << more60[i].med << std::endl;
		}
		fr << "vargsiukai:" << std::endl;
		for (unsigned int i = 0; i < m2; i++)
		{
			fr << "			" << std::setw(20) << std::left << less60[i].pavarde << std::setw(20) << std::left << less60[i].vardas << std::setw(30);
			fr << std::fixed << std::setprecision(2) << less60[i].vid << less60[i].med << std::endl;
		}
		auto end = high_resolution_clock::now();
		std::cout << duration<double>(end - start).count() << "s\n";
		fd.close();
		fr.close();
		t *= 10;
	}
	return 0;
}
