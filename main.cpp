#include <iostream>
#include <cassert>
#include "Member.hpp"
using namespace std;

Member avi, beni, chana;

void test1()
{
	Member dana;
	chana.follow(dana);
	dana.follow(avi);
	cout << "  " << chana.numFollowers() << " " <<  chana.numFollowing() << endl; // 0 1
	cout << "  " << avi.numFollowers() << " " <<  avi.numFollowing() << endl; // 1 0
	cout << "  " << Member::count() << endl; // 4
}

void test2()
{
	unsigned int before1 = avi.numFollowing();
	unsigned int before2 = avi.numFollowers();
	avi.follow(avi);
	unsigned int after1 = avi.numFollowing();
	unsigned int after2 = avi.numFollowers();
	
	cout<< " " << before1 << "=" << after1 << endl; // x=x 0=0
	cout<< " " << before2 << "=" << after2 << endl; // y=y 0=0
}

void test3()
{
	unsigned int before1 = avi.numFollowing();
	unsigned int before2 = avi.numFollowers();
	avi.unfollow(avi);
	unsigned int after1 = avi.numFollowing();
	unsigned int after2 = avi.numFollowers();
	
	cout<< " " << before1 << "=" << after1 << endl; // x=x 0=0
	cout<< " " << before2 << "=" << after2 << endl; // y=y 0=0
}

int test4()
{
	beni.follow(avi);
	assert(beni.numFollowers() == 1 && beni.numFollowing() == 1);
	beni.unfollow(avi);
	assert(beni.numFollowers() == 1 && beni.numFollowing() == 0);
}

int test5()
{
	Member kineret, dvir;
	kineret.unfollow(dvir);
	assert(dvir.numFollowers() == 0 && dvir.numFollowing() == 0);
	
}

int main() {
	cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 0
	avi.follow(beni);
	cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 1
	cout << beni.numFollowers() << " " << beni.numFollowing() << endl; // 1 0
	cout << Member::count() << endl; // 3
	cout << endl;
	
	test4();

	avi.follow(beni); // duplicate follow has no effect
	cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 1
	avi.unfollow(beni);	
	cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 0
	cout << endl;

	cout << chana.numFollowers() << " " <<  chana.numFollowing() << endl; // 0 0
	test1();
	cout << chana.numFollowers() << " " <<  chana.numFollowing() << endl; // 0 0
	cout << avi.numFollowers() << " " <<  avi.numFollowing() << endl; // 0 0
	cout << Member::count() << endl; // 3
	
	test2();
	test3();
	test5();
	

}