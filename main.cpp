#include <iostream>
#include <cassert>
#include "Member.h"
using namespace std;

Member avi, beni, chana;

void test0(){
	assert(avi.numFollowers() == 0 && avi.numFollowing() == 0);
	avi.follow(beni);
	assert(avi.numFollowers() == 0 && avi.numFollowing() == 1);
	assert(beni.numFollowers() == 1 && beni.numFollowing() == 0);
	assert(Member::count() == 3);
}

void test1()
{
	beni.follow(avi);
	assert(beni.numFollowers() == 1 && beni.numFollowing() == 1);
	beni.unfollow(avi);
	assert(beni.numFollowers() == 1 && beni.numFollowing() == 0);
}

/* duplicate follow has no effect */
void test2(){
	avi.follow(beni); 
	assert(avi.numFollowers() == 0 && avi.numFollowing() == 1);
	avi.unfollow(beni);	
	assert(avi.numFollowers() == 0 && avi.numFollowing() == 0);
}

void test3()
{
	Member dana;
	assert(chana.numFollowers() == 0 && chana.numFollowing() == 0);
	chana.follow(dana);
	dana.follow(avi);
	assert(chana.numFollowers() == 0 && chana.numFollowing() == 1);
	assert(avi.numFollowers() == 1 && avi.numFollowing() == 0);
	assert(Member::count() == 4);
}

/* check if distructor works */
void test4()
{
	assert(chana.numFollowers() == 0 && chana.numFollowing() == 0);
	assert(avi.numFollowers() == 0 && avi.numFollowing() == 0);
	assert(Member::count() == 3);

}

void test5()
{
	unsigned int before1 = avi.numFollowing();
	unsigned int before2 = avi.numFollowers();
	avi.follow(avi);
	unsigned int after1 = avi.numFollowing();
	unsigned int after2 = avi.numFollowers();
	
	//check if there are no changes
	assert(before1 == after1);
	assert(before2 == after2);
}

void test6()
{
	unsigned int before1 = avi.numFollowing();
	unsigned int before2 = avi.numFollowers();
	avi.unfollow(avi);
	unsigned int after1 = avi.numFollowing();
	unsigned int after2 = avi.numFollowers();
	
	//check if there are no changes
	assert(before1 == after1);
	assert(before2 == after2);
}

void test7()
{
	Member kineret, dvir;
	kineret.unfollow(dvir);
	assert(dvir.numFollowers() == 0 && dvir.numFollowing() == 0);
	
}

int main() {

	test0();
	test1();
	test2();
	test3(); 
	test4();
	test5();
	test6();
	test7();

	return 0;
}