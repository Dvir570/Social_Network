#include <iostream>
#include "Member.h"
using namespace std;

Member avi, beni, chana;

void test1() {
	Member dana;
	chana.follow(dana);
	dana.follow(avi);
	cout << "  " << chana.numFollowers() << " " <<  chana.numFollowing() << endl; // 0 1
	cout << "  " << avi.numFollowers() << " " <<  avi.numFollowing() << endl; // 1 0
	cout << "  " << Member::count() << endl; // 4
}

void test2(){
	unsigned int before1 = avi.numFollowing();
	unsigned int before2 = avi.numFollowers();
	avi.follow(avi);
	unsigned int after1 = avi.numFollowing();
	unsigned int after2 = avi.numFollowers();
	
	cout<< " " << before1 << "=" << after1 << endl; // x=x
	cout<< " " << before2 << "=" << after2 << endl; // y=y
}

int main() {
	cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 0
	avi.follow(beni);
	cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 1
	cout << beni.numFollowers() << " " << beni.numFollowing() << endl; // 1 0
	cout << Member::count() << endl; // 3
	cout << endl;

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
}