
#include "file_dict.h"
//#include "mas_dict.h"
#include "Letter.h"
#include "Pole.h"
#include "Word.h"
#include "Bank.h"

#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>
#include <iostream>
#include <fstream>
#include <string>  




using namespace Microsoft::VisualStudio::CppUnitTestFramework;
//using namespace std;
namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Letter a('и');
			char ii = 'и';
			char a_ret_v = a.return_value();
			int a_ret_w = a.return_weight();
			int a_ret_n = a.return_nums();

			Assert::AreEqual(a_ret_v, ii);
			Assert::AreEqual(a_ret_w, 1);
			Assert::AreEqual(a_ret_n, 6);

			bool a_ret_l = a.return_locked();
			Assert::AreEqual(a_ret_l, true);
			a.change_locked(false);
			a_ret_l = a.return_locked();
			Assert::AreEqual(a_ret_l, false);


			a.delete_one_letter();
			a_ret_n = a.return_nums();
			Assert::AreEqual(a_ret_n, 5);

			a.delete_one_letter();
			a.delete_one_letter();
			a.delete_one_letter();
			a.delete_one_letter();
			a.delete_one_letter();
			a_ret_n = a.return_nums();
			Assert::AreEqual(a_ret_n, 0);

			a_ret_n = a.return_nums();
			Assert::AreEqual(a_ret_n, 0);


			Letter b;

			char b_ret_v = b.return_value();
			int b_ret_w = b.return_weight();
			int b_ret_n = b.return_nums();

			Assert::AreEqual(b_ret_v, (char) - 1);
			Assert::AreEqual(b_ret_w, -1);
			Assert::AreEqual(b_ret_n, -1);


			Letter c('s', 3, 5);

			char c_ret_v = c.return_value();
			int c_ret_w = c.return_weight();
			int c_ret_n = c.return_nums();

			Assert::AreEqual(c_ret_v, 's');
			Assert::AreEqual(c_ret_w, 3);
			Assert::AreEqual(c_ret_n, 5);


		};
		TEST_METHOD(TestMethod2)
		{
			Pole P("лавелас");
			string s = P.return_pole_word(0, 7);
			string s_com = "zzzzлавеласzzzz";
			Assert::AreEqual(s, s_com);

			string sg = "лисолось";
			P.write_word(sg, 3, 8, 7, 4);
			s = P.return_pole_word(1, 4);
			s_com = "zzzzzzzлzzzzzzz";
			Assert::AreEqual(s, s_com);


			P.write_word(sg, 1, 8, 7, 4);
			s = P.return_pole_word(1, 4);
			Assert::AreEqual(s, s_com);

			P.write_word(sg, 1, 8, -1, 16);
			s = P.return_pole_word(1, 4);
			Assert::AreEqual(s, s_com);


			sg = "лось";
			P.write_word(sg, 1, 4, 7, 4);
			s = P.return_pole_word(1, 4);
			s_com = "zzzzzzzлосьzzzz";
			Assert::AreEqual(s, s_com);


			char letter_p = P.return_letter_from(7, 4);
			char letter_com = 'л';
			Assert::AreEqual(letter_p, letter_com);

			letter_p = P.return_letter_from(-1, 4);
			Assert::AreEqual(letter_p, (char)-1);



		};
		TEST_METHOD(TestMethod3)
		{
			Pole P("лавелас");
			string sg = "лось";
			Letter l[7];
			string bank = "омтсьда";
			for (int i = 0; i < 7; i++) {
				Letter a(bank[i]);
				l[i] = a;
			}

			Word word1(sg, 4, 8, 5, 1, P, l);
			int result = word1.check_alphs();
			Assert::AreEqual(result, 1);

			result = word1.pirog();
			Assert::AreEqual(result, 1);

			result = word1.get_weight();
			Assert::AreEqual(result, 14); // word's first weight * 2

			Word word3(sg, 4, 7, 5, 1, P, l);
			result = word3.pirog();
			Assert::AreEqual(result, 0);

			Letter a('к');
			l[0] = a;
			Word word2(sg, 4, 8, 5, 1, P, l);
			result = word2.check_alphs();
			Assert::AreEqual(result, -1);
		};
		TEST_METHOD(TestMethod4)
		{
			file_dict ff;
			string word = "авлос";
			Letter l[5];
			for (int i = 0; i < 5; i++) {
				Letter a(word[i]);
				l[i] = a;
			}
			bool b = ff.search_word(l, 5);
			Assert::AreEqual(b,true);

			string word2 = ff.find_first_world(40);
			string word2_comp = "агевзия";
			Assert::AreEqual(word2_comp, word2);

			string word3 = "абажуродержатель";
			Letter l3[16];
			for (int i = 0; i < 16; i++) {
				Letter a(word3[i]);
				l3[i] = a;
			}
			b = ff.search_word(l3, 16);
			Assert::AreEqual(b, false);

			string word4 = "абандол";
			Letter l4[7];
			for (int i = 0; i < 7; i++) {
				Letter a(word4[i]);
				l4[i] = a;
			}
			b = ff.search_word(l4, 7);
			Assert::AreEqual(b, false);


			


			
		}
	};
}
