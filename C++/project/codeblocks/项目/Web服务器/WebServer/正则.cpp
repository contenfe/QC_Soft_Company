#include<iostream>
#include<string>
#include<regex>

using namespace std;


string strRes[]{
	"123123asdfas123",
	"asd12adfdjaf912af",
	"afsdf1xf1",
};


std::string s = "Some people, when confronted with a problem, think "
    "\"I know, I'll use regular expressions.\" "
    "Now they have two problems wer123.";


int main()
{
	smatch mat;
	regex pat(R"(\d+)");

	if (regex_match(strRes[0], mat, pat))
	{
		cout << "match:\n";
		cout << mat[0] << endl;
	}

	if (regex_match(strRes[0], pat))
	{
		cout << "match2:\n";
		cout << mat[0] << endl;
	}

	if (regex_search(strRes[1], mat, pat))
	{
		cout << "search:\n";
		cout << mat[0] << endl;
	}

	return 0;
}
