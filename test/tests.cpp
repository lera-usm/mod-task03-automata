#include <gtest/gtest.h>
#include "Automata.h"

TEST(testing, on)
{
	vectotr<string> menu{ "capuchino","latte","mokko" };
	vector<int> ceny{ 25,20,30 };
	Automata A(menu, ceny);
	A.on();
	EXPECT_EQ(A.get_state(),states::wait);
}
TEST(testing, off)
{
	vectotr<string> menu{ "capuchino","latte","mokko" };
	vector<int> ceny{ 25,20,30 };
	Automata A(menu, ceny);
	A.on();
	A.off();
	EXPECT_EQ(A.get_state(),states::off);
}
TEST(testing, coin)
{
	vectotr<string> menu{ "capuchino","latte","mokko" };
	vector<int> ceny{ 25,20,30 };
	Automata A(menu, ceny);
	A.on();
	A.coin(5);
	EXPECT_EQ(A.get_state(),states::accept);
}
TEST(testing, get_menu)
{
	vectotr<string> menu{ "capuchino","latte","mokko" };
	vector<int> ceny{ 25,20,30 };
	Automata A(menu, ceny);
	A.on();
	EXPECT_EQ(A.get_menu(),menu);
}
TEST(testing, get_ceny)
{
	vectotr<string> menu{ "capuchino","latte","mokko" };
	vector<int> ceny{ 25,20,30 };
	Automata A(menu, ceny);
	A.on();
	EXPECT_EQ(A.get_ceny(),ceny);
}
TEST(testing, otmena)
{
	vectotr<string> menu{ "capuchino","latte","mokko" };
	vector<int> ceny{ 25,20,30 };
	Automata A(menu, ceny);
	A.on();
	A.coin(5);
	EXPECT_EQ(A.otmena(),5);
	EXPECT_EQ(A.get_state(),states::wait);
}
TEST(testing, vibor)
{
	vectotr<string> menu{ "capuchino","latte","mokko" };
	vector<int> ceny{ 25,20,30 };
	Automata A(menu, ceny);
	A.on();
	A.coin(5);
	EXPECT_EQ(A.vibor(0),false);
}
TEST(testing, cook)
{
	vectotr<string> menu{ "capuchino","latte","mokko" };
	vector<int> ceny{ 25,20,30 };
	Automata A(menu, ceny);
	A.on();
	A.coin(20);
	A.vibor(1);
	EXPECT_EQ(A.get_state(),states::cook);
}
