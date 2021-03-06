// stdafx.cpp : source file that includes just the standard includes
// OOP uzduotis 2.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"
using namespace std::chrono;

void vectorveiksmai(std::vector<studentai>& stud, unsigned short int nr, unsigned int nd)
{
	unsigned int m = 0, m1 = 0, m2 = 0;
	std::vector<studentai> less60;
	std::vector<studentai> more60;
	std::cout << "laikas naudojant vectorius: ";
	if (stud.size() == 0) { throw std::domain_error("studentu vektorius tuscias"); }
	m = stud.size();
	for (unsigned int i = 0; i < m; i++)
	{
		int sum = 0;
		if (nr == 2) nd = stud[i].paz.size() - 1;
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
		if (nr == 2) nd = stud[i].paz.size() - 1;
		if ((nd) % 2 != 0)
			stud[i].med = 0.4*stud[i].paz[nd / 2] + 0.6*stud[i].egz;
		else
		{
			double med = (stud[i].paz[nd / 2 - 1] + stud[i].paz[nd / 2]) / 2;
			stud[i].med = 0.4*med + 0.6*stud[i].egz;
		}
	}

	//std::sort(stud.begin(), stud.end(), acompare);
	auto start = high_resolution_clock::now();

	std::copy_if(stud.begin(), stud.end(), back_inserter(more60), maziau);
	std::copy_if(stud.begin(), stud.end(), back_inserter(less60), daugiau);

	auto end = high_resolution_clock::now();
	std::cout << duration<double>(end - start).count() << "s\n";

	std::ofstream fr("rezultatai.txt");
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
}

void listveiksmai(std::list<studentai>& stud1, unsigned short int nr, unsigned int nd)
{
	std::cout << "laikas naudojant listus: ";
	unsigned int m = 0;
	if (stud1.size() == 0) { throw std::domain_error("studentu vektorius tuscias"); }
	for (std::list<studentai>::iterator it = stud1.begin(); it != stud1.end(); ++it)
	{
		if ((*it).paz.size() == 0) { throw std::domain_error("nd pazymiu vektorius tuscias"); }
		int sum = 0;
		if (nr == 2) nd = (*it).paz.size() - 1;
		for (unsigned int j = 0; j < nd; j++)
		{
			sum = sum + (*it).paz.at(j);
		}
		(*it).vid = 0.4*(sum / nd) + 0.6*(*it).egz;
	}

	for (std::list<studentai>::iterator it = stud1.begin(); it != stud1.end(); ++it)
		std::sort((*it).paz.begin(), (*it).paz.end() - 1);

	for (std::list<studentai>::iterator it = stud1.begin(); it != stud1.end(); ++it)
	{
		if (nr == 2) nd = (*it).paz.size() - 1;
		if ((nd) % 2 != 0)
			(*it).med = 0.4*(*it).paz[nd / 2] + 0.6*(*it).egz;
		else
		{
			double med = ((*it).paz[nd / 2 - 1] + (*it).paz[nd / 2]) / 2;
			(*it).med = 0.4*med + 0.6*(*it).egz;
		}
	}
	//stud1.sort(acompare);
	std::list<studentai> more60, less60;

	auto start = high_resolution_clock::now();

	std::copy_if(stud1.begin(), stud1.end(), back_inserter(more60), maziau);
	std::copy_if(stud1.begin(), stud1.end(), back_inserter(less60), daugiau);

	auto end = high_resolution_clock::now();
	std::cout << duration<double>(end - start).count() << "s\n";

	std::ofstream fr("rezultatai.txt");
	fr << "			" << std::setw(20) << std::left << "Pavarde" << std::setw(20) << std::left << "Vardas" << std::setw(30) << "Galutinis-vidurkis" << "Galutinis-mediana" << std::endl;
	fr << "galvociai:" << std::endl;
	for (std::list<studentai>::iterator it = more60.begin(); it != more60.end(); ++it)
	{
		fr << "			" << std::setw(20) << std::left << (*it).pavarde << std::setw(20) << std::left << (*it).vardas << std::setw(30);
		fr << std::fixed << std::setprecision(2) << (*it).vid << (*it).med << std::endl;
	}
	fr << "vargsiukai:" << std::endl;
	for (std::list<studentai>::iterator it = less60.begin(); it != less60.end(); ++it)
	{
		fr << "			" << std::setw(20) << std::left << (*it).pavarde << std::setw(20) << std::left << (*it).vardas << std::setw(30);
		fr << std::fixed << std::setprecision(2) << (*it).vid << (*it).med << std::endl;
	}
}

void dequeveiksmai(std::deque<studentai>& stud1, unsigned short int nr, unsigned int nd)
{
	std::cout << "laikas naudojant dekus: ";
	unsigned int m = 0;
	if (stud1.size() == 0) { throw std::domain_error("studentu vektorius tuscias"); }
	for (std::deque<studentai>::iterator it = stud1.begin(); it != stud1.end(); ++it)
	{
		if ((*it).paz.size() == 0) { throw std::domain_error("nd pazymiu vektorius tuscias"); }
		int sum = 0;
		if (nr == 2) nd = (*it).paz.size() - 1;
		for (unsigned int j = 0; j < nd; j++)
		{
			sum = sum + (*it).paz.at(j);
		}
		(*it).vid = 0.4*(sum / nd) + 0.6*(*it).egz;
	}

	for (std::deque<studentai>::iterator it = stud1.begin(); it != stud1.end(); ++it)
		std::sort((*it).paz.begin(), (*it).paz.end() - 1);

	for (std::deque<studentai>::iterator it = stud1.begin(); it != stud1.end(); ++it)
	{
		if (nr == 2) nd = (*it).paz.size() - 1;
		if ((nd) % 2 != 0)
			(*it).med = 0.4*(*it).paz[nd / 2] + 0.6*(*it).egz;
		else
		{
			double med = ((*it).paz[nd / 2 - 1] + (*it).paz[nd / 2]) / 2;
			(*it).med = 0.4*med + 0.6*(*it).egz;
		}
	}

	//std::sort(stud1.begin(), stud1.end(), acompare);
	std::deque<studentai> more60, less60;

	auto start = high_resolution_clock::now();

	std::copy_if(stud1.begin(), stud1.end(), back_inserter(more60), maziau);
	std::copy_if(stud1.begin(), stud1.end(), back_inserter(less60), daugiau);

	auto end = high_resolution_clock::now();
	std::cout << duration<double>(end - start).count() << "s\n";

	std::ofstream fr("rezultatai.txt");
	fr << "			" << std::setw(20) << std::left << "Pavarde" << std::setw(20) << std::left << "Vardas" << std::setw(30) << "Galutinis-vidurkis" << "Galutinis-mediana" << std::endl;
	fr << "galvociai:" << std::endl;
	for (std::deque<studentai>::iterator it = more60.begin(); it != more60.end(); ++it)
	{
		fr << "			" << std::setw(20) << std::left << (*it).pavarde << std::setw(20) << std::left << (*it).vardas << std::setw(30);
		fr << std::fixed << std::setprecision(2) << (*it).vid << (*it).med << std::endl;
	}
	fr << "vargsiukai:" << std::endl;
	for (std::deque<studentai>::iterator it = less60.begin(); it != less60.end(); ++it)
	{
		fr << "			" << std::setw(20) << std::left << (*it).pavarde << std::setw(20) << std::left << (*it).vardas << std::setw(30);
		fr << std::fixed << std::setprecision(2) << (*it).vid << (*it).med << std::endl;
	}
}

void vectorveiksmai2(std::vector<studentai>& stud, unsigned short int nr, unsigned int nd)
{
	std::cout << std::endl << "2 strategija :" << std::endl;
	unsigned int m = 0, m1 = 0, m2 = 0;
	std::vector<studentai> less60;
	std::cout << "laikas naudojant vectorius: ";
	if (stud.size() == 0) { throw std::domain_error("studentu vektorius tuscias"); }
	m = stud.size();
	for (unsigned int i = 0; i < m; i++)
	{
		if (stud[i].paz.size() == 0) { throw std::domain_error("nd pazymiu vektorius tuscias"); }
		int sum = 0;
		if (nr == 2) nd = stud[i].paz.size() - 1;
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
		if (nr == 2) nd = stud[i].paz.size() - 1;
		if ((nd) % 2 != 0)
			stud[i].med = 0.4*stud[i].paz[nd / 2] + 0.6*stud[i].egz;
		else
		{
			double med = (stud[i].paz[nd / 2 - 1] + stud[i].paz[nd / 2]) / 2;
			stud[i].med = 0.4*med + 0.6*stud[i].egz;
		}
	}
	//std::sort(stud.begin(), stud.end(), acompare);
	auto start = high_resolution_clock::now();

	std::remove_copy_if(stud.begin(), stud.end(), back_inserter(less60), daugiau);
	stud.erase(remove_if(stud.begin(), stud.end(), maziau), stud.end());

	auto end = high_resolution_clock::now();
	std::cout << duration<double>(end - start).count() << "s\n";

	std::ofstream fr("rezultatai.txt");
	fr << "			" << std::setw(20) << std::left << "Pavarde" << std::setw(20) << std::left << "Vardas" << std::setw(30) << "Galutinis-vidurkis" << "Galutinis-mediana" << std::endl;
	fr << "galvociai:" << std::endl;
	for (unsigned int i = 0; i < stud.size(); i++)
	{
		fr << "			" << std::setw(20) << std::left << stud[i].pavarde << std::setw(20) << std::left << stud[i].vardas << std::setw(30);
		fr << std::fixed << std::setprecision(2) << stud[i].vid << stud[i].med << std::endl;
	}
	fr << "vargsiukai:" << std::endl;
	for (unsigned int i = 0; i < less60.size(); i++)
	{
		fr << "			" << std::setw(20) << std::left << less60[i].pavarde << std::setw(20) << std::left << less60[i].vardas << std::setw(30);
		fr << std::fixed << std::setprecision(2) << less60[i].vid << less60[i].med << std::endl;
	}
}

void listveiksmai2(std::list<studentai>& stud1, unsigned short int nr, unsigned int nd)
{
	std::cout << "laikas naudojant listus: ";
	unsigned int m = 0;
	if (stud1.size() == 0) { throw std::domain_error("studentu vektorius tuscias"); }
	for (std::list<studentai>::iterator it = stud1.begin(); it != stud1.end(); ++it)
	{
		if ((*it).paz.size() == 0) { throw std::domain_error("nd pazymiu vektorius tuscias"); }
		int sum = 0;
		if (nr == 2) nd = (*it).paz.size() - 1;
		for (unsigned int j = 0; j < nd; j++)
		{
			sum = sum + (*it).paz.at(j);
		}
		(*it).vid = 0.4*(sum / nd) + 0.6*(*it).egz;
	}

	for (std::list<studentai>::iterator it = stud1.begin(); it != stud1.end(); ++it)
		std::sort((*it).paz.begin(), (*it).paz.end() - 1);

	for (std::list<studentai>::iterator it = stud1.begin(); it != stud1.end(); ++it)
	{
		if (nr == 2) nd = (*it).paz.size() - 1;
		if ((nd) % 2 != 0)
			(*it).med = 0.4*(*it).paz[nd / 2] + 0.6*(*it).egz;
		else
		{
			double med = ((*it).paz[nd / 2 - 1] + (*it).paz[nd / 2]) / 2;
			(*it).med = 0.4*med + 0.6*(*it).egz;
		}
	}
	//stud1.sort(acompare);
	std::list<studentai> less60;

	auto start = high_resolution_clock::now();

	std::remove_copy_if(stud1.begin(), stud1.end(), back_inserter(less60), daugiau);
	stud1.erase(remove_if(stud1.begin(), stud1.end(), maziau), stud1.end());

	auto end = high_resolution_clock::now();
	std::cout << duration<double>(end - start).count() << "s\n";

	std::ofstream fr("rezultatai.txt");
	fr << "			" << std::setw(20) << std::left << "Pavarde" << std::setw(20) << std::left << "Vardas" << std::setw(30) << "Galutinis-vidurkis" << "Galutinis-mediana" << std::endl;
	fr << "galvociai:" << std::endl;
	for (std::list<studentai>::iterator it = stud1.begin(); it != stud1.end(); ++it)
	{
		fr << "			" << std::setw(20) << std::left << (*it).pavarde << std::setw(20) << std::left << (*it).vardas << std::setw(30);
		fr << std::fixed << std::setprecision(2) << (*it).vid << (*it).med << std::endl;
	}
	fr << "vargsiukai:" << std::endl;
	for (std::list<studentai>::iterator it = less60.begin(); it != less60.end(); ++it)
	{
		fr << "			" << std::setw(20) << std::left << (*it).pavarde << std::setw(20) << std::left << (*it).vardas << std::setw(30);
		fr << std::fixed << std::setprecision(2) << (*it).vid << (*it).med << std::endl;
	}
}

void dequeveiksmai2(std::deque<studentai>& stud1, unsigned short int nr, unsigned int nd)
{
	std::cout << "laikas naudojant dekus: ";
	unsigned int m = 0;
	if (stud1.size() == 0) { throw std::domain_error("studentu vektorius tuscias"); }
	for (std::deque<studentai>::iterator it = stud1.begin(); it != stud1.end(); ++it)
	{
		if ((*it).paz.size() == 0) { throw std::domain_error("nd pazymiu vektorius tuscias"); }
		int sum = 0;
		if (nr == 2) nd = (*it).paz.size() - 1;
		for (unsigned int j = 0; j < nd; j++)
		{
			sum = sum + (*it).paz.at(j);
		}
		(*it).vid = 0.4*(sum / nd) + 0.6*(*it).egz;
	}

	for (std::deque<studentai>::iterator it = stud1.begin(); it != stud1.end(); ++it)
		std::sort((*it).paz.begin(), (*it).paz.end() - 1);

	for (std::deque<studentai>::iterator it = stud1.begin(); it != stud1.end(); ++it)
	{
		if (nr == 2) nd = (*it).paz.size() - 1;
		if ((nd) % 2 != 0)
			(*it).med = 0.4*(*it).paz[nd / 2] + 0.6*(*it).egz;
		else
		{
			double med = ((*it).paz[nd / 2 - 1] + (*it).paz[nd / 2]) / 2;
			(*it).med = 0.4*med + 0.6*(*it).egz;
		}
	}

	//std::sort(stud1.begin(), stud1.end(), acompare);
	std::deque<studentai> less60;

	auto start = high_resolution_clock::now();

	std::remove_copy_if(stud1.begin(), stud1.end(), back_inserter(less60), daugiau);
	stud1.erase(remove_if(stud1.begin(), stud1.end(), maziau), stud1.end());

	auto end = high_resolution_clock::now();
	std::cout << duration<double>(end - start).count() << "s\n";

	std::ofstream fr("rezultatai.txt");
	fr << "			" << std::setw(20) << std::left << "Pavarde" << std::setw(20) << std::left << "Vardas" << std::setw(30) << "Galutinis-vidurkis" << "Galutinis-mediana" << std::endl;
	fr << "galvociai:" << std::endl;
	for (std::deque<studentai>::iterator it = stud1.begin(); it != stud1.end(); ++it)
	{
		fr << "			" << std::setw(20) << std::left << (*it).pavarde << std::setw(20) << std::left << (*it).vardas << std::setw(30);
		fr << std::fixed << std::setprecision(2) << (*it).vid << (*it).med << std::endl;
	}
	fr << "vargsiukai:" << std::endl;
	for (std::deque<studentai>::iterator it = less60.begin(); it != less60.end(); ++it)
	{
		fr << "			" << std::setw(20) << std::left << (*it).pavarde << std::setw(20) << std::left << (*it).vardas << std::setw(30);
		fr << std::fixed << std::setprecision(2) << (*it).vid << (*it).med << std::endl;
	}
}

void failu_kurimas(int m)
{
	std::ofstream fk("kursiokai.txt");
	int n = 5;

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


// TODO: reference any additional headers you need in STDAFX.H
// and not in this file
